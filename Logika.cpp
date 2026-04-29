#include "Logika.hpp"
#include"Film.hpp"
#include <iostream>

void Logika::kedvencekBetolt() {}
void Logika::ujFilmHozzaad(Film* film) {
    katalogusTarolo.hozzaad(film);
    kedvencekTarolo.hozzaad(film);
}
void Logika::filmKilistaz() {}
void Logika::filmKereses() {}
void Logika::kedvencek() {}
void Logika::kedvencekExport() {}
void Logika::kedvencekTorol() {}
void Logika::filmTorol() {}
void Logika::kilepes() {}
void Logika::inditas() {
    std::cout << "A program elindult" << std::endl;
     CsaladiFilm* uj_csfilm = new CsaladiFilm("Alma",120,1990,12);
    DokumentumFilm* uj_dfilm = new DokumentumFilm("Farkasok",90,2030,"Falka");
    ujFilmHozzaad(uj_csfilm);
    ujFilmHozzaad(uj_dfilm);
    delete uj_csfilm;
    delete uj_dfilm;
}