//WM53NO
#include "Kedvencek.hpp"
#include <iostream>
//Tesztprogram jelez ha kedvencek letrejottek
Kedvencek::Kedvencek() {
    std::cout << "A Kedvencek letrejottek" << std::endl;
}
//Tesztprogram jelez ha kedvencek meghaltak
Kedvencek::~Kedvencek() {
    std::cout << "A Kedvencek meghaltak" << std::endl;
}

void Kedvencek::atmeretez() {}
void Kedvencek::listazas() const {}
//Tesztprogram jelez ha kedvencekhez uj elem lett adva
void Kedvencek::hozzaad(Film* film) {
    std::cout << "Uj kedvenc lett hozzaadva" << std::endl;
}
void Kedvencek::torles(int index) {}
void Kedvencek::mentes() const {}
void Kedvencek::exportalas(const std::string& fajlnev)const {}

