//WM53NO
#include "Film.hpp"
#include <iostream>
#ifdef MEMTRACE
#include "memtrace.h"
#endif

Film::Film() : nev(""), ido(0), keletkezes(0) {}

Film::Film(const std::string& n, int i, int k) : nev(n), ido(i), keletkezes(k) {}

Film::~Film() {}

CsaladiFilm::CsaladiFilm(const std::string& n, int i, int k, int kh) : Film(n, i, k), korhatar(kh) {}

void CsaladiFilm::kiir(std::ostream& os) const  {
    os << "Cim: "<< nev << " ; "<< "Idotartam: "<< ido << " ; "<< "Keletkezes: " << keletkezes << " ; " << "Korhatar: " << korhatar << std::endl;
}

void CsaladiFilm::mentes(std::ostream& os) const  {
    os << "CS"<<";"<< nev << ";"<< ido << ";"<< keletkezes << ";" << korhatar << std::endl;
}

CsaladiFilm::~CsaladiFilm() {}

DokumentumFilm::DokumentumFilm(const std::string& n, int i, int k, const std::string& l) : Film(n, i, k), leiras(l) {}

void DokumentumFilm::kiir(std::ostream& os) const {
     os << "Cim: "<< nev << " ; "<< "Idotartam: "<< ido << " ; "<< "Keletkezes: " << keletkezes << " ; " << "Leiras: " << leiras << std::endl;
}

void DokumentumFilm::mentes(std::ostream& os) const {
     os << "D"<<";"<< nev << ";"<< ido << ";"<< keletkezes << ";" << leiras << std::endl;
}

DokumentumFilm::~DokumentumFilm() {   }