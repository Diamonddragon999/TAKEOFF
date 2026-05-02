#include "logobserver.h"
#include "gamestate.h"

#include <iostream>

// cppcheck-suppress unusedFunction
void LogObserver::schimbat(GameState& s) {
    std::cout << "[log] tura " << s.getTura()
              << " bani " << s.getBani()
              << " cap " << s.getCapabilitate()
              << " alin " << s.getAliniere() << "\n";
}
