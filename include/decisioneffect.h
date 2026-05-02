#ifndef OOP_DECISIONEFFECT_H
#define OOP_DECISIONEFFECT_H

#include <string>

class GameState;

class DecisionEffect {
public:
    virtual ~DecisionEffect() = default;
    virtual void aplica(GameState& s) const = 0;
    virtual std::string descriere() const = 0;
};

#endif
