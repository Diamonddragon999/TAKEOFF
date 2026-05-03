#include "crisisevent.h"

#include <utility>

CrisisEvent::CrisisEvent(std::string descriere, std::vector<Optiune> o)
    : GameEvent{std::move(descriere)}, opts{std::move(o)} {}

CrisisEvent::CrisisEvent(const CrisisEvent& other)
    : GameEvent{other}, opts{other.opts} {}

// cppcheck-suppress unusedFunction
CrisisEvent& CrisisEvent::operator=(const CrisisEvent& other) {
    if (this == &other) return *this;
    GameEvent::operator=(other);
    opts = other.opts;
    return *this;
}

// cppcheck-suppress unusedFunction
std::string CrisisEvent::eticheta() const {
    return "[criza]";
}

// cppcheck-suppress unusedFunction
const std::vector<Optiune>& CrisisEvent::optiuni() const {
    return opts;
}
