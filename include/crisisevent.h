#ifndef OOP_CRISISEVENT_H
#define OOP_CRISISEVENT_H

#include <string>
#include <vector>

#include "gameevent.h"
#include "optiune.h"

class CrisisEvent : public GameEvent {
public:
    CrisisEvent(std::string descriere, std::vector<Optiune> opts);
    CrisisEvent(const CrisisEvent& other);
    CrisisEvent& operator=(const CrisisEvent& other);

    std::string eticheta() const override;
    const std::vector<Optiune>& optiuni() const override;

private:
    std::vector<Optiune> opts;
};

#endif
