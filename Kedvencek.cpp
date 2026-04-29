#include "Kedvencek.hpp"
#include <iostream>

Kedvencek::Kedvencek() {
    std::cout << "A Kedvencek letrejottek" << std::endl;
}
Kedvencek::~Kedvencek() {
    std::cout << "A Kedvencek meghaltak" << std::endl;
}

void Kedvencek::atmeretez() {}
void Kedvencek::listazas() const {}
void Kedvencek::hozzaad(Film* film) {
    std::cout << "Uj kedvenc lett hozzaadva" << std::endl;
}
void Kedvencek::torles(int index) {}
void Kedvencek::mentes() const {}
void Kedvencek::exportalas(std::string fajlnev)const {}

