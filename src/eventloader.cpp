#include "eventloader.h"
#include "techevent.h"
#include "crisisevent.h"
#include "optiune.h"

#include <vector>

std::shared_ptr<GameEvent> make_event(const nlohmann::json& j) {
    if (j["type"] == "tech") {
        return std::make_shared<TechEvent>(std::vector<Optiune>{});
    }
    return std::make_shared<CrisisEvent>();
}
