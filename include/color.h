#ifndef OOP_COLOR_H
#define OOP_COLOR_H

#include <string>

namespace col {
    namespace code {
        constexpr const char* reset  = "\033[0m";
        constexpr const char* bold   = "\033[1m";
        constexpr const char* red    = "\033[31m";
        constexpr const char* green  = "\033[32m";
        constexpr const char* yellow = "\033[33m";
        constexpr const char* cyan   = "\033[36m";
        constexpr const char* gray   = "\033[90m";
    }

    // cppcheck-suppress unusedFunction
    inline std::string wrap(const char* c, const std::string& s) {
        return std::string{c} + s + code::reset;
    }

    // cppcheck-suppress unusedFunction
    inline std::string red(const std::string& s)    { return wrap(code::red, s); }
    // cppcheck-suppress unusedFunction
    inline std::string green(const std::string& s)  { return wrap(code::green, s); }
    // cppcheck-suppress unusedFunction
    inline std::string yellow(const std::string& s) { return wrap(code::yellow, s); }
    // cppcheck-suppress unusedFunction
    inline std::string cyan(const std::string& s)   { return wrap(code::cyan, s); }
    // cppcheck-suppress unusedFunction
    inline std::string gray(const std::string& s)   { return wrap(code::gray, s); }
    // cppcheck-suppress unusedFunction
    inline std::string bold(const std::string& s)   { return wrap(code::bold, s); }

    // cppcheck-suppress unusedFunction
    inline std::string redBold(const std::string& s) {
        return std::string{code::bold} + code::red + s + code::reset;
    }
    // cppcheck-suppress unusedFunction
    inline std::string greenBold(const std::string& s) {
        return std::string{code::bold} + code::green + s + code::reset;
    }
    // cppcheck-suppress unusedFunction
    inline std::string yellowBold(const std::string& s) {
        return std::string{code::bold} + code::yellow + s + code::reset;
    }
    // cppcheck-suppress unusedFunction
    inline std::string cyanBold(const std::string& s) {
        return std::string{code::bold} + code::cyan + s + code::reset;
    }

    // cppcheck-suppress unusedFunction
    inline std::string delta(int n) {
        return n >= 0 ? green(std::to_string(n)) : red(std::to_string(n));
    }

    // cppcheck-suppress unusedFunction
    inline std::string statBani(int v) {
        const std::string s = std::to_string(v);
        if (v < 100) return red(s);
        if (v < 500) return yellow(s);
        return green(s);
    }

    // cppcheck-suppress unusedFunction
    inline std::string statCap(int v) {
        const std::string s = std::to_string(v);
        if (v >= 150) return green(s);
        if (v >= 80)  return yellow(s);
        return s;
    }

    // cppcheck-suppress unusedFunction
    inline std::string statAlin(int v) {
        const std::string s = std::to_string(v);
        if (v < 40) return red(s);
        if (v < 60) return yellow(s);
        return green(s);
    }
}

#endif
