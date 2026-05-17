#include <iostream>

#include "env_fixes.h"
#include "game.h"

#ifdef _WIN32
#include <windows.h>
static void enable_vt_mode() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD mode = 0;
    if (h != INVALID_HANDLE_VALUE && GetConsoleMode(h, &mode)) {
        SetConsoleMode(h, mode | 0x0004);
    }
}
#else
static void enable_vt_mode() {}
#endif

int main() {
    init_threads();
    enable_vt_mode();
    Game game;
    game.ruleaza();
    return 0;
}
