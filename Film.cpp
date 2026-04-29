#include "Film.hpp"
#include <iostream>

Film::Film() : nev(""), ido(0), keletkezes(0) {}
Film::Film(std::string n, int i, int k) : nev(n), ido(i), keletkezes(k) {}
Film::~Film() {}

CsaladiFilm::CsaladiFilm(std::string n, int i, int k, int kh) : Film(n, i, k), korhatar(kh) {
    std::cout << "Csaladi film letrejott" << std::endl;
}
void CsaladiFilm::kiir() const  {}
void CsaladiFilm::mentes() const  {}
CsaladiFilm::~CsaladiFilm() {
     std::cout << "Csaladi film meghalt" << std::endl;
}

DokumentumFilm::DokumentumFilm(std::string n, int i, int k, std::string l) : Film(n, i, k), leiras(l) {
    std::cout << "Dokumentum film letrejott" << std::endl;
}
void DokumentumFilm::kiir() const {}
void DokumentumFilm::mentes() const {}
DokumentumFilm::~DokumentumFilm() {
    std::cout << "Dokumentum film meghalt" << std::endl;
}