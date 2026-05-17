#include "eventloader.h"
#include "techevent.h"
#include "crisisevent.h"
#include "optiune.h"
#include "effects.h"
#include "schimbcompozit.h"

#include <string>
#include <vector>

static std::shared_ptr<DecisionEffect> make_effect(const std::string& kind, int delta) {
    if (kind == "bani") return std::make_shared<SchimbBani>(delta);
    if (kind == "cap") return std::make_shared<SchimbCapabilitate>(delta);
    if (kind == "alin") return std::make_shared<SchimbAliniere>(delta);
    return std::make_shared<SchimbBani>(0);
}

// cppcheck-suppress unusedFunction
std::shared_ptr<GameEvent> make_event(const nlohmann::json& j) {
    std::string desc = j.value("event", std::string{"event"});
    std::string type = j.value("type", std::string{"tech"});

    std::vector<Optiune> opts;
    for (const auto& opt : j["options"]) {
        std::string text = opt.value("text", std::string{"continua"});
        std::string kind = opt.value("effect", std::string{"bani"});
        int delta = opt.value("delta", 0);
        std::shared_ptr<DecisionEffect> efect = make_effect(kind, delta);

        if (opt.contains("secondary_effects") && opt["secondary_effects"].is_array()) {
            for (const auto& sec : opt["secondary_effects"]) {
                std::string kind2 = sec.value("effect", std::string{"bani"});
                int delta2 = sec.value("delta", 0);
                auto urmator = make_effect(kind2, delta2);
                efect = std::make_shared<SchimbCompozit>(efect, urmator);
            }
        } else if (opt.contains("secondary_effect") && opt.contains("secondary_delta")) {
            std::string kind2 = opt["secondary_effect"].get<std::string>();
            int delta2 = opt["secondary_delta"].get<int>();
            auto secundar = make_effect(kind2, delta2);
            efect = std::make_shared<SchimbCompozit>(efect, secundar);
        }

        opts.emplace_back(text, efect);
    }

    if (type == "crisis") {
        return std::make_shared<CrisisEvent>(desc, opts);
    }
    return std::make_shared<TechEvent>(desc, opts);
}
