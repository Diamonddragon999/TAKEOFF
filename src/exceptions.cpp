#include "exceptions.h"

#include <string>

BugetInsuficient::BugetInsuficient(int avem, int trebuie)
    : TakeoffException("nu ai destui bani: ai " + std::to_string(avem) + ", trebuie " + std::to_string(trebuie)) {}
