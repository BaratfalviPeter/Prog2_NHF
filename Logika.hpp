//WM53NO
#pragma once
#include "Katalogus.hpp"
#include "Kedvencek.hpp"
#include <string>

/**
 * @brief A program logikajat es menurendszeret kezeli
 * Ez iranyitja a katlogus es kedvencek osztalyt tovabb figyel a helyes menuvezerlesre
 */
class Logika{

    Katalogus katalogusTarolo;
    Kedvencek kedvencekTarolo;

    //A korlatokert felelos konstansok
    static const int EVSZAM = 2026;
    static const int MAX_IDOTARTAM = 5000;
    static const int MAX_KORHATAR = 100;
    static const int MAX_PUFFER_MERET = 10000;

    /**
     * @brief Ellenorzi a szambevitelt egy adott tartomanyban
     * 
     * @param also_h A tartomany also hatara 
     * @param felso_h A tartomany felso hatara
     * @return A beolvasott es ellenorzott ertek
     */
    int beolvasas_ellenorzes(int also_h, int felso_h);
    
    /**
     * @brief Betolti a kedvencektar.txt bol az adatokt
     * 
     * @param fajlnev Az elore meghatarozott fajl neve ahol az adatok vannak tarolva
     */
    void kedvencekBetolt(const std::string& fajlnev);
    
    /**
     * @brief Uj filmet lehet hozzaadni a katalogushoz
     * 
     */
    void ujFilmHozzaad();
    
    /**
     * @brief Kilistazza a kataloguusban levo filmeket
     * 
     */
    void filmKilistaz();
    
    /**
     * @brief Egy cim vagy cimreszlet  megadasaval keres a katalogusban
     * 
     */
    void filmKereses() const;
    
    /**
     * @brief Belelep a kedvencek almenube, kilistazza a kedvenceket
     * 
     */
    void kedvencek();
    
    /**
     * @brief A felhasznalotol kap egy kedvencekhez kivant adni film idexet es hozzaadja 
     * 
     * @param index Ez a felhasznalo altal valasztott film indexe
     */
    void kedvencekhezAd(int index);
    
    /**
     * @brief Exportalja a kedvenceket egy txt fajlba amit a felhasznalo kedve szerint hasznalhat utanna
     * A fajl nevet a felhasznalotol keri be
     */
    void kedvencekExport() const ;
    
    /**
     * @brief Megadott index alapjan torol a kedvencek kozul
     * 
     */
    void kedvencekTorol();
    
    /**
     * @brief Megadott index alapjan totol a filmek kozul
     * 
     */
    void filmTorol();
    
    /**
     * @brief kilep a programbol es elvegzi a menteseket
     * 
     */
    void kilepes();
public:
    
    /**
     * @brief Itt indul a program, meghivja a betolto fuggvenyeket
     * 
     */
    void inditas();

};