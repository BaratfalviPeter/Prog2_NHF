//WM53NO
#include "Katalogus.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

//Tesztprogram jelez ha a Katalogus letrejott
Katalogus::Katalogus() {
    darab = 0; 
    kapacitas = 5;
    TaroltFilm = new Film*[kapacitas]; // Foglal egy alap meretu katalogust
}

//Tesztprogram jelez ha a Katalogus meghalt
Katalogus::~Katalogus() {
    for (size_t i = 0; i < darab; i++)
    {
        delete TaroltFilm[i]; // A tarolon vegiglepked es torli a tartalmat
    }
    delete[] TaroltFilm; //Vegul torli a tombot is
    
}

void Katalogus::atmeretez() {
    Film** uj_filmtar = new Film*[kapacitas*2]; //Uj tarolo foglalasa ketszeres kapacitassal
    for (size_t i = 0; i < darab; i++)
    {
        uj_filmtar[i] = TaroltFilm[i]; // A regi adatokat betesszuk az ujba
    }
    delete[] TaroltFilm; // Felszabaditjuk a regit
    TaroltFilm=uj_filmtar; // Atallitjuk a pointert
    kapacitas= kapacitas*2; // A kapacitas erteket is megkettozzuk
    
}

Film* Katalogus::getterFilm(int index) const {
    if (index >= 0 && index < darab)
    {
        return TaroltFilm[index];
    }
    throw std::out_of_range("Rossz index lett megadva! Kier a listabol!");
}

void Katalogus::rendezes(Rend_szempont szempont, Irany irany) {
    if (darab < 2)
    {
        return;
    }
    

    for (size_t i = 0; i < darab-1; i++)
    {
        for (size_t j = 0; j < darab-i-1; j++)
        {
            bool rossz_e = false;
            
            if (szempont == Cim)
            {
                if (irany == Nov)
                {
                    if (TaroltFilm[j]->getNev() > TaroltFilm[j+1]->getNev())
                    {
                        rossz_e = true;
                    }
                }

                else if (irany == Csokk)
                {
                    if (TaroltFilm[j]->getNev() < TaroltFilm[j+1]->getNev())
                    {
                        rossz_e = true;
                    }
                }
                
            }

            else if (szempont == Ido)
            {
                if (irany == Nov)
                {
                    if (TaroltFilm[j]->get_ido() > TaroltFilm[j+1]->get_ido())
                    {
                        rossz_e = true;
                    }
                }

                else if (irany == Csokk)
                {
                    if (TaroltFilm[j]->get_ido() < TaroltFilm[j+1]->get_ido())
                    {
                        rossz_e = true;
                    }
                }
            }

            else if (szempont == Keletkezes)
            {
                if (irany == Nov)
                {
                    if (TaroltFilm[j]->getKeletkezes() > TaroltFilm[j+1]->getKeletkezes())
                    {
                        rossz_e = true;
                    }
                }

                else if (irany == Csokk)
                {
                    if (TaroltFilm[j]->getKeletkezes() < TaroltFilm[j+1]->getKeletkezes())
                    {
                        rossz_e = true;
                    }
                }
                
            }

            if (rossz_e == true)
            {
                Film* temp = TaroltFilm[j];
                TaroltFilm[j] = TaroltFilm[j+1];
                TaroltFilm[j+1] = temp;
            }

        }
        
    }
    
} 

void Katalogus::kereses(const std::string& cim, std::ostream& os) const {
    for (size_t i = 0; i < darab; i++)
    {
        if (TaroltFilm[i]->getNev().find(cim) != std::string::npos)
        {
            TaroltFilm[i]->kiir(os);
        }
        
    }
    
} 

Film* Katalogus::filmLekerdez (const std::string& cim, int ev) const {
    for (size_t i = 0; i < darab; i++)
    {
        if (TaroltFilm[i]->getNev()==cim && TaroltFilm[i]->getKeletkezes() == ev)
        {
            return TaroltFilm[i];
        }
        
    }
    return nullptr;    
}
void Katalogus::listazas(std::ostream& os) const {
    for (size_t i = 0; i < darab; i++) //Vegigmegy a katalogus tartalman
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
    for (size_t i = index; i < darab; i++) //A torolt elem indexetol elindul a vegeig
    {
        TaroltFilm[i] = TaroltFilm[i+1]; //Minden elemet egyel elorebb helyez
    }
    

    
}
void Katalogus::mentes(const std::string& fajlnev) const {
    std::ofstream KatalogusMentes(fajlnev);
    if (!KatalogusMentes.is_open())
    {
        throw Fajlhiba("A fajl nem olvashato!! Fajl neve:" + fajlnev);
    }
    for (size_t i = 0; i < darab; i++)
    {
        TaroltFilm[i]->mentes(KatalogusMentes);
    }
    KatalogusMentes.close();
    
}
void Katalogus::betoltes(const std::string& fajlnev) {
    std::ifstream KatalogusBetoltes(fajlnev);
    if (!KatalogusBetoltes.is_open())
    {
        throw Fajlhiba("A fajl nem olvashato!! Fajl neve:" + fajlnev);
    }
    
    std::string sor;
    while (std::getline(KatalogusBetoltes,sor))
    {
        std::string tipus;
        std::stringstream ss(sor);
        std::getline(ss,tipus,';');
        if (tipus == "CS")
        {
            std::string nev,ido,keletkezes,korhatar;
            std::getline(ss,nev,';');
            std::getline(ss,ido,';');
            std::getline(ss,keletkezes,';');
            std::getline(ss,korhatar);
            CsaladiFilm* uj_csfilm = new CsaladiFilm(nev,std::stoi(ido),std::stoi(keletkezes),std::stoi(korhatar));
            hozzaad(uj_csfilm);
        }
        else if(tipus == "D")
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
    
}