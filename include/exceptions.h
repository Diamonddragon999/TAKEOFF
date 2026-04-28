#ifndef OOP_EXCEPTIONS_H
#define OOP_EXCEPTIONS_H

#include <stdexcept>

class TakeoffException : public std::runtime_error {
public:
    using std::runtime_error::runtime_error;
};

class BugetInsuficient : public TakeoffException {
public:
    BugetInsuficient(int avem, int trebuie);
};

#endif
