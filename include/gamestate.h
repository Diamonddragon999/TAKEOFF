#ifndef OOP_GAMESTATE_H
#define OOP_GAMESTATE_H

#include <memory>
#include <vector>

#include "observer.h"

class GameState {
public:
    GameState();
    GameState(int tura, int bani, int cap, int alin);

    int getTura() const;
    int getBani() const;
    int getCapabilitate() const;
    int getAliniere() const;

    void avanseaza();
    void cheltuieste(int cost);
    void incaseaza(int suma);
    void schimbaCapabilitate(int delta);
    void schimbaAliniere(int delta);

    void atasaObserver(std::shared_ptr<GameStateObserver> obs);

private:
    int tura;
    int bani;
    int capabilitate;
    int aliniere;
    std::vector<std::shared_ptr<GameStateObserver>> observatori;

    void notifica() const;
};

#endif
