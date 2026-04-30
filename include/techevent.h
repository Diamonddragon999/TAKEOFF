#ifndef OOP_TECHEVENT_H
#define OOP_TECHEVENT_H

#include "gameevent.h"

class TechEvent : public GameEvent {
public:
    std::string descriere() const override;
    void aplica(GameState& state) const override;
};

#endif
