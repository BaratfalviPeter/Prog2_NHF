#include "Katalogus.hpp"
#include <iostream>
Katalogus::Katalogus() {
    std::cout << "A Katalogus letrejott" << std::endl;
}
Katalogus::~Katalogus() {
    std::cout << "A Katalogus meghalt" << std::endl;
}

void Katalogus::atmeretez() {}

Film* Katalogus::getterFilm(int index) const {return nullptr;}
void Katalogus::rendezes() const {}
void Katalogus::kereses(std::string cim) const {}
Film* Katalogus::filmLekerdez (std::string cim, int ev) const {return nullptr;}
void Katalogus::listazas() const {}
void Katalogus::hozzaad(Film* film) {
     std::cout << "Film a katalogushoz adva" << std::endl;
}
void Katalogus::torles(int index) {}
void Katalogus::mentes() const {}
void Katalogus::betoltes() {}