#ifndef OOP_GAME_H
#define OOP_GAME_H

#include <map>
#include <memory>
#include <string>

#include "gamestate.h"
#include "gameevent.h"
#include "eventdeck.h"
#include "sumar.h"

class Game {
public:
    Game();
    void ruleaza();
    void seteazaCheieAPI(const std::string& cheie);

private:
    GameState stat;
    EventDeck<std::shared_ptr<GameEvent>> deck;
    EventDeck<std::string> istoric;
    std::map<std::string, int> contoareTipuri;
    Sumar sumar;

    void afiseazaStat() const;
    int citesteOptiune(int max) const;
    std::string verificaFinal() const;
    void afiseazaRecap() const;
};

#endif
