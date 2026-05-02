#include "game.h"
#include "techevent.h"
#include "crisisevent.h"
#include "optiune.h"
#include "effects.h"
#include "exceptions.h"
#include "logobserver.h"

#include <iostream>
#include <vector>

Game::Game() {
    stat.atasaObserver(std::make_shared<LogObserver>());
    deck.push(std::make_shared<TechEvent>(
        "lansare model nou",
        std::vector<Optiune>{
            Optiune{"investeste in safety", std::make_shared<SchimbAliniere>(15)},
            Optiune{"lanseaza public, capabilitate +20", std::make_shared<SchimbCapabilitate>(20)}
        }
    ));
    deck.push(std::make_shared<CrisisEvent>(
        "criza pe piata",
        std::vector<Optiune>{
            Optiune{"reduceti pierderea", std::make_shared<SchimbBani>(-100)},
            Optiune{"inghet activitati", std::make_shared<SchimbCapabilitate>(-10)}
        }
    ));
    deck.push(std::make_shared<TechEvent>(
        "contract pentagon",
        std::vector<Optiune>{
            Optiune{"semneaza, +1000 dar -10 aliniere", std::make_shared<SchimbBani>(1000)},
            Optiune{"refuza, +200 dar +10 aliniere", std::make_shared<SchimbAliniere>(10)}
        }
    ));
}

void Game::ruleaza() {
    std::cout << "=== TAKEOFF ===\n";
    while (!deck.empty()) {
        afiseazaStat();
        auto card = deck.draw();
        std::cout << "\n" << card->descriere() << "\n";
        const auto& opts = card->optiuni();
        for (size_t i = 0; i < opts.size(); ++i) {
            std::cout << (i + 1) << ". " << opts[i].text << "\n";
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
    verificaFinal();
}

void Game::afiseazaStat() const {
    std::cout << "tura " << stat.getTura()
              << " | bani " << stat.getBani()
              << " | cap " << stat.getCapabilitate()
              << " | alin " << stat.getAliniere() << "\n";
}

int Game::citesteOptiune(int max) const {
    int n;
    if (!(std::cin >> n)) return 1;
    if (n < 1 || n > max) return 1;
    return n;
}

void Game::verificaFinal() const {
    if (stat.getBani() <= 0) {
        std::cout << "ai dat faliment\n";
    } else if (stat.getAliniere() < 30) {
        std::cout << "modelul a scapat de sub control\n";
    } else if (stat.getCapabilitate() >= 200) {
        std::cout << "ai atins ASI, ai castigat\n";
    } else {
        std::cout << "ai supravietuit\n";
    }
}
