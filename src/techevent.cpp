#include "techevent.h"

#include <utility>

TechEvent::TechEvent(std::string descriere, std::vector<Optiune> o)
    : GameEvent{std::move(descriere)}, opts{std::move(o)} {}

// cppcheck-suppress unusedFunction
std::string TechEvent::eticheta() const {
    return "[tech]";
}

// cppcheck-suppress unusedFunction
const std::vector<Optiune>& TechEvent::optiuni() const {
    return opts;
}
