//WM53NO
#include "Logika.hpp"
#include "Film.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

int Logika::beolvasas_ellenorzes(int also_h, int felso_h){
    int ertek;
    while (true)
    {
        std::cin >> ertek;
        if (std::cin.fail() || ertek < also_h || ertek > felso_h)
        {
            std::cin.clear();
            std::cin.ignore(MAX_PUFFER_MERET, '\n');
            std::cout << "Rossz erteket adtal meg probald meg ujra! Elvart: " << also_h << " - " << felso_h << std::endl;
            std::cout << "Valasztas: ";
            
        }
        else 
        {
            std::cin.ignore(MAX_PUFFER_MERET, '\n');
            return ertek;
        }
    }
    
}

void Logika::kedvencekBetolt(const std::string& fajlnev) {
    std::ifstream KedvencekBetolt(fajlnev);
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


void Logika::ujFilmHozzaad() {
    
    int valasztas = -1;
    std::string nev, leiras;
    int ido, keletkezes, korhatar;
    
    
    std::cout<< "1. Csaladifilm" << std::endl;
    std::cout<< "2. Dokumentumfim" << std::endl;
    std::cout<< "Valassza ki a film tipusat: " ;
    valasztas = beolvasas_ellenorzes(1,2);
        
    
    
    std::cout << std::endl << "Adja meg a film nevet: ";
    std::getline(std::cin >> std::ws, nev);
    
    std::cout << std::endl << "Adja meg a film hosszat: ";
    ido = beolvasas_ellenorzes(1,MAX_IDOTARTAM);
    
    std::cout << std::endl << "Adja meg a film keletkezeset: ";
    keletkezes = beolvasas_ellenorzes(1,EVSZAM);
    
    if (valasztas == 1)
    {
        
        
        std::cout << std::endl << "Adja meg a film korhatarat: ";
        korhatar = beolvasas_ellenorzes(1,MAX_KORHATAR);
        

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
    int valasztas = -1;
    if (katalogusTarolo.get_db() == 0)
    {
        std::cout << "A katalogus meg ures!" << std::endl;
    }
    else
    {
        Rend_szempont aktualis_sz = Cim;
        Irany aktualis_i = Nov;
        bool kell_rend = false;

        while (valasztas != 0)
        {
            katalogusTarolo.listazas(std::cout);
            std::cout << "1. Kedvencekhez hozzaadas, 2. Cim szerinti rendezes, 3. Ido szerinti rendezes, 4. Keletkezes szerinti rendezes, 5. Novekvo/Csokkeno sorrend, 0. Visszalepes" << std::endl;
            std::cout << "Valasztas: ";
            valasztas = beolvasas_ellenorzes(0,5);
            switch (valasztas)
            {
            case 1:
                std::cout << std::endl << "Adja meg a kedvencekhez kivant adni film sorszamat: ";
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
            if (kell_rend)
            {
                try
                {
                    katalogusTarolo.rendezes(aktualis_sz,aktualis_i);
                }
                catch(const std::runtime_error& e)
                {
                    std::cerr << "Hibas rendezes:" << e.what() << '\n';
                }
            }
            

        }
    }
    
}
void Logika::filmKereses() {
    std::string cim;
    std::cout << "Adja meg a keresett film cimet: ";
    std::getline(std::cin >> std::ws, cim);
    katalogusTarolo.kereses(cim,std::cout);
} 

void Logika::kedvencek() {
    
    int valasztas = -1;
    if (kedvencekTarolo.get_db() == 0)
    {
        std::cout << "Meg ures a kedvencek tarolo" << std::endl;
    }
    else
    {
    
        while (valasztas != 0)
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
    if (katalogusTarolo.getterFilm(index-1) == nullptr)
    {
        std::cout << "Nem talalhato ez a film." << std::endl;
        return;
    }
    kedvencekTarolo.hozzaad(katalogusTarolo.getterFilm(index-1));
    
}
void Logika::kedvencekExport() {
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
    if (katalogusTarolo.get_db() == 0)
    {
        std::cout << "A katalogus ures nincs mit torolni!" << std::endl;
        return;
    }

    katalogusTarolo.listazas(std::cout);
    std::cout << "Adja meg a torolni kivant film sorszamat: ";
    int index = beolvasas_ellenorzes(1,katalogusTarolo.get_db());
    try
    {
        kedvencekTarolo.mutato_eltavolitas(katalogusTarolo.getterFilm(index-1));
        katalogusTarolo.torles(index-1);
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