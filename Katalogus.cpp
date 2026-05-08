//WM53NO
#include "Katalogus.hpp"
#include <iostream>

//Tesztprogram jelez ha a Katalogus letrejott
Katalogus::Katalogus() {
    std::cout << "A Katalogus letrejott" << std::endl;
    darab = 0; 
    kapacitas = 5;
    TaroltFilm = new Film*[kapacitas]; // Foglal egy alap meretu katalogust
}

//Tesztprogram jelez ha a Katalogus meghalt
Katalogus::~Katalogus() {
    std::cout << "A Katalogus meghalt" << std::endl;
    for (size_t i = 0; i < darab; i++)
    {
        delete TaroltFilm[i]; // A tarolon vegiglepked es torli a tartalmat
    }
    delete[] TaroltFilm; //Vegul torli a tombot is
    
}

void Katalogus::atmeretez() {
    Film** uj_filmtar = new Film*[kapacitas*2]; //Uj tarolo foglalasa ketszeres kapacitassal
    for (size_t i = 0; i < darab; i++)
    {
        uj_filmtar[i] = TaroltFilm[i]; // A regi adatokat betesszuk az ujba
    }
    delete[] TaroltFilm; // Felszabaditjuk a regit
    TaroltFilm=uj_filmtar; // Atallitjuk a pointert
    kapacitas= kapacitas*2; // A kapacitas erteket is megkettozzuk
    
}

Film* Katalogus::getterFilm(int index) const {return nullptr;}
void Katalogus::rendezes(Rend_szempont szempont, Irany irany) {}
void Katalogus::kereses(const std::string& cim) const {}
Film* Katalogus::filmLekerdez (const std::string& cim, int ev) const {return nullptr;}
void Katalogus::listazas() const {
    for (size_t i = 0; i < darab; i++) //Vegigmegy a katalogus tartalman
    {
        std::cout<< i+1 << ". "; //Sorszamot tesz minden sor ele 
        TaroltFilm[i]->kiir(); //Minden elemre meghivja a kiir() metodust
    }
    
}
void Katalogus::hozzaad(Film* film) {
     if (kapacitas <= darab) //Kapacitas ellenorzese
     {
        atmeretez(); //Ha keves a kapacitas akkor atmeretez
     }
    TaroltFilm[darab++] = film; //A tarolohoz hozzaadjuk az uj filmet es noveljuk a darabszamot
}
void Katalogus::torles(int index) {
    delete TaroltFilm[index]; //Torli az adott elemet
    darab--; //Csokkenti a darabszamot
    for (size_t i = index; i < darab; i++) //A torolt elem indexetol elindul a vegeig
    {
        TaroltFilm[i] = TaroltFilm[i+1]; //Minden elemet egyel elorebb helyez
    }
    

    
}
void Katalogus::mentes() const {}
void Katalogus::betoltes() {}