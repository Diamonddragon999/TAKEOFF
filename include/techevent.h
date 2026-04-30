#ifndef OOP_TECHEVENT_H
#define OOP_TECHEVENT_H

#include <vector>

#include "gameevent.h"
#include "optiune.h"

class TechEvent : public GameEvent {
public:
    explicit TechEvent(std::vector<Optiune> optiuni);
    std::string descriere() const override;
    void aplica(GameState& state) const override;
private:
    std::vector<Optiune> optiuni;
};

#endif
