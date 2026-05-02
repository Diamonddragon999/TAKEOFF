#include "effects.h"
#include "gamestate.h"

#include <string>

SchimbBani::SchimbBani(int d) : delta{d} {}

// cppcheck-suppress unusedFunction
void SchimbBani::aplica(GameState& s) const {
    s.incaseaza(delta);
}

// cppcheck-suppress unusedFunction
std::string SchimbBani::descriere() const {
    return "bani " + std::to_string(delta);
}

SchimbCapabilitate::SchimbCapabilitate(int d) : delta{d} {}

// cppcheck-suppress unusedFunction
void SchimbCapabilitate::aplica(GameState& s) const {
    s.schimbaCapabilitate(delta);
}

// cppcheck-suppress unusedFunction
std::string SchimbCapabilitate::descriere() const {
    return "capabilitate " + std::to_string(delta);
}

SchimbAliniere::SchimbAliniere(int d) : delta{d} {}

// cppcheck-suppress unusedFunction
void SchimbAliniere::aplica(GameState& s) const {
    s.schimbaAliniere(delta);
}

// cppcheck-suppress unusedFunction
std::string SchimbAliniere::descriere() const {
    return "aliniere " + std::to_string(delta);
}
