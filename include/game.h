#ifndef OOP_GAME_H
#define OOP_GAME_H

#include <memory>

#include "gamestate.h"
#include "gameevent.h"
#include "eventdeck.h"

class Game {
public:
    Game();
    void ruleaza();

private:
    GameState stat;
    EventDeck<std::shared_ptr<GameEvent>> deck;

    void afiseazaStat() const;
    int citesteOptiune(int max) const;
    void verificaFinal() const;
};

#endif
