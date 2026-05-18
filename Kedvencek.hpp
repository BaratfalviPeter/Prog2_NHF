//WM53NO
#pragma once
#include "Film.hpp"
#include "Kivetelek.hpp"
#include <string>

/**
 * @brief A kedvencek mutatoit tarolo osztaly
 * 
 */
class Kedvencek{
    Film** KedvencFilm;
    int darab;
    int kapacitas;
    
    /**
     * @brief Noveli a tarpolo kapacitasat
     * 
     */
    void atmeretez();

    //Masolas es ertekadas letiltasa
    Kedvencek(const Kedvencek&);
    Kedvencek operator=(const Kedvencek&);
public:

    /**
     * @brief Beallitja az alapertekeket es lefoglalja az alap 5 nagysagu tarolot
     * 
     */
    Kedvencek();

    /**
     * @brief Visszaadja a kedvenc filmek darabszamat
     * 
     * @return A darabszam
     */
    int get_db() const {return darab;}
   
    /**
     * @brief Kilistazza a kedvenc filmeket
     * 
     * @param os A cel kimenet
     */
    void listazas(std::ostream& os) const;
    
    /**
     * @brief A tarolohoz ad egy uj kedvencet (de szigoruan nem hoz letre ujat csak az adott film mutatojat menti)
     * 
     * @param film A katalogusbol szarmazo adott film mutatoja
     */
    void hozzaad(Film* film);

    /**
     * @brief Torli az adott filmet, vagyis annak a mutatojat csak maga a film megmarad a kataloguban
     * 
     * @param index A kedvenc indexe a listaban
     * @throw std::out_of_range Ha az index nem ervenyes
     */
    void torles(int index);

    /**
     * @brief Eltavolitja az adott film mutatojat 
     * 
     * @param keresett A keresett film mutatoja
     */
    void mutato_eltavolitas(Film* keresett);
    
    /**
     * @brief Elore megadott fix fajlba meni a kedvenceket (nev és a keltekezesi idejet)
     * 
     * @param fajlnev A fajl neve ahova menteni szeretnenk
     * @throw Fajlhiba Ha az adott fajl nem nyithato meg vagy nem olvashato
     */
    void mentes(const std::string& fajlnev) const;
    
    /**
     * @brief Exportalja a felhasznalo szamara a kedvenceit az osszes adataval (Abban a formatumba ahogy a kiiras is tortenik)
     * 
     * @param fajlnev A felhasznalo altal megadott fajl neve ahova az exportalas tortenik
     */
    void exportalas(const std::string& fajlnev)const;

    /**
     * @brief Felszabaditja a Kedvenceket
     * 
     */
    ~Kedvencek();
};