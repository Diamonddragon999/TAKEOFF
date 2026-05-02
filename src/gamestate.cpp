#include "gamestate.h"
#include "exceptions.h"

// cppcheck-suppress unusedFunction
void GameState::avanseaza() {
    tura++;
}

// cppcheck-suppress unusedFunction
void GameState::cheltuieste(int cost) {
    if (cost > bani) throw BugetInsuficient(bani, cost);
    bani -= cost;
}
