//WM53NO
#pragma once
#include "Film.hpp"
#include "Kivetelek.hpp"
#include <string>

class Kedvencek{
    Film** KedvencFilm;
    int darab;
    int kapacitas;
    //Noveli a tarpolo kapacitasat
    void atmeretez();
    Kedvencek(const Kedvencek&);
    Kedvencek operator=(const Kedvencek&);
public:
    Kedvencek();
    int get_db() const {return darab;}
    //Kilistazza a tarolt elemeket
    void listazas(std::ostream& os) const;
    //A tarolohoz ad egy uj kedvencet(de szigoruan nem hoz letre ujat csak az adott film mutatojat menti)
    void hozzaad(Film* film);
    //Torli az adott filmet, vagyis annak a mutatojat csak maga a film megmarad a kataloguban
    void torles(int index);
    void mutato_eltavolitas(Film* keresett);
    //Elore megadott fix fajlba meni a kedvenceket
    void mentes(const std::string& fajlnev) const;
    //Exportalja a felhasznalo szamara a kedvenceit az osszes adataval
    void exportalas(const std::string& fajlnev)const;
    ~Kedvencek();
};