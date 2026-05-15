#include <iostream>

#include "env_fixes.h"
#include "game.h"

int main() {
    init_threads();
    Game game;
    game.ruleaza();
    return 0;
}
