#ifndef OOP_EVENTDECK_H
#define OOP_EVENTDECK_H

#include <vector>
#include <utility>

#include "exceptions.h"

template <typename T>
class EventDeck {
public:
    // cppcheck-suppress unusedFunction
    void push(T item) {
        cards.push_back(std::move(item));
    }

    // cppcheck-suppress unusedFunction
    T draw() {
        if (cards.empty()) throw TakeoffException("deck gol");
        T item = std::move(cards.back());
        cards.pop_back();
        return item;
    }

    // cppcheck-suppress unusedFunction
    size_t size() const {
        return cards.size();
    }

    // cppcheck-suppress unusedFunction
    bool empty() const {
        return cards.empty();
    }

private:
    std::vector<T> cards;
};

#endif
