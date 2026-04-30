#include "techevent.h"
#include "gamestate.h"

std::string TechEvent::descriere() const {
    return "lansare model nou";
}

void TechEvent::aplica(GameState& state) const {
    state.bani += 500;
}
