#ifndef OOP_CRISISEVENT_H
#define OOP_CRISISEVENT_H

#include "gameevent.h"

class CrisisEvent : public GameEvent {
public:
    std::string descriere() const override;
    void aplica(GameState& state) const override;
};

#endif
