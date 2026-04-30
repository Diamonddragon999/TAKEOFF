#ifndef OOP_GAMEEVENT_H
#define OOP_GAMEEVENT_H

#include <string>

class GameState;

class GameEvent {
public:
    virtual ~GameEvent() = default;
    virtual std::string descriere() const = 0;
    virtual void aplica(GameState& state) const = 0;
};

#endif
