#ifndef OOP_SCHIMBCOMPOZIT_H
#define OOP_SCHIMBCOMPOZIT_H

#include <memory>

#include "decisioneffect.h"

class SchimbCompozit : public DecisionEffect {
public:
    SchimbCompozit(std::shared_ptr<DecisionEffect> primar,
                   std::shared_ptr<DecisionEffect> secundar);
    void aplica(GameState& s) const override;
    std::string descriere() const override;
private:
    std::shared_ptr<DecisionEffect> primar;
    std::shared_ptr<DecisionEffect> secundar;
};

#endif
