#include "eventloader.h"
#include "techevent.h"
#include "crisisevent.h"
#include "optiune.h"

#include <string>
#include <vector>

// cppcheck-suppress unusedFunction
std::shared_ptr<GameEvent> make_event(const nlohmann::json& j) {
    std::string nume = j.value("name", std::string{"event"});
    std::vector<Optiune> empty{};
    if (j.value("type", std::string{"tech"}) == "tech") {
        return std::make_shared<TechEvent>(nume, empty);
    }
    return std::make_shared<CrisisEvent>(nume, empty);
}
