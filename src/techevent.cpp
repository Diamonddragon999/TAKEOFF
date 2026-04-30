#include "techevent.h"
#include "gamestate.h"

#include <utility>

TechEvent::TechEvent(std::vector<Optiune> opts) : optiuni{std::move(opts)} {}

std::string TechEvent::descriere() const {
    return "lansare model nou";
}

void TechEvent::aplica(GameState& state) const {
    if (!optiuni.empty()) optiuni[0].aplica(state);
}
