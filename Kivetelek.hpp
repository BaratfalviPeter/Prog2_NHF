//WM53NO
#pragma once
#include <stdexcept>
#include <string>

/**
 * @brief A fajlkezelesi hibak jelzesere szolgalo osztaly
 * Az std::runtime_error osztalybol szarmazik
 * 
 */
class Fajlhiba : public std::runtime_error {
public:

    /**
     * @brief Konstruktor amely beallitja a hibauzenetet
     * 
     * @param uzenet A hiba reszletes leirasa
     */
    Fajlhiba(const std::string& uzenet) : std::runtime_error(uzenet) {}
};

