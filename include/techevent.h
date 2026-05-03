#ifndef OOP_TECHEVENT_H
#define OOP_TECHEVENT_H

#include <string>
#include <vector>

#include "gameevent.h"
#include "optiune.h"

class TechEvent : public GameEvent {
public:
    TechEvent(std::string descriere, std::vector<Optiune> opts);
    TechEvent(const TechEvent& other);
    TechEvent& operator=(const TechEvent& other);

    std::string eticheta() const override;
    const std::vector<Optiune>& optiuni() const override;

private:
    std::vector<Optiune> opts;
};

#endif
