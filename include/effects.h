#ifndef OOP_EFFECTS_H
#define OOP_EFFECTS_H

#include "decisioneffect.h"

class SchimbBani : public DecisionEffect {
public:
    explicit SchimbBani(int delta);
    void aplica(GameState& s) const override;
    std::string descriere() const override;
private:
    int delta;
};

class SchimbCapabilitate : public DecisionEffect {
public:
    explicit SchimbCapabilitate(int delta);
    void aplica(GameState& s) const override;
    std::string descriere() const override;
private:
    int delta;
};

class SchimbAliniere : public DecisionEffect {
public:
    explicit SchimbAliniere(int delta);
    void aplica(GameState& s) const override;
    std::string descriere() const override;
private:
    int delta;
};

#endif
