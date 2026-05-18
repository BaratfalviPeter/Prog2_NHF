//WM53NO
#include "Kedvencek.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

#ifdef MEMTRACE
#include "memtrace.h"
#endif

Kedvencek::Kedvencek() : darab(0), kapacitas(5) {   //Az alap kontruktor ertekek beallitasa
    KedvencFilm = new Film*[kapacitas]; //Lefoglalja az alap helyet 

}

Kedvencek::~Kedvencek() {
    delete[] KedvencFilm;   //Csak a mutatokat toroljuk mert az objektum marad tovabb a katalogusban
}

void Kedvencek::atmeretez() {
    Film** uj_kedvencek = new Film*[kapacitas*2]; //Megnoveli a kapacitast a duplajara
    for (int i = 0; i < darab; i++)
    {
        uj_kedvencek[i] = KedvencFilm[i]; //A regi tarolobol atteszi az ujra
    }
    delete[] KedvencFilm; //torli a regi tarolot
    KedvencFilm = uj_kedvencek; //A regi tarolo mutatojat az ujra allitja
    kapacitas = kapacitas*2;    // A kapacitast is noveljuk
     
}

void Kedvencek::listazas(std::ostream& os) const {
    for (int i = 0; i < darab; i++) // Vegigmegy az egesz kedvenceken 
    {
        os << i+1 << ". ";
        KedvencFilm[i]->kiir(os); //Minden elemre meghivja a kiir() metodust ami a megadott cel kimetre ir
    }
    
}

void Kedvencek::hozzaad(Film* film) {
    if (darab >= kapacitas) //Ha nem eleg a kapacitas az atmeretez() metodust hivja
    {
        atmeretez();
    }
    KedvencFilm[darab++] = film; // A kapott film mutatot hozzadja a tarolohoz es noveli a darabszamat

}

void Kedvencek::torles(int index) {
    if (index < 0 || index >= darab) // Ha az index nincs benne a jo tartomanyba akkor hibat dob
    {
        throw std::out_of_range("Rossz index lett megadva! Kier a listabol!");
    }
    darab--; //Csokkenti a darabszamot hogy a for ne fusson tul
    for (int i = index; i < darab; i++) //Az adott torolt indextol indul
    {
        KedvencFilm[i] = KedvencFilm[i+1]; //Az adott indexen levo elemet a legvegere tolja ami mar a darabszamon kivul esik
    } 

}

void Kedvencek::mutato_eltavolitas(Film* keresett){
    for (int i = 0; i < darab;) //Az elejerol indul a ciklus ami bejarja a kedvencek tarolojat
    {
        if (KedvencFilm[i] == keresett) //Ha megegyezik az adott elem akkor meghivodik a torles()
        {
            torles(i); //Csokkenti a darabszamot es a legvegere tolja az adott elemet
            
        }
        else i++; //Egyeb esetben a ciklus a kovetkezo elemre lep (a masik esetben nem kell novelni hiszen a torles() eltolta)
    }

}

void Kedvencek::mentes(const std::string& fajlnev) const { 
    std::ofstream KedvencekMentes(fajlnev); //Az adott fajl megnyitasa
    if (!KedvencekMentes.is_open())
    {
         throw Fajlhiba("A fajl nem nyithato meg!! Fajl neve:" + fajlnev); //A megnyitas ellenorzese
    }
    for (int i = 0; i < darab; i++)
    {
        KedvencekMentes << KedvencFilm[i]->getNev() << ";" <<KedvencFilm[i]->getKeletkezes()<< std::endl; //Vegigmegyunk a kedvenceken es a szukseges nev;keletkezes adatokat menjunk ebben a formatumban
    }
    KedvencekMentes.close(); //Bezarjuk a fajlt
    
}

void Kedvencek::exportalas(const std::string& fajlnev)const {
     std::ofstream KedvencekMentes(fajlnev); //Megnyitunk egy fajlt a felhasznalo altal megadott nev szerint
    if (!KedvencekMentes.is_open())
    {
         throw Fajlhiba("A fajl nem nyithato meg!! Fajl neve:" + fajlnev); //Ellenorizzuk hogy a fajl letrejott-e
    }
    for (int i = 0; i < darab; i++)
    {
        KedvencFilm[i]->kiir(KedvencekMentes); //Vegigmegyunk a kedvenceket es az osszesre meghuvjuk a kiir() metodust 
    }
    KedvencekMentes.close(); //Bezarjuk a fajlt
    
}

