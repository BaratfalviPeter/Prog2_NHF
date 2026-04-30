#include "Film.hpp"
#include <iostream>

Film::Film() : nev(""), ido(0), keletkezes(0) {}
Film::Film(const std::string& n, int i, int k) : nev(n), ido(i), keletkezes(k) {}
Film::~Film() {}
//Tesztprogram jelez ha a cs_film ctor letrejott
CsaladiFilm::CsaladiFilm(const std::string& n, int i, int k, int kh) : Film(n, i, k), korhatar(kh) {
    std::cout << "Csaladi film letrejott" << std::endl;
}
void CsaladiFilm::kiir() const  {}
void CsaladiFilm::mentes() const  {}
//Tesztprogram jelez ha a cs_film  meghalt
CsaladiFilm::~CsaladiFilm() {
     std::cout << "Csaladi film meghalt" << std::endl;
}

//Tesztprogram jelez ha a d_film ctor letrejott
DokumentumFilm::DokumentumFilm(const std::string& n, int i, int k, const std::string& l) : Film(n, i, k), leiras(l) {
    std::cout << "Dokumentum film letrejott" << std::endl;
}
void DokumentumFilm::kiir() const {}
void DokumentumFilm::mentes() const {}
//Tesztprogram jelez ha a d_film meghalt
DokumentumFilm::~DokumentumFilm() {
    std::cout << "Dokumentum film meghalt" << std::endl;
}