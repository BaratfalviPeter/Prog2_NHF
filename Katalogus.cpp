//WM53NO
#include "Katalogus.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#ifdef MEMTRACE
#include "memtrace.h"
#endif

Katalogus::Katalogus(): darab(0), kapacitas(5) {
    TaroltFilm = new Film*[kapacitas]; // Foglal egy alap meretu katalogust

}

Katalogus::~Katalogus() {
    for (int i = 0; i < darab; i++)
    {
        delete TaroltFilm[i]; // A tarolon vegiglepked es torli a tartalmat
    }
    delete[] TaroltFilm; //Vegul torli a tombot is
    
}

void Katalogus::atmeretez() {
    Film** uj_filmtar = new Film*[kapacitas*2]; //Uj tarolo foglalasa ketszeres kapacitassal
    for (int i = 0; i < darab; i++)
    {
        uj_filmtar[i] = TaroltFilm[i]; // A regi adatokat betesszuk az ujba
    }
    delete[] TaroltFilm; // Felszabaditjuk a regit
    TaroltFilm=uj_filmtar; // Atallitjuk a pointert
    kapacitas= kapacitas*2; // A kapacitas erteket is megkettozzuk
    
}

Film* Katalogus::getterFilm(int index) const {
    if (index >= 0 && index < darab) //Megnezzuk hogy az index helyes elemre esik-e
    {
        return TaroltFilm[index]; //Ha helyes visszadjuk a film mutatojat
    }
    throw std::out_of_range("Rossz index lett megadva! Kier a listabol!"); 

}

bool Katalogus::rendezes_cim_jo_e(Irany ir, int hely) const { // A cim helyes sorrendjet ellenorzi, ha nem jo igazat ad vissza
    if (ir == Nov)
    {
        return TaroltFilm[hely]->getNev() > TaroltFilm[hely+1]->getNev(); // Ha novekvo sorrend kell
    }
    else 
    {
       return TaroltFilm[hely]->getNev() < TaroltFilm[hely+1]->getNev(); //Ha csokkeno sorrend kell
    }

}

bool Katalogus::rendezes_ido_jo_e(Irany ir, int hely) const { // Az ido helyes sorrendjet ellenorzi, ha nem jo igazat ad vissza
    if (ir == Nov)
    {
        return TaroltFilm[hely]->getIdo() > TaroltFilm[hely+1]->getIdo(); //Ha novekvo sorrend kell
    }
    else 
    {
       return TaroltFilm[hely]->getIdo() < TaroltFilm[hely+1]->getIdo(); // Ha csokkeno sorrend kell
    }

}

bool Katalogus::rendezes_kel_jo_e(Irany ir, int hely) const{ //A keletkezes helyes sorrendjet ellenorzi, ha nem jo igazat ad vissza
    if (ir == Nov)
    {
        return TaroltFilm[hely]->getKeletkezes() > TaroltFilm[hely+1]->getKeletkezes(); //Ha novekvo sorrend kell
    }
    else 
    {
       return TaroltFilm[hely]->getKeletkezes() < TaroltFilm[hely+1]->getKeletkezes(); //Ha csokkeno sorrend kell
    }

}

void Katalogus::rendezes(Rend_szempont szempont, Irany irany) {
    if (darab < 2)
    {
        throw std::runtime_error("Nincs eleg elem a listaban!");    //Van e eleg elem a katalogusba hogy rendezni lehessen
    }
    
    for (int i = 0; i < darab-1; i++) //Buborekrendezes algoritmusa
    {
        for (int j = 0; j < darab-i-1; j++)
        {
            bool rossz_e = false;           //A szempont alapjan eldontjuk hogy melyik ellenorzo segedfugvenyt kell hasznalni
            
            if (szempont == Cim)
            {
                rossz_e = rendezes_cim_jo_e(irany,j);
            }

            else if (szempont == Ido)
            {
                rossz_e = rendezes_ido_jo_e(irany,j);
            }

            else if (szempont == Keletkezes)
            {
                rossz_e = rendezes_kel_jo_e(irany,j);
            }

            if (rossz_e == true)        //Ha az elemek rossz sorrendben vannak akkor felcsereljuk a mutatoikat
            {
                Film* temp = TaroltFilm[j];
                TaroltFilm[j] = TaroltFilm[j+1];
                TaroltFilm[j+1] = temp;
            }

        }
        
    }
    
} 

void Katalogus::kereses(const std::string& cim, std::ostream& os) const {
    for (int i = 0; i < darab; i++)
    {
        if (TaroltFilm[i]->getNev().find(cim) != std::string::npos)     //std::string.find() npos-t ad vissza ha nincs benne a szoreszlet.
        {
            TaroltFilm[i]->kiir(os);
        }

    }

} 

