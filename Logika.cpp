//WM53NO
#include "Logika.hpp"
#include "Film.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#ifdef MEMTRACE
#include "memtrace.h"
#endif

int Logika::beolvasas_ellenorzes(int also_h, int felso_h){ //Ez felelos hogy az adatbekeres jo legyen
    int ertek;
    while (true) //Teljesen a visszatereseig megy
    {
        std::cin >> ertek; //beolvassa a kijelzorol az adatot
        if (std::cin.fail() || ertek < also_h || ertek > felso_h) //Ha az adat nem felel meg hogy int tipusu vagy nincs benne a korlatokba akkor belep az if-be
        {
            std::cin.clear(); //Torli a hiballapotot
            std::cin.ignore(MAX_PUFFER_MERET, '\n'); //Uriti a pufferben maradt hibas karaktereket
            std::cout << "Rossz erteket adtal meg probald meg ujra! Elvart: " << also_h << " - " << felso_h << std::endl;
            std::cout << "Valasztas: ";
        }
        else //Ez fut le jo ertek megadasa utan
        {
            std::cin.ignore(MAX_PUFFER_MERET, '\n'); //Uriti a pufferben maradt karaktereket hogy a kovetkezo hasznalatnal ne okozzon gondot 
            return ertek; // Megszakitja a while-t es visszater egy helyes ertekkel

        }

    }
    
}

void Logika::kedvencekBetolt(const std::string& fajlnev) {
    std::ifstream KedvencekBetolt(fajlnev); //Megnyitja az elore meghatarozott nevu fajlt.
    if (!KedvencekBetolt.is_open())
    {
        return; //Ellenorzi hogy meg lehet e nyitni ha nem akkor kilep.
    }
    
    std::string sor;
    while (std::getline(KedvencekBetolt,sor)){ //Addig megy a ciklus ameddig tud uj sort beolvasni utanna megall
        std::stringstream ss(sor); //A sor at van adva a stringsteamnek amibol majd elemenkent ki tudunk olvasni
        std::string nev , keletkezes;
        std::getline(ss,nev,';'); //kiolvassuk a nevet
        std::getline(ss,keletkezes); // Kiolvassuk a keletkezest
        try
        {
            int evszam = std::stoi(keletkezes); //A keletkezest int-re alakitjuk mert string volt
            Film* be_kedvenc = katalogusTarolo.filmLekerdez(nev,evszam); //Lekerjuk az adott film pointerjet
            if (be_kedvenc != nullptr)//Ha sikeres volt a kereses
            {
            kedvencekTarolo.hozzaad(be_kedvenc); //Akkor a kedvencek tarolohoz addjuk
            }
        }
        catch(const std::exception& e)
        {
            std::cerr<< "Hibas adatsor a fajlban! Kihagyva." << '\n';
        }
        
    }

}


void Logika::ujFilmHozzaad() {
    
    int valasztas = -1;
    std::string nev, leiras;
    int ido, keletkezes, korhatar;
    
    std::cout<< "1. Csaladifilm" << std::endl; //A felhasznalo kivalasztja a film tipusat
    std::cout<< "2. Dokumentumfim" << std::endl;
    std::cout<< "Valassza ki a film tipusat: " ;
    valasztas = beolvasas_ellenorzes(1,2);
        
    std::cout << std::endl << "Adja meg a film nevet: "; //A felhasznalo megadja a film nevet
    std::getline(std::cin >> std::ws, nev);
    
    std::cout << std::endl << "Adja meg a film hosszat: ";//A felhasznalo megadja a film idotartamat
    ido = beolvasas_ellenorzes(1,MAX_IDOTARTAM);
    
    std::cout << std::endl << "Adja meg a film keletkezeset: "; //A felhasznalo megadja a film keletkezesi evszamjat
    keletkezes = beolvasas_ellenorzes(1,EVSZAM);
    
    if (valasztas == 1) //Ha csaladi film tipust kapott akkor ez fut le
    {
        std::cout << std::endl << "Adja meg a film korhatarat: ";   // Bekeri a specialis adatot itt a korhatart
        korhatar = beolvasas_ellenorzes(1,MAX_KORHATAR);
        
        CsaladiFilm* uj_csfilm = new CsaladiFilm(nev,ido,keletkezes,korhatar); //Uj helyet foglal az objektumnak
        katalogusTarolo.hozzaad(uj_csfilm); //Majd hozzaadja a katalogushoz
    }

    if (valasztas == 2) //Ha dokumentum film tipust kapott akkor ez fut le
    {
        std::cout << std::endl << "Adja meg a film leirasat: "; // Bekeri a specialis adatot itt a leirast
        std::getline(std::cin >> std::ws, leiras);

        DokumentumFilm* uj_dfilm = new DokumentumFilm(nev,ido,keletkezes,leiras);   //Uj helyet foglal az objektumnak
        katalogusTarolo.hozzaad(uj_dfilm);  //Majd hozzaadja a katalogushoz
    }    

}

