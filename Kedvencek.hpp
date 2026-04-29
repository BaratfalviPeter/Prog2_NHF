#include "Film.hpp"
#include <string>

class Kedvencek{
    Film** KedvencFilm;
    int darab;
    int kapacitás;
    void atmeretez();
public:
    Kedvencek();
    void listazas() const;
    void hozzaad(Film* film);
    void torles(int index);
    void mentes() const;
    void exportalas(std::string fajlnev)const;
    ~Kedvencek();
};