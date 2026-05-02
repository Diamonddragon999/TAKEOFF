#ifndef OOP_OBSERVER_H
#define OOP_OBSERVER_H

class GameState;

class GameStateObserver {
public:
    virtual ~GameStateObserver() = default;
    virtual void schimbat(const GameState& s) = 0;
};

#endif
