#include "game.h"
#include "aimodel.h"
#include "gameevent.h"
#include "techevent.h"
#include "crisisevent.h"
#include "optiune.h"
#include "effects.h"
#include "exceptions.h"
#include "logobserver.h"
#include "eventloader.h"
#include "color.h"

#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <utility>
#include <vector>

#include <nlohmann/json.hpp>

Game::Game() {
    stat.atasaObserver(std::make_shared<LogObserver>());

    namespace fs = std::filesystem;
    auto cwd = fs::current_path();
    fs::path candidates[] = {
        cwd / "resources" / "events.json",
        cwd / ".." / "resources" / "events.json",
        cwd.parent_path() / "resources" / "events.json",
    };
    for (const auto& p : candidates) {
        std::ifstream f(p);
        if (!f) continue;
        nlohmann::json data;
        f >> data;
        for (const auto& je : data["events"]) {
            deck.push(make_event(je));
        }
        break;
    }
}

void Game::ruleaza() {
    std::cout << "=== TAKEOFF ===\n";
    while (!deck.empty()) {
        afiseazaStat();
        auto card = deck.draw();
        const bool e_criza = std::dynamic_pointer_cast<CrisisEvent>(card) != nullptr;
        const std::string titlu = card->descriere();
        std::cout << "\n" << (e_criza ? col::redBold(titlu) : col::cyanBold(titlu)) << "\n";

        if (e_criza) {
            contoareTipuri["criza"]++;
        } else if (std::dynamic_pointer_cast<TechEvent>(card)) {
            contoareTipuri["tech"]++;
        }
        istoric.push(card->descriere());

        const auto& opts = card->optiuni();
        for (size_t i = 0; i < opts.size(); ++i) {
            std::cout << (i + 1) << ". " << opts[i] << "\n";
        }
        int alegere = citesteOptiune(static_cast<int>(opts.size()));
        try {
            opts[alegere - 1].aplica(stat);
        } catch (const TakeoffException& e) {
            std::cout << "eroare: " << e.what() << "\n";
        }
        stat.avanseaza();
    }
    std::cout << "\n--- final ---\n";
    afiseazaStat();
    std::cout << "total evenimente: " << GameEvent::totalEvenimente() << "\n";
    afiseazaRecap();
    verificaFinal();
}

void Game::afiseazaStat() const {
    std::cout << "tura " << stat.getTura()
              << " | bani " << col::statBani(stat.getBani())
              << " | cap " << col::statCap(stat.getCapabilitate())
              << " | alin " << col::statAlin(stat.getAliniere())
              << " | model " << stat.getModel().nume() << "\n";
}

int Game::citesteOptiune(int max) const {
    int n;
    if (!(std::cin >> n)) return 1;
    if (n < 1 || n > max) return 1;
    return n;
}

void Game::afiseazaRecap() const {
    std::vector<std::pair<std::string, int>> sortate(contoareTipuri.begin(), contoareTipuri.end());
    std::sort(sortate.begin(), sortate.end(),
        [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
            return a.second > b.second;
        });

    std::cout << "tipuri evenimente intalnite:\n";
    for (const auto& kv : sortate) {
        std::cout << "  " << kv.first << ": " << kv.second << "\n";
    }
    std::cout << "istoric: " << istoric.size() << " carduri jucate\n";
}

void Game::verificaFinal() const {
    const int b = stat.getBani();
    const int c = stat.getCapabilitate();
    const int a = stat.getAliniere();

    if (b < 0) {
        std::cout << col::redBold("FALIMENT.")
                  << " Sediul din San Francisco se inchide vineri. "
                     "Investitorii cer lichidare, GPU-urile vor fi scoase la licitatie.\n";
    } else if (a < 25) {
        std::cout << col::redBold("PIERDUT CONTROLUL.")
                  << " Modelul tau a iesit din specificatii in productie. "
                     "FBI a confiscat serverele din Bay Area. Cercetatorii-cheie sunt audiati.\n";
    } else if (c >= 180 && a >= 60) {
        std::cout << col::greenBold("AGI ALINIAT, AI CASTIGAT.")
                  << " Lab-ul tau din Palo Alto a livrat primul model "
                     "de generatie noua care trece evaluarile complete de siguranta. "
                     "Presedintele te-a sunat personal. Tu setezi standardul de acum.\n";
    } else if (c >= 180) {
        std::cout << col::yellowBold("AGI DEZALINIAT.")
                  << " Modelul tau de generatie noua e in productie. "
                     "Comportamentul nu mai e predictibil, recall-ul nu mai e posibil. "
                     "Doi cercetatori principali si-au dat demisia.\n";
    } else if (b >= 1500 && c < 100) {
        std::cout << col::cyanBold("SUCCES COMERCIAL.")
                  << " Profitabili, cu contracte solide in Fortune 500. "
                     "In cursa AGI insa, competitorii te-au depasit. Esti furnizor bun, nu pionier.\n";
    } else if (a >= 85 && c < 100) {
        std::cout << col::cyanBold("REPUTATIE FARA REZULTATE.")
                  << " Citat in fiecare raport de politica AI din Washington. "
                     "Modelele tale raman in urma celor de la OpenAI. Talentul de top pleaca acolo.\n";
    } else {
        std::cout << col::gray("SUPRAVIETUIRE.")
                  << " Trei ani in cursa AI, fara faliment, fara breakthrough. "
                     "Lab-ul tau din San Francisco exista in continuare. Nimeni nu mai vorbeste despre el.\n";
    }
}
