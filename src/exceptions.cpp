#include "exceptions.h"

#include <string>

// cppcheck-suppress unusedFunction
BugetInsuficient::BugetInsuficient(int avem, int trebuie)
    : TakeoffException("nu ai destui bani: ai " + std::to_string(avem) + ", trebuie " + std::to_string(trebuie)) {}