Film* Katalogus::filmLekerdez (const std::string& cim, int ev) const { 
    for (int i = 0; i < darab; i++) // Vegigmegyunk a tarolt filmek listajan
    {
        if (TaroltFilm[i]->getNev()==cim && TaroltFilm[i]->getKeletkezes() == ev) // Ha megegyezik a pontos cim es a pontos ev akkor talaltunk van
        {
            return TaroltFilm[i]; // visszadjuk a keresett film mutatojat
        }
        
    }
    return nullptr;    
}
void Katalogus::listazas(std::ostream& os) const {
    for (int i = 0; i < darab; i++) //Vegigmegy a katalogus tartalman
    {
        os << i+1 << ". "; //Sorszamot tesz minden sor ele 
        TaroltFilm[i]->kiir(os); //Minden elemre meghivja a kiir() metodust
    }
    
}
void Katalogus::hozzaad(Film* film) {
     if (kapacitas <= darab) //Kapacitas ellenorzese
     {
        atmeretez(); //Ha keves a kapacitas akkor atmeretez
     }
    TaroltFilm[darab++] = film; //A tarolohoz hozzaadjuk az uj filmet es noveljuk a darabszamot

}
void Katalogus::torles(int index) {
    if (index < 0 || index >= darab)
    {
        throw std::out_of_range("Rossz index lett megadva! Kier a listabol!");
    }
    delete TaroltFilm[index]; //Torli az adott elemet
    darab--; //Csokkenti a darabszamot
    for (int i = index; i < darab; i++) //A torolt elem indexetol elindul a vegeig
    {
        TaroltFilm[i] = TaroltFilm[i+1]; //Minden elemet egyel elorebb helyez
    }
    
}
void Katalogus::mentes(const std::string& fajlnev) const {
    std::ofstream KatalogusMentes(fajlnev); //Letrehozzuk a celfajlt
    if (!KatalogusMentes.is_open()) //Ellonirizzuk hogy sikeresen letre lett hozva es meg lehet-e nyitni
    {
        throw Fajlhiba("A fajl nem olvashato!! Fajl neve:" + fajlnev);
    }
    for (int i = 0; i < darab; i++)
    {
        TaroltFilm[i]->mentes(KatalogusMentes); //Vegigmegyunk a katalogus osszes elemen es meghivjuk a mentes metodust
    }
    KatalogusMentes.close(); //vegul bezarjuk a celfajlt
    
}
void Katalogus::betoltes(const std::string& fajlnev) {
    std::ifstream KatalogusBetoltes(fajlnev); //letrehosszuk a bemeneti celfajlt
    if (!KatalogusBetoltes.is_open())
    {
        throw Fajlhiba("A fajl nem olvashato!! Fajl neve:" + fajlnev); //Ellenorizzuk hogy sikeres volt-e a letrehozas
    }
    
    std::string sor;
    while (std::getline(KatalogusBetoltes,sor)) //Addig tart a ciklus ameddig tudunk behivni sort a sor valtozoba
    {
        std::string tipus;
        std::stringstream ss(sor);  //A beolvasott sort beleteszuk egy stringstreambe hogy konnyen ki tudjok beole az adatokat olvasni
        std::getline(ss,tipus,';'); //Az elso adatot kiolvassuk a ; ig 
        try
        {
            if (tipus == "CS")  //Az elso alapjan eldontjuk hogy milyen tipus, itt Csaladifilm tipusu
            {
                std::string nev,ido,keletkezes,korhatar; //Letrehozunk tarolokat amibe majd az adatokat tarolhatjuk
                std::getline(ss,nev,';'); //Tovabb daraboljuk a pontosveszoig es betesszuk az adott taroloba
                std::getline(ss,ido,';');
                std::getline(ss,keletkezes,';');
                std::getline(ss,korhatar);
                CsaladiFilm* uj_csfilm = new CsaladiFilm(nev,std::stoi(ido),std::stoi(keletkezes),std::stoi(korhatar)); // Vegul foglalunk memoriat az objektumnak es feltoltjuk az adatokkal
                hozzaad(uj_csfilm); // A hozzaad() metodus a katalogushoz adja az uj objektumot
            }

            else if(tipus == "D")   //Az elso alapjan eldontjuk hogy milyen tipus itt Dokumentumfilm. Minden ugyanugy tortenik tovabb mint a masik esetben
            {
                std::string nev,ido,keletkezes,leiras;
                std::getline(ss,nev,';');
                std::getline(ss,ido,';');
                std::getline(ss,keletkezes,';');
                std::getline(ss,leiras);
                DokumentumFilm* uj_dfilm = new DokumentumFilm(nev,std::stoi(ido),std::stoi(keletkezes),leiras);
                hozzaad(uj_dfilm);
            }

        }

        catch(const std::exception& e)
        {
            std::cerr << "Hiba az adatsorba, kihagyva." << '\n';
        }
        
    }
    
}