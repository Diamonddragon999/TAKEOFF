#ifndef OOP_EVENTLOADER_H
#define OOP_EVENTLOADER_H

#include "gameevent.h"

#include <nlohmann/json.hpp>

GameEvent make_event(const nlohmann::json& j);

#endif
