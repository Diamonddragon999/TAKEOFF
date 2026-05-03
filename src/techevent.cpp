#include "techevent.h"

#include <utility>

TechEvent::TechEvent(std::string descriere, std::vector<Optiune> o)
    : GameEvent{std::move(descriere)}, opts{std::move(o)} {}

TechEvent::TechEvent(const TechEvent& other)
    : GameEvent{other}, opts{other.opts} {}

// cppcheck-suppress unusedFunction
TechEvent& TechEvent::operator=(const TechEvent& other) {
    if (this == &other) return *this;
    GameEvent::operator=(other);
    opts = other.opts;
    return *this;
}

// cppcheck-suppress unusedFunction
std::string TechEvent::eticheta() const {
    return "[tech]";
}

// cppcheck-suppress unusedFunction
const std::vector<Optiune>& TechEvent::optiuni() const {
    return opts;
}
