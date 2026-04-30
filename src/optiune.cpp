#include "optiune.h"
#include "gamestate.h"

#include <utility>

Optiune::Optiune(std::string t, int d) : text{std::move(t)}, delta{d} {}

void Optiune::aplica(GameState& state) const {
    state.bani += delta;
}