void Logika::filmKilistaz() {
    int valasztas = -1;

    if (katalogusTarolo.get_db() == 0) //Ellenorzi hogy a katalogus nem ures e 
    {
        std::cout << "A katalogus meg ures!" << std::endl;
    }

    else
    {
        Rend_szempont aktualis_sz = Cim;
        Irany aktualis_i = Nov;
        bool kell_rend = false;

        while (valasztas != 0)  //Addig fut ameddig a valsztas nem 0 vagyis a visszalepes gomb nincs leutve
        {
            katalogusTarolo.listazas(std::cout); 
            std::cout << "1. Kedvencekhez hozzaadas, 2. Cim szerinti rendezes, 3. Ido szerinti rendezes, 4. Keletkezes szerinti rendezes, 5. Novekvo/Csokkeno sorrend, 0. Visszalepes" << std::endl;
            std::cout << "Valasztas: ";
            valasztas = beolvasas_ellenorzes(0,5);
            switch (valasztas)
            {
            case 1:
            {    std::cout << std::endl << "Adja meg a kedvencekhez kivant adni film sorszamat: ";
                int index = beolvasas_ellenorzes(1,katalogusTarolo.get_db());
                try
                {
                   kedvencekhezAd(index);
                }
                catch(const std::out_of_range& e)
                {
                    std::cerr << "Hiba: " << e.what() << '\n';
                }
                break;
            }
            case 2:
                aktualis_sz = Cim;
                kell_rend = true;
                break;

            case 3:
                aktualis_sz = Ido;
                kell_rend = true;
                break;

            case 4:
                aktualis_sz = Keletkezes;
                kell_rend = true;
                break;

            case 5:
                if (aktualis_i == Nov)
                {
                    aktualis_i = Csokk;
                    kell_rend = true;
                }

                else
                {
                    aktualis_i = Nov;
                    kell_rend = true;
                } 
                break;

            case 0:
                //visszalepes itt tortenik
                break;

            default:
                std::cout << "Hibas valsztas!!" << std::endl;
                break;
            }
            if (kell_rend) //ha kell rendezes vagyis a kell_rend igaz lesz lefut ez a programresz
            {
                try
                {
                    katalogusTarolo.rendezes(aktualis_sz,aktualis_i); //Meghivodik a rendezes metodus
                }
                catch(const std::runtime_error& e)
                {
                    std::cerr << "Hibas rendezes:" << e.what() << '\n';
                }
            }

        }

    }
    
}
void Logika::filmKereses() const {
    std::string cim;
    std::cout << "Adja meg a keresett film cimet: ";
    std::getline(std::cin >> std::ws, cim); //Bekeri a cimet vagy cimreszletet
    katalogusTarolo.kereses(cim,std::cout);
} 

