#ifndef OOP_GAME_H
#define OOP_GAME_H

#include <map>
#include <memory>
#include <string>

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
    EventDeck<std::string> istoric;
    std::map<std::string, int> contoareTipuri;

    void afiseazaStat() const;
    int citesteOptiune(int max) const;
    void verificaFinal() const;
    void afiseazaRecap() const;
};

#endif
