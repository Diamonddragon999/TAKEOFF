#include "optiune.h"
#include "gamestate.h"

#include <utility>

Optiune::Optiune(std::string t, int d) : text{std::move(t)}, delta{d} {}

// cppcheck-suppress unusedFunction
void Optiune::aplica(GameState& state) const {
    state.bani += delta;
}
