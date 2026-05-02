#include "game.h"
#include "techevent.h"
#include "crisisevent.h"
#include "optiune.h"
#include "exceptions.h"

#include <iostream>
#include <vector>

Game::Game() {
    deck.push(std::make_shared<TechEvent>(std::vector<Optiune>{
        Optiune{"investeste in safety", -100},
        Optiune{"lanseaza modelul", 500}
    }));
    deck.push(std::make_shared<CrisisEvent>());
    deck.push(std::make_shared<TechEvent>(std::vector<Optiune>{
        Optiune{"contract pentagon", 1000},
        Optiune{"refuza contractul", 200}
    }));
}

void Game::ruleaza() {
    std::cout << "=== TAKEOFF ===\n";
    while (!deck.empty()) {
        afiseazaStat();
        auto card = deck.draw();
        std::cout << "\n" << card->descriere() << "\n";
        std::cout << "1. continua\n";
        std::cout << "2. skip\n";
        int alegere = citesteOptiune(2);
        if (alegere == 1) {
            try {
                card->aplica(stat);
            } catch (const TakeoffException& e) {
                std::cout << "eroare: " << e.what() << "\n";
            }
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
    } else {
        std::cout << "ai supravietuit\n";
    }
}