void Logika::kedvencek() {
    
    int valasztas = -1;
    if (kedvencekTarolo.get_db() == 0) //Ellenorzi hogy van-e adat a kedvencek taroloban
    {
        std::cout << "Meg ures a kedvencek tarolo" << std::endl;
    }

    else
    {
        while (valasztas != 0)//Addig fut a ciklus ameddig a visszalep gomb nincs megnyova vagyis a 0.
        {
            kedvencekTarolo.listazas(std::cout);
            std::cout << "1. Kedvencek exportalasa, 2. Kedvencek kozul torles, 0. Visszalepes" << std::endl;
            std::cout << "Valasztas: ";
            valasztas = beolvasas_ellenorzes(0,2);
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
    
}
void Logika::kedvencekhezAd(int index) {
    if (katalogusTarolo.getterFilm(index-1) == nullptr) //Ha az adott film indexe nem talalhato akkor ez a resz fut le.
    {
        std::cout << "Nem talalhato ez a film." << std::endl;
        return;
    }
    kedvencekTarolo.hozzaad(katalogusTarolo.getterFilm(index-1)); //Egyeb esetekben ha talalhato a kedvencekhez lesz hozzaadva 
    
}
void Logika::kedvencekExport() const {
    std::string fajlnev;
    std::cout << "Adja meg a fajl nevet: ";
    std::cin >> fajlnev;

    try
    {
        kedvencekTarolo.exportalas(fajlnev);
    }
    catch(const Fajlhiba& e)
    {
        std::cerr << "Exportalasi hiba: " << e.what() << '\n';
    }
    
    std::cout << std::endl;
    std::cout << "Exportalas sikeres!" << std::endl;
}
void Logika::kedvencekTorol() {
    
    std::cout << "Adja meg a torolni kivant kedvenc sorszamat: ";
    int index = beolvasas_ellenorzes(1,kedvencekTarolo.get_db());

    try
    {
        kedvencekTarolo.torles(index-1);
        std::cout << std::endl;
        std::cout << "Torles sikeres!" << std::endl;
    }
    catch(const std::out_of_range& e)
    {
        std::cerr << "Hiba a torleskor: " << e.what() << '\n';
    }
    
}
void Logika::filmTorol() {
    if (katalogusTarolo.get_db() == 0) //Ellenorzi hogy van-e elem amit lehet torolni.
    {
        std::cout << "A katalogus ures nincs mit torolni!" << std::endl;
        return;
    }

    katalogusTarolo.listazas(std::cout);
    std::cout << "Adja meg a torolni kivant film sorszamat: ";
    int index = beolvasas_ellenorzes(1,katalogusTarolo.get_db());

    try
    {
        kedvencekTarolo.mutato_eltavolitas(katalogusTarolo.getterFilm(index-1)); //Elsonek torli a kedvencek tarolobol a film mutatojat, ha tobb van benne az osszeset.
        katalogusTarolo.torles(index-1); //Utanna torli magat a filmet is.
        std::cout << "Torles sikeres!" << std::endl;
    }
    catch(const std::out_of_range& e)
    {
        std::cerr << "Hiba a torlekor: " << e.what() << '\n';
    }

}

void Logika::kilepes() {
    try
    {
        katalogusTarolo.mentes("filmtar.txt");
        kedvencekTarolo.mentes("kedvencektar.txt"); 
    }
    catch(const Fajlhiba& e)
    {
        std::cerr << "Mentesi hiba: " << e.what() << '\n';
    }
    
}

void Logika::inditas() {
   try
   {
    katalogusTarolo.betoltes("filmtar.txt");
    kedvencekBetolt("kedvencektar.txt");
   }
   catch(const Fajlhiba& e)
   {
    std::cerr<< "Inditasi hiba: " << e.what() << '\n';
   }
   
    int valasztas = -1;
    while (valasztas != 0)
    {
        std::cout << "1. Film hozzaadasa" << std::endl;
        std::cout << "2. Filmek kilistazasa" << std::endl;
        std::cout << "3. Filmek keresese" << std::endl;
        std::cout << "4. Kedvenc filmek" << std::endl;
        std::cout << "5. Film torlese" << std::endl;
        std::cout << "0. Kilepes" << std::endl;

        std::cout << "Valasztas: ";
        valasztas = beolvasas_ellenorzes(0,5);
        switch (valasztas)
        {
        case 1:
            ujFilmHozzaad();
            break;
        case 2:
            filmKilistaz();
            break;
        case 3:
            filmKereses();
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