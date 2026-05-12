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
    int valasztas = 5;

    while (valasztas != 0)
    {
        katalogusTarolo.listazas();
        std::cout << "1. Kedvencekhez hozzaadas, 2. Rendezesi szempont, 3. Novekvo/Csokkeno sorrend, 0. Visszalepes" << std::endl;
        std::cout << "Valasztas: ";
        std::cin >> valasztas;
        switch (valasztas)
        {
        case 1:
            int index;
            std::cout << std::endl << "Adja meg a kedvencekhez kivant adni film sorszamat: ";
            std::cin >> index;
            std::cout << std::endl;
            kedvencekhezAd(index);
            break;

        case 2:
            //kesobb csinalom
            break;

        case 3:
            //kesobb csinalom
            break;

        case 0:
            //visszalepes itt tortenik
            break;

       
        default:
            std::cout << "Hibas valsztas!!" << std::endl;
            break;
        }

    }
      
    
}
void Logika::filmKereses() {}
void Logika::kedvencek() {
    
    int valasztas = 3;
    
    while (valasztas != 0)
    {
        kedvencekTarolo.listazas();
        std::cout << "1. Kedvencek exportalasa, 2. Kedvencek kozul torles, 0. Visszalepes" << std::endl;
        std::cout << "Valasztas: ";
        std::cin >> valasztas;
        std::cout << std::endl;
        switch (valasztas)
        {
        case 1:
            kedvencekExport();
            break;

        case 2:
            kedvencekTorol();
            break;

        case 0:
            // A program visszalep
            break;
        
        default:
            break;
        }
    }
    
    
}
void Logika::kedvencekhezAd(int index) {
    if (katalogusTarolo.getterFilm(index) == nullptr)
    {
        std::cout << "Nem talalhato ez a film." << std::endl;
        return;
    }
    kedvencekTarolo.hozzaad(katalogusTarolo.getterFilm(index));
    
}
void Logika::kedvencekExport() {
    std::string fajlnev;
    std::cout << "Adja meg a fajl nevet: ";
    std::cin >> fajlnev;
    kedvencekTarolo.exportalas(fajlnev);
    std::cout << std::endl;
    std::cout << "Exportalas sikeres!" << std::endl;
}
void Logika::kedvencekTorol() {
    int index;
    std::cout << "Adja meg a torolni kivant kedvenc sorszamat: ";
    std::cin >> index;
    kedvencekTarolo.torles(index);
    std::cout << std::endl;
    std::cout << "Torles sikeres!" << std::endl;
}
void Logika::filmTorol() {
    int index;
    katalogusTarolo.listazas();
    std::cout << "Adja meg a torolni kivant film sorszamat: ";
    std::cin >> index;
    katalogusTarolo.torles(index);
    std::cout << "torles sikeres" << std::endl; // teszteleshez

}
void Logika::kilepes() {
    katalogusTarolo.mentes();
    kedvencekTarolo.mentes();
}
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
    katalogusTarolo.betoltes();
    kedvencekBetolt();
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
            kedvencek();
            break;

        case 5:
            filmTorol();
            break;

        case 0:
            kilepes();
            break;
        default:
            std::cout << "Hibas valsztas!!" << std::endl;
            break;
        }
    }
    

    
    
}