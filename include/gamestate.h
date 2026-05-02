#ifndef OOP_GAMESTATE_H
#define OOP_GAMESTATE_H

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

private:
    int tura;
    int bani;
    int capabilitate;
    int aliniere;
};

#endif
