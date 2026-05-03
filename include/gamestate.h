#ifndef OOP_GAMESTATE_H
#define OOP_GAMESTATE_H

#include <memory>
#include <vector>

#include "observer.h"

class AIModel;

class GameState {
public:
    GameState();
    GameState(int tura, int bani, int cap, int alin);

    int getTura() const;
    int getBani() const;
    int getCapabilitate() const;
    int getAliniere() const;
    const AIModel& getModel() const;

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
    std::shared_ptr<AIModel> model;
    std::vector<std::shared_ptr<GameStateObserver>> observatori;

    void evolueaza();
    void notifica() const;
};

#endif
