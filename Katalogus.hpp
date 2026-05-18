//WM53NO
#pragma once
#include "Film.hpp"
#include "Kivetelek.hpp"
#include <string>

/**
 * @brief A rendezes szempontjait meghatarozo enum
 * 
 */
enum Rend_szempont{
    Cim = 2,            /**< Cim szerinti rendezes */
    Keletkezes = 3,     /**< Keletkezes szerinti rendezes */
    Ido = 4             /**< Ido szerinti rendezes */
};

/**
 * @brief A rendezes iranyaz meghatarozo enum
 * 
 */
enum Irany{
    Nov = 1,    /**< Novekvo iranyu rendezes */
    Csokk = 2   /**< Csokkeno iranyu rendezes */
};

/**
 * @brief A filmek kezeleseert es tarolasaert felelos osztaly
 * 
 */
class Katalogus{
    Film** TaroltFilm;
    int darab;
    int kapacitas;

    /** 
    * @brief  Megnoveli a tarolo kapacitasat a ketszeresere.
    * Csak a hozzaad() hivja ha megtel a tarolo
    */
    void atmeretez();

    // Masolas es ertekadas leiltasa
    Katalogus(const Katalogus&);
    Katalogus operator=(const Katalogus&);
public:

    /**
     * @brief Beallitja az alapertekeket es foglal egy alap 5 kapacitasu katalogust.
    */
    Katalogus();

    /**
     * @brief Visszaadja a tarolt filmek szamat
     * 
     * @return A tarolt filmek darabszama
     */
    int get_db() const {return darab;}
    
    /**
     * @brief A film indexe alapjan visszaadja az adott film mutatojat
     * 
     * @param index A film indexe a taroloban
     * @return Az adott filmre mutato pointer
     * @throw std::out_of_range Ha az index < 0 vagy index >= darabszam
     */
    Film* getterFilm(int index) const;
    
    /**
     * @brief Segedfuggveny ami eldonti hogy ket egymas mellett allo film cim rossz sorrendbe van-e
     * 
     * @param ir A rendezes iranya (nov/csokk)
     * @param hely A vizsgalt index
     * @return true Ha a ket vizsgalt egyseg nincs jo sorrendben
     * @return false Ha a ket egyseg jo sorrendben van
     */
    bool rendezes_cim_jo_e(Irany ir, int hely) const;

    /**
     * @brief Segedfuggveny ami eldonti hogy ket egymas mellett allo film idotartam rossz sorrendbe van-e
     * 
     * @param ir A rendezes iranya (nov/csokk)
     * @param hely A vizsgalt index
     * @return true Ha a ket vizsgalt egyseg nincs jo sorrendben
     * @return false Ha a ket egyseg jo sorrendben van
     */
    bool rendezes_ido_jo_e(Irany ir, int hely) const;

    /**
     * @brief Segedfuggveny ami eldonti hogy ket egymas mellett allo film keletkezes rossz sorrendbe van-e
     * 
     * @param ir A rendezes iranya (nov/csokk)
     * @param hely A vizsgalt index
     * @return true Ha a ket vizsgalt egyseg nincs jo sorrendben
     * @return false Ha a ket egyseg jo sorrendben van
     */
    bool rendezes_kel_jo_e(Irany ir, int hely) const;
    
    /**
     * @brief Rendezi a katalogus tartalmat a megadott szempontok szerint (Buborekrendezes)
     * 
     * @param szempont Mi alapjan rendezze a katalogust (Cim,Ido,Keletkezes)
     * @param irany Milyen iranyba rendezze a katalogust (Novekvo/CSokkeno)
     * @throw std::runtime_error Ha nincs eleg elem tehat az elemszam < mint 2 
     */
    void rendezes(Rend_szempont szempont, Irany irany);

    /**
     * @brief Megadott cimreszlet szeint keres a ketalogusban
     * Vegigmegy a kataloguson es ha a cimbe szerepel a keresett reszlet akkor kiirja azok adatait
     * @param cim A keresett cim vagy cimreszlet
     * @param os A celkimenet ahova a talalatok listazasa tortenik
     */
    void kereses(const std::string& cim, std::ostream& os) const;

    /**
     * @brief A cim es az ev alapjan adja vissza keresett film mutatojat
     * A kedvencek betoltesenel hasznaljuk 
     * @param cim A film cime
     * @param ev  A film keletkezesi eve
     * @return A megtalalt film mutatojat vagy ha nincs talalat akkor nullptr
     */
    Film* filmLekerdez (const std::string& cim, int ev) const;
    
    /**
    * @brief Kilistazza a katalogus tartalmat es sorszamot rak az elemek ele
    * Nem valtoztatja a lista szerkezetet/elemeit
    * @param os A cel kimenet
    */
    void listazas(std::ostream& os) const;
    
    /**
     * @brief Hozzaadja a katalogushoz az uj filmet
     * Szukseg eseten meghivja az atmeretez() metodust es boviti a katalogust
     * @param film Egy film pointert kap.
     */
    void hozzaad(Film* film);

    /**
     * @brief Torol egy filmet veglegesen a katalogusbol
     * A filmeket feljebb csusztatjuk hogy ne legyen ures lyuk a katalogusban
     * @param index A torlendo film indexe
     * @throw std::out_of_range Ha az index ervenytelen tehat index < 0 vagy index > darabszam
     */
    void torles(int index);
    //
    /**
     * @brief Elore megadott fix fajlba menti a katalogus tartalmat
     * 
     * @param fajlnev Annak a fajlnak a neve ahova a mentes kivanjuk vegezni
     * @throw Fajlhiba Ha a fajl nem olvashato vagy nem letezik
     */
    void mentes(const std::string& fajlnev) const;
    //
    /**
     * @brief A fajlbol betolti a katalogus tartalmat
     * A specialis kodolast dekodolja ertelmezi a CS/D tipusjelolesket
     * @param fajlnev A betoltendo fajl neve
     * @throw Fajlhiba Ha az adott fajl nem nyithato meg vagy nem olvashato
     */
    void betoltes(const std::string& fajlnev);

    /**
     * @brief Felszabaditja a Katalogust
     * 
     */
    ~Katalogus();
};