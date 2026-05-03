#include "aimodel.h"
#include "narrowai.h"
#include "frontierai.h"
#include "agenticai.h"

// cppcheck-suppress unusedFunction
std::shared_ptr<AIModel> AIModel::creeazaPentruCap(int cap) {
    if (cap >= 200) return std::make_shared<AgenticAI>();
    if (cap >= 100) return std::make_shared<FrontierAI>();
    return std::make_shared<NarrowAI>();
}
