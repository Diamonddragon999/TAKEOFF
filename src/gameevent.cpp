#include "gameevent.h"

#include <utility>

GameEvent::GameEvent(std::string d) : desc{std::move(d)} {
    ++contor;
}

// cppcheck-suppress unusedFunction
std::string GameEvent::descriere() const {
    return eticheta() + " " + desc;
}

// cppcheck-suppress unusedFunction
int GameEvent::totalEvenimente() {
    return contor;
}
