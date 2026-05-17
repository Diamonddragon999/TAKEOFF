#include "schimbcompozit.h"

#include <utility>

SchimbCompozit::SchimbCompozit(std::shared_ptr<DecisionEffect> p,
                               std::shared_ptr<DecisionEffect> s)
    : primar{std::move(p)}, secundar{std::move(s)} {}

// cppcheck-suppress unusedFunction
void SchimbCompozit::aplica(GameState& s) const {
    if (primar) primar->aplica(s);
    if (secundar) secundar->aplica(s);
}

// cppcheck-suppress unusedFunction
std::string SchimbCompozit::descriere() const {
    std::string rez;
    if (primar) rez += primar->descriere();
    if (secundar) rez += ", " + secundar->descriere();
    return rez;
}
