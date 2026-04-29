#ifndef OOP_FRONTIERAI_H
#define OOP_FRONTIERAI_H

#include "aimodel.h"

class FrontierAI : public AIModel {
public:
    std::string nume() const override;
    std::string descriere();
};

#endif
