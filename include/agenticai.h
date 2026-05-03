#ifndef OOP_AGENTICAI_H
#define OOP_AGENTICAI_H

#include "aimodel.h"

class AgenticAI : public AIModel {
public:
    std::string nume() const override;
    std::string descriere() const override;
};

#endif
