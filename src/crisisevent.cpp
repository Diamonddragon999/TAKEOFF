#include "crisisevent.h"
#include "gamestate.h"

std::string CrisisEvent::descriere() const {
    return "criza pe piata";
}

void CrisisEvent::aplica(GameState& state) const {
    state.bani -= 200;
}
