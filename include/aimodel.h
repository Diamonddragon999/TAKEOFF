#ifndef OOP_AIMODEL_H
#define OOP_AIMODEL_H

#include <memory>
#include <string>

class AIModel {
public:
    virtual ~AIModel() = default;
    virtual std::string nume() const = 0;
    virtual std::string descriere() const = 0;

    static std::shared_ptr<AIModel> creeazaPentruCap(int cap);
};

#endif
