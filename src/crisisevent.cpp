#include "crisisevent.h"
#include "gamestate.h"

// cppcheck-suppress unusedFunction
std::string CrisisEvent::descriere() const {
    return "criza pe piata";
}

// cppcheck-suppress unusedFunction
void CrisisEvent::aplica(GameState& state) const {
    state.incaseaza(-200);
}
