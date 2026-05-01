#include "eventloader.h"
#include "techevent.h"
#include "crisisevent.h"
#include "optiune.h"

#include <vector>

GameEvent make_event(const nlohmann::json& j) {
    if (j["type"] == "tech") {
        return TechEvent{std::vector<Optiune>{}};
    }
    return CrisisEvent{};
}
