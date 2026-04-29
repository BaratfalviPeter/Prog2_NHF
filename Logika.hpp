#include "Katalogus.hpp"
#include "Kedvencek.hpp"

class Logika{
    Katalogus katalogus;
    Kedvencek kedvencek;
    void kedvencekBetolt();
    void ujFilmHozzaad();
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