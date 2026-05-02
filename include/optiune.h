#ifndef OOP_OPTIUNE_H
#define OOP_OPTIUNE_H

#include <memory>
#include <string>

#include "decisioneffect.h"

class GameState;

class Optiune {
public:
    std::string text;
    std::shared_ptr<DecisionEffect> effect;

    Optiune(std::string t, std::shared_ptr<DecisionEffect> e);
    void aplica(GameState& s) const;
};

#endif
