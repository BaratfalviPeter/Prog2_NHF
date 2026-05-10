//WM53NO
#include "Kedvencek.hpp"
#include <iostream>
//Tesztprogram jelez ha kedvencek letrejottek
Kedvencek::Kedvencek() {
    std::cout << "A Kedvencek letrejottek" << std::endl;
    darab = 0;
    kapacitas = 5;
    KedvencFilm = new Film*[kapacitas];

}
//Tesztprogram jelez ha kedvencek meghaltak
Kedvencek::~Kedvencek() {
    std::cout << "A Kedvencek meghaltak" << std::endl;
    delete KedvencFilm;
}

void Kedvencek::atmeretez() {
    Film** uj_kedvencek = new Film*[kapacitas*2];
    for (size_t i = 0; i < darab; i++)
    {
        uj_kedvencek[i] = KedvencFilm[i];
    }
    delete[] KedvencFilm;
    KedvencFilm = uj_kedvencek;
    kapacitas = kapacitas*2;
    
}
void Kedvencek::listazas() const {
    for (size_t i = 0; i < darab; i++)
    {
        std::cout<<i+1<<". ";
        KedvencFilm[i]->kiir();
    }
    
}
//Tesztprogram jelez ha kedvencekhez uj elem lett adva
void Kedvencek::hozzaad(Film* film) {
    std::cout << "Uj kedvenc lett hozzaadva" << std::endl;
    if (darab >= kapacitas)
    {
        atmeretez();
    }
    KedvencFilm[darab++] = film;
    
}
void Kedvencek::torles(int index) {
    darab--;
    for (size_t i = index; i < darab; i++)
    {
        KedvencFilm[i] = KedvencFilm[i+1];
    }
    
}
void Kedvencek::mentes() const {}
void Kedvencek::exportalas(const std::string& fajlnev)const {}

