#include "optiune.h"
#include "gamestate.h"

#include <iostream>
#include <utility>

Optiune::Optiune() : text{}, effect{} {}

Optiune::Optiune(std::string t, std::shared_ptr<DecisionEffect> e)
    : text{std::move(t)}, effect{std::move(e)} {}

Optiune::Optiune(std::string t) : text{std::move(t)}, effect{} {}

Optiune::Optiune(const Optiune& o) : text{o.text}, effect{o.effect} {}

Optiune::Optiune(Optiune&& o) noexcept : text{std::move(o.text)}, effect{std::move(o.effect)} {}

Optiune& Optiune::operator=(const Optiune& o) {
    if (this == &o) return *this;
    text = o.text;
    effect = o.effect;
    return *this;
}

Optiune& Optiune::operator=(Optiune&& o) noexcept {
    if (this == &o) return *this;
    text = std::move(o.text);
    effect = std::move(o.effect);
    return *this;
}

Optiune::~Optiune() = default;

// cppcheck-suppress unusedFunction
Optiune& Optiune::operator+=(int amp) {
    text += " (x" + std::to_string(amp) + ")";
    return *this;
}

// cppcheck-suppress unusedFunction
void Optiune::aplica(GameState& s) const {
    if (effect) effect->aplica(s);
}

// cppcheck-suppress unusedFunction
const std::string& Optiune::getText() const {
    return text;
}

// cppcheck-suppress unusedFunction
std::ostream& operator<<(std::ostream& os, const Optiune& o) {
    os << o.text;
    if (o.effect) os << " [" << o.effect->descriere() << "]";
    return os;
}

// cppcheck-suppress unusedFunction
std::istream& operator>>(std::istream& is, Optiune& o) {
    std::getline(is, o.text);
    return is;
}

// cppcheck-suppress unusedFunction
bool operator==(const Optiune& a, const Optiune& b) {
    return a.getText() == b.getText();
}
