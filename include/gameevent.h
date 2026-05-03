#ifndef OOP_GAMEEVENT_H
#define OOP_GAMEEVENT_H

#include <string>
#include <vector>

#include "optiune.h"

class GameEvent {
public:
    explicit GameEvent(std::string descriere);
    virtual ~GameEvent() = default;

    virtual std::string eticheta() const = 0;
    virtual const std::vector<Optiune>& optiuni() const = 0;

    std::string descriere() const;

    static int totalEvenimente();

private:
    std::string desc;
    static int contor;
};

#endif
