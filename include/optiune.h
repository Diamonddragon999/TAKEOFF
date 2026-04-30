#ifndef OOP_OPTIUNE_H
#define OOP_OPTIUNE_H

#include <string>

class GameState;

class Optiune {
public:
    std::string text;
    int delta;

    Optiune(std::string t, int d);
    void aplica(GameState& state) const;
};

#endif
