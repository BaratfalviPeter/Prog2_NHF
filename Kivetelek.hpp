#pragma once
#include <stdexcept>
#include <string>

class Fajlhiba : public std::runtime_error {
public:
    Fajlhiba(const std::string& uzenet) : std::runtime_error(uzenet) {}
};

