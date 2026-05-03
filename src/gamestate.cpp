#include "gamestate.h"
#include "exceptions.h"
#include "narrowai.h"

#include <utility>

GameState::GameState()
    : tura{1}, bani{1000}, capabilitate{50}, aliniere{80},
      model{std::make_shared<NarrowAI>()} {}

GameState::GameState(int t, int b, int cap, int alin)
    : tura{t}, bani{b}, capabilitate{cap}, aliniere{alin},
      model{std::make_shared<NarrowAI>()} {}

// cppcheck-suppress unusedFunction
int GameState::getTura() const { return tura; }

// cppcheck-suppress unusedFunction
int GameState::getBani() const { return bani; }

// cppcheck-suppress unusedFunction
int GameState::getCapabilitate() const { return capabilitate; }

// cppcheck-suppress unusedFunction
int GameState::getAliniere() const { return aliniere; }

// cppcheck-suppress unusedFunction
const AIModel& GameState::getModel() const { return *model; }

// cppcheck-suppress unusedFunction
void GameState::avanseaza() {
    tura++;
    notifica();
}

// cppcheck-suppress unusedFunction
void GameState::cheltuieste(int cost) {
    if (cost > bani) throw BugetInsuficient(bani, cost);
    bani -= cost;
    notifica();
}

// cppcheck-suppress unusedFunction
void GameState::incaseaza(int suma) {
    bani += suma;
    notifica();
}

// cppcheck-suppress unusedFunction
void GameState::schimbaCapabilitate(int delta) {
    capabilitate += delta;
    if (capabilitate < 0) capabilitate = 0;
    notifica();
}

// cppcheck-suppress unusedFunction
void GameState::schimbaAliniere(int delta) {
    aliniere += delta;
    if (aliniere < 0) aliniere = 0;
    if (aliniere > 100) aliniere = 100;
    notifica();
}

// cppcheck-suppress unusedFunction
void GameState::atasaObserver(std::shared_ptr<GameStateObserver> obs) {
    observatori.push_back(std::move(obs));
}

void GameState::notifica() const {
    for (const auto& obs : observatori) {
        obs->schimbat(*this);
    }
}
