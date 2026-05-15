//WM53NO
#include "Kedvencek.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
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
    delete[] KedvencFilm;
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
        KedvencFilm[i]->kiir(std::cout);
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
    if (index < 0 || index > darab)
    {
        return;
    }
    darab--;
    for (size_t i = index; i < darab; i++)
    {
        KedvencFilm[i] = KedvencFilm[i+1];
    }
    
}

void Kedvencek::mutato_eltavolitas(Film* keresett){
    for (size_t i = 0; i < darab; i++)
    {
        if (KedvencFilm[i] == keresett)
        {
            torles(i);
            return;
        }
        
    }
    
}

void Kedvencek::mentes() const {
    std::ofstream KedvencekMentes("kedvencektar.txt");
    if (!KedvencekMentes.is_open())
    {
        return;
    }
    for (size_t i = 0; i < darab; i++)
    {
        KedvencekMentes << KedvencFilm[i]->getNev() << ";" <<KedvencFilm[i]->getKeletkezes()<< std::endl;
    }
    KedvencekMentes.close();
    std::cout<<"mentes sikerult"<<std::endl;
}
void Kedvencek::exportalas(const std::string& fajlnev)const {
     std::ofstream KedvencekMentes(fajlnev);
    if (!KedvencekMentes.is_open())
    {
        return;
    }
    for (size_t i = 0; i < darab; i++)
    {
        KedvencFilm[i]->kiir(KedvencekMentes);
    }
    KedvencekMentes.close();
    std::cout<<"export sikerult"<<std::endl;
}

