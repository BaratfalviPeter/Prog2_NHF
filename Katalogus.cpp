//WM53NO
#include "Katalogus.hpp"
#include <iostream>
//Tesztprogram jelez ha a Katalogus letrejott
Katalogus::Katalogus() {
    std::cout << "A Katalogus letrejott" << std::endl;
}
//Tesztprogram jelez ha a Katalogus meghalt
Katalogus::~Katalogus() {
    std::cout << "A Katalogus meghalt" << std::endl;
}

void Katalogus::atmeretez() {}

Film* Katalogus::getterFilm(int index) const {return nullptr;}
void Katalogus::rendezes(Rend_szempont szempont, Irany irany) {}
void Katalogus::kereses(const std::string& cim) const {}
Film* Katalogus::filmLekerdez (const std::string& cim, int ev) const {return nullptr;}
void Katalogus::listazas() const {}
//Tesztprogram jelez ha film lett a katalogushoz adva
void Katalogus::hozzaad(Film* film) {
     std::cout << "Film a katalogushoz adva" << std::endl;
}
void Katalogus::torles(int index) {}
void Katalogus::mentes() const {}
void Katalogus::betoltes() {}