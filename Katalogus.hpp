//WM53NO
#pragma once
#include "Film.hpp"
#include <string>
//Rendezes szempontja
enum Rend_szempont{
    Cim = 1,
    Keletkezes = 2,
    Ido = 3
};
//Rendezes iranya
enum Irany{
    Nov = 1,
    Csokk = 2
};

class Katalogus{
    Film** TaroltFilm;
    int darab;
    int kapacitas;
    /** 
    * @brief  Megnoveli a tarolo kapacitasat a ketszeresere.
    * Csak a hozzaad() hivja ha megtel a tarolo
    */
    void atmeretez();
public:
    /**
     * @brief Beallitja az alapertekeket es foglal egy alap 5 kapacitasu katalogust.
    */
    Katalogus();
    int get_db() const {return darab;}
    //A film indexe alapjan visszaadja az adott film mutatojat
    Film* getterFilm(int index) const;
    //Rendezi a katalogust
    void rendezes(Rend_szempont szempont, Irany irany);
    //Megadott cim szerint keres a katalogusban
    void kereses(const std::string& cim) const;
    //Cim es ev szerint kikeresi a katalogusbol az adott filmet
    Film* filmLekerdez (const std::string& cim, int ev) const;
    
    /**
    * @brief Kilistazza a katalogus tartalmat es sorszamot rak az elemek ele
    * Nem valtoztatja a lista szerkezetet/elemeit
    */
    void listazas() const;
    
    /**
     * @brief Hozzaadja a katalogushoz az uj filmet
     * @param film Egy film pointert kap.
     */
    
    void hozzaad(Film* film);

    //Torol a katalogusbol veglegesen
    void torles(int index);
    //Elore megadott fix fajlba menti a katalogus tartalmat
    void mentes() const;
    //A fajlbol betolti a katalogus tartalmat
    void betoltes();
    ~Katalogus();
};