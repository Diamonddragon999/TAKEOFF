#ifndef OOP_LOGOBSERVER_H
#define OOP_LOGOBSERVER_H

#include "observer.h"

class LogObserver : public GameStateObserver {
public:
    void schimbat(GameState& s) override;
};

#endif
