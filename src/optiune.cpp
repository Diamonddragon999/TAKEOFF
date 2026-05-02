#include "optiune.h"
#include "gamestate.h"

#include <utility>

Optiune::Optiune(std::string t, std::shared_ptr<DecisionEffect> e)
    : text{std::move(t)}, effect{std::move(e)} {}

// cppcheck-suppress unusedFunction
void Optiune::aplica(GameState& s) const {
    if (effect) effect->aplica(s);
}
