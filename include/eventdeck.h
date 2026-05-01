#ifndef OOP_EVENTDECK_H
#define OOP_EVENTDECK_H

#include <vector>
#include <utility>

#include "exceptions.h"

template <typename T>
class EventDeck {
public:
    void push(T item) {
        cards.push_back(std::move(item));
    }

    T draw() {
        if (cards.empty()) throw TakeoffException("deck gol");
        T item = std::move(cards.back());
        cards.pop_back();
        return item;
    }

    size_t size() const {
        return cards.size();
    }

    bool empty() const {
        return cards.empty();
    }

private:
    std::vector<T> cards;
};

#endif
