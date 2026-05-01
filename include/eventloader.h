#ifndef OOP_EVENTLOADER_H
#define OOP_EVENTLOADER_H

#include <memory>

#include "gameevent.h"

#include <nlohmann/json.hpp>

std::shared_ptr<GameEvent> make_event(const nlohmann::json& j);

#endif
