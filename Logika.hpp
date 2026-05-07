//WM53NO
#include "Katalogus.hpp"
#include "Kedvencek.hpp"

class Logika{
    Katalogus katalogusTarolo;
    Kedvencek kedvencekTarolo;
    //Betolti a kedvencektar.txt bol az adatokt
    void kedvencekBetolt();
    //Uj filmet lehet hozzaadni a katalogushoz(A teszt mukodese miatt kap film parametert amugy nem kapna)
    void ujFilmHozzaad(Film* film);
    //Kilistazza a kataloguusban levo filmeket
    void filmKilistaz();
    //Egy cím megadasaval keres a katalogusban
    void filmKereses();
    //Belelep a kedvencek almenube, kilistazza a kedvenceket
    void kedvencek();
    //A felhasznalotol kap egy kedvencekhez kivant adni film idexet es hozzaadja 
    void kedvencekhezAd();
    //Exportalja a kedvenceket egy txt fajlba amit a felhasznalo kedve szerint hasznalhat utanna
    void kedvencekExport();
    //Megadott index alapjan torol a kedvencek kozul
    void kedvencekTorol();
    //Megadott index alapjan totol a filmek kozul
    void filmTorol();
    //kilep a programbol
    void kilepes();
public:
    //Itt indul a program, meghivja a betolto fuggvenyeket
    void inditas();

};