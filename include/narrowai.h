#ifndef OOP_NARROWAI_H
#define OOP_NARROWAI_H

#include "aimodel.h"

class NarrowAI : public AIModel {
public:
    std::string nume() const override;
    std::string descriere() const override;
};

#endif
