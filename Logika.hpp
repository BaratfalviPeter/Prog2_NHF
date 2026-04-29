#include "Katalogus.hpp"
#include "Kedvencek.hpp"

class Logika{
    Katalogus katalogusTarolo;
    Kedvencek kedvencekTarolo;
    void kedvencekBetolt();
    void ujFilmHozzaad(Film* film);
    void filmKilistaz();
    void filmKereses();
    void kedvencek();
    void kedvencekExport();
    void kedvencekTorol();
    void filmTorol();
    void kilepes();
public:
    void inditas();

};