#include "Film.hpp"

Film::Film() : nev(""), ido(0), keletkezes(0) {}
Film::Film(std::string n, int i, int k) : nev(n), ido(i), keletkezes(k) {}
Film::~Film() {}

CsaladiFilm::CsaladiFilm(std::string n, int i, int k, int kh) : Film(n, i, k), korhatar(kh) {}
void CsaladiFilm::kiir() const  {}
void CsaladiFilm::mentes() const  {}
CsaladiFilm::~CsaladiFilm() {}

DokumentumFilm::DokumentumFilm(std::string n, int i, int k, std::string l) : Film(n, i, k), leiras(l) {}
void DokumentumFilm::kiir() const {}
void DokumentumFilm::mentes() const {}
DokumentumFilm::~DokumentumFilm() {}