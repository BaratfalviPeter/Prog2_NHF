#pragma once
#include "Film.hpp"
#include <string>

class Katalogus{
    Film** TaroltFilm;
    int darab;
    int kapacitás;
    void atmeretez();
public:
    Katalogus();
    Film* getterFilm(int index) const;
    void rendezes() const;
    void kereses(std::string cim) const;
    Film* filmLekerdez (std::string cim, int ev) const;
    void listazas() const;
    void hozzaad(Film* film);
    void torles(int index);
    void mentes() const;
    void betoltes();
    ~Katalogus();
};