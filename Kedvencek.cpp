//WM53NO
#include "Kedvencek.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
//Tesztprogram jelez ha kedvencek letrejottek
Kedvencek::Kedvencek() {
    darab = 0;
    kapacitas = 5;
    KedvencFilm = new Film*[kapacitas];

}
//Tesztprogram jelez ha kedvencek meghaltak
Kedvencek::~Kedvencek() {
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
void Kedvencek::listazas(std::ostream& os) const {
    for (size_t i = 0; i < darab; i++)
    {
        os << i+1 << ". ";
        KedvencFilm[i]->kiir(os);
    }
    
}
//Tesztprogram jelez ha kedvencekhez uj elem lett adva
void Kedvencek::hozzaad(Film* film) {
    if (darab >= kapacitas)
    {
        atmeretez();
    }
    KedvencFilm[darab++] = film;
    
}
void Kedvencek::torles(int index) {
    if (index < 0 || index >= darab)
    {
        throw std::out_of_range("Rossz index lett megadva! Kier a listabol!");
    }
    darab--;
    for (size_t i = index; i < darab; i++)
    {
        KedvencFilm[i] = KedvencFilm[i+1];
    }
    
}

void Kedvencek::mutato_eltavolitas(Film* keresett){
    for (size_t i = 0; i < darab;)
    {
        if (KedvencFilm[i] == keresett)
        {
            torles(i);
            
        }
        else i++;
        
        
    }
    
}

void Kedvencek::mentes(const std::string& fajlnev) const {
    std::ofstream KedvencekMentes(fajlnev);
    if (!KedvencekMentes.is_open())
    {
         throw Fajlhiba("A fajl nem olvashato!! Fajl neve:" + fajlnev);
    }
    for (size_t i = 0; i < darab; i++)
    {
        KedvencekMentes << KedvencFilm[i]->getNev() << ";" <<KedvencFilm[i]->getKeletkezes()<< std::endl;
    }
    KedvencekMentes.close();
    
}
void Kedvencek::exportalas(const std::string& fajlnev)const {
     std::ofstream KedvencekMentes(fajlnev);
    if (!KedvencekMentes.is_open())
    {
         throw Fajlhiba("A fajl nem olvashato!! Fajl neve:" + fajlnev);
    }
    for (size_t i = 0; i < darab; i++)
    {
        KedvencFilm[i]->kiir(KedvencekMentes);
    }
    KedvencekMentes.close();
    
}

