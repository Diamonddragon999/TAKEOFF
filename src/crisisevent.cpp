#include "crisisevent.h"

#include <utility>

CrisisEvent::CrisisEvent(std::string descriere, std::vector<Optiune> o)
    : GameEvent{std::move(descriere)}, opts{std::move(o)} {}

// cppcheck-suppress unusedFunction
std::string CrisisEvent::eticheta() const {
    return "[criza]";
}

// cppcheck-suppress unusedFunction
const std::vector<Optiune>& CrisisEvent::optiuni() const {
    return opts;
}
