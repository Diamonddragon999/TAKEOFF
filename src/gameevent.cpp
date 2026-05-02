#include "gameevent.h"

#include <utility>

GameEvent::GameEvent(std::string d) : desc{std::move(d)} {}

// cppcheck-suppress unusedFunction
std::string GameEvent::descriere() const {
    return eticheta() + " " + desc;
}
