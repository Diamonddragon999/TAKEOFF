#include "game.h"
#include "aimodel.h"
#include "techevent.h"
#include "crisisevent.h"
#include "optiune.h"
#include "effects.h"
#include "exceptions.h"
#include "logobserver.h"
#include "eventloader.h"

#include <filesystem>
#include <fstream>
#include <iostream>
#include <vector>

#include <nlohmann/json.hpp>

Game::Game() {
    stat.atasaObserver(std::make_shared<LogObserver>());

    auto path = std::filesystem::current_path().parent_path() / "resources" / "events.json";
    std::ifstream f(path);
    if (f) {
        nlohmann::json data;
        f >> data;
        for (const auto& je : data["events"]) {
            deck.push(make_event(je));
        }
    }
}

void Game::ruleaza() {
    std::cout << "=== TAKEOFF ===\n";
    while (!deck.empty()) {
        afiseazaStat();
        auto card = deck.draw();
        std::cout << "\n" << card->descriere() << "\n";
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
    verificaFinal();
}

void Game::afiseazaStat() const {
    std::cout << "tura " << stat.getTura()
              << " | bani " << stat.getBani()
              << " | cap " << stat.getCapabilitate()
              << " | alin " << stat.getAliniere()
              << " | model " << stat.getModel().nume() << "\n";
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
