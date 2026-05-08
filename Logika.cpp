//WM53NO
#include "Logika.hpp"
#include"Film.hpp"
#include <iostream>

void Logika::kedvencekBetolt() {}
//A tesztprogram itt hasznalja a katalogus tarolot, bemutatja mukodeset. Tovabba a hozzaad metodust mutatja be
void Logika::ujFilmHozzaad(Film* film) {
    katalogusTarolo.hozzaad(film);
    
}
void Logika::filmKilistaz() {}
void Logika::filmKereses() {}
void Logika::kedvencek() {}
void Logika::kedvencekhezAd() {}
void Logika::kedvencekExport() {}
void Logika::kedvencekTorol() {}
void Logika::filmTorol() {}
void Logika::kilepes() {}
//Tesztrogram lefutasa
//A tesztprogram megmutatja a ctor/dtor hivasokat tovabba a katalogushoz adast. A kedvencek tarolo mukodeset is bemutatja
void Logika::inditas() {
    std::cout << "A program elindult" << std::endl;
    CsaladiFilm* uj_csfilm = new CsaladiFilm("Alma",120,1990,12);
    DokumentumFilm* uj_dfilm = new DokumentumFilm("Farkasok",90,2030,"Falka");
    uj_csfilm->kiir();
    uj_dfilm->kiir();
    ujFilmHozzaad(uj_csfilm);
    ujFilmHozzaad(uj_dfilm);
    kedvencekTarolo.hozzaad(uj_csfilm);
    delete uj_csfilm;
    delete uj_dfilm;
}