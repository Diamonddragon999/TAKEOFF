#ifndef OOP_OPTIUNE_H
#define OOP_OPTIUNE_H

#include <iosfwd>
#include <memory>
#include <string>

#include "decisioneffect.h"

class GameState;

class Optiune {
public:
    Optiune();
    Optiune(std::string text, std::shared_ptr<DecisionEffect> effect);
    explicit Optiune(std::string text);

    Optiune(const Optiune& other);
    Optiune(Optiune&& other) noexcept;
    Optiune& operator=(const Optiune& other);
    Optiune& operator=(Optiune&& other) noexcept;
    ~Optiune();

    Optiune& operator+=(int amplifier);

    void aplica(GameState& s) const;
    const std::string& getText() const;

    friend std::ostream& operator<<(std::ostream& os, const Optiune& o);
    friend std::istream& operator>>(std::istream& is, Optiune& o);

private:
    std::string text;
    std::shared_ptr<DecisionEffect> effect;
};

bool operator==(const Optiune& a, const Optiune& b);

#endif
