#include "gamestate.h"
#include "exceptions.h"

void GameState::avanseaza() {
    tura++;
}

void GameState::cheltuieste(int cost) {
    if (cost > bani) throw BugetInsuficient(cost);
    bani -= cost;
}
