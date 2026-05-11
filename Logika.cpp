//WM53NO
#include "Logika.hpp"
#include"Film.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

void Logika::kedvencekBetolt() {
    std::ifstream KedvencekBetolt("kedvencektar.txt");
    if (!KedvencekBetolt.is_open())
    {
        return;
    }
    
    std::string sor;
    while (std::getline(KedvencekBetolt,sor)){
        std::stringstream ss(sor);
        std::string nev , keletkezes;
        std::getline(ss,nev,';');
        std::getline(ss,keletkezes);
        Film* be_kedvenc;
        be_kedvenc = katalogusTarolo.filmLekerdez(nev,std::stoi(keletkezes));
        if (be_kedvenc != nullptr)
        {
            kedvencekTarolo.hozzaad(be_kedvenc);

        }
    }
}

//A tesztprogram itt hasznalja a katalogus tarolot, bemutatja mukodeset. Tovabba a hozzaad metodust mutatja be
void Logika::ujFilmHozzaad() {
    
    int valasztas = 0;
    std::string nev, leiras;
    int ido, keletkezes, korhatar;
    while (valasztas != 1 && valasztas != 2)
    {
        std::cout<< "1. Csaladifilm" << std::endl;
        std::cout<< "2. Dokumentumfim" << std::endl;
        std::cout<< "Valassza ki a film tipusat: " ;
        std::cin >> valasztas;
        if (valasztas != 1 && valasztas != 2)
        {
            std::cout << "Rossz szamot valasztott adja meg ujra!" << std::endl;
        }
        
    }
    
    std::cout << std::endl << "Adja meg a film nevet: ";
    std::getline(std::cin >> std::ws, nev);
    std::cout << std::endl << "Adja meg a film hosszat: ";
    std::cin >> ido;
    std::cout << std::endl << "Adja meg a film keletkezeset: ";
    std::cin >> keletkezes;
    if (valasztas == 1)
    {
        std::cout << std::endl << "Adja meg a film korhatarat: ";
        std::cin >> korhatar;
        CsaladiFilm* uj_csfilm = new CsaladiFilm(nev,ido,keletkezes,korhatar);
        katalogusTarolo.hozzaad(uj_csfilm);
    }
    if (valasztas == 2)
    {
        std::cout << std::endl << "Adja meg a film leirasat: ";
        std::getline(std::cin >> std::ws, leiras);
        DokumentumFilm* uj_dfilm = new DokumentumFilm(nev,ido,keletkezes,leiras);
        katalogusTarolo.hozzaad(uj_dfilm);
    }    
}

void Logika::filmKilistaz() {
    katalogusTarolo.listazas();
    //rendezes ide jon
}
void Logika::filmKereses() {}
void Logika::kedvencek() {}
void Logika::kedvencekhezAd() {}
void Logika::kedvencekExport() {}
void Logika::kedvencekTorol() {}
void Logika::filmTorol() {}
void Logika::kilepes() {}
//Tesztrogram lefutasa
//A tesztprogram megmutatja a ctor/dtor hivasokat tovabba a katalogushoz adast. A kedvencek tarolo mukodeset is bemutatja
void Logika::inditas() {
    /*
    //Tesztelesre hasznaltam
    std::cout << "A program elindult" << std::endl;
    CsaladiFilm* uj_csfilm = new CsaladiFilm("Alma",120,1990,12);
    DokumentumFilm* uj_dfilm = new DokumentumFilm("Farkasok",90,2030,"Falka");
    uj_csfilm->kiir(std::cout);
    uj_dfilm->kiir(std::cout);
    katalogusTarolo.hozzaad(uj_csfilm);
    katalogusTarolo.hozzaad(uj_dfilm);
    katalogusTarolo.listazas();
    kedvencekTarolo.hozzaad(uj_csfilm);
    kedvencekTarolo.listazas();
    katalogusTarolo.mentes();
    katalogusTarolo.betoltes();
    katalogusTarolo.listazas();
    kedvencekTarolo.mentes();
    kedvencekTarolo.exportalas("kedvenceim");
    */
    int valasztas = 10;
    while (valasztas != 0)
    {
        std::cout << "1. Film hozzaadasa" << std::endl;
        std::cout << "2. Filmek kilistazasa" << std::endl;
        std::cout << "3. Filmek keresese" << std::endl;
        std::cout << "4. Kedvenc filmek" << std::endl;
        std::cout << "5. Film torlese" << std::endl;
        std::cout << "0. Kilepes" << std::endl;

        std::cout << "Valasztas: ";
        std::cin >> valasztas;

        switch (valasztas)
        {
        case 1:
            ujFilmHozzaad();
            break;
        case 2:
            filmKilistaz();
            break;
        case 3:
            //kesobb megcsinalom
            break;

        case 4:
            
            break;

        case 5:
            break;

        case 0:
            break;
        default:
            std::cout << "Hibas valsztas!!" << std::endl;
            break;
        }
    }
    

    
    
}