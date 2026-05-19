//WM53NO
#include "Logika.hpp"
#include "gtest_lite.hpp"
#include<sstream>
#ifdef MEMTRACE
#include "memtrace.h"
#endif

void tesztek_futattasa(){

    TEST(Hozzaadas,Elso_teszt) {
        Katalogus kat;
        CsaladiFilm* cs_teszt = new CsaladiFilm("Shrek",120,2000,12);
        DokumentumFilm* d_teszt = new DokumentumFilm("Farkasok",90,2015,"Falka");
        kat.hozzaad(cs_teszt);
        kat.hozzaad(d_teszt);

        EXPECT_EQ(2,kat.get_db());
        EXPECT_EQ(120,kat.getterFilm(0)->getIdo());
        EXPECT_EQ(2000,kat.getterFilm(0)->getKeletkezes());
        EXPECT_STREQ("Shrek",kat.getterFilm(0)->getNev().c_str());
        EXPECT_STREQ("Farkasok",kat.getterFilm(1)->getNev().c_str());
        
    } END

    TEST(Rendezes,Masodik_teszt){
        Katalogus kat;
        CsaladiFilm* cs_teszt = new CsaladiFilm("Shrek",120,2000,12);
        DokumentumFilm* d_teszt = new DokumentumFilm("Farkasok",90,2015,"Falka");
        kat.hozzaad(cs_teszt);
        kat.hozzaad(d_teszt);

        kat.rendezes(Cim,Nov);
        EXPECT_STREQ("Farkasok",kat.getterFilm(0)->getNev().c_str());
        kat.rendezes(Cim,Csokk);
        EXPECT_STREQ("Shrek",kat.getterFilm(0)->getNev().c_str());
        kat.rendezes(Ido,Nov);
        EXPECT_EQ(90,kat.getterFilm(0)->getIdo());
        kat.rendezes(Ido,Csokk);
        EXPECT_EQ(120,kat.getterFilm(0)->getIdo());
        kat.rendezes(Keletkezes,Nov);
        EXPECT_EQ(2000,kat.getterFilm(0)->getKeletkezes());
        kat.rendezes(Keletkezes,Csokk);
        EXPECT_EQ(2015,kat.getterFilm(0)->getKeletkezes());

    } END

    TEST(Kivetelek,Harmadik_teszt){
       Katalogus kat;
       Kedvencek kedv;
       EXPECT_THROW(kat.getterFilm(99), std::out_of_range);
       EXPECT_THROW(kat.rendezes(Cim,Nov), std::runtime_error);
       EXPECT_THROW(kat.torles(99), std::out_of_range);
       EXPECT_THROW(kedv.torles(99), std::out_of_range);

    } END

    TEST(Torles,Negyedik_teszt){
        Katalogus kat;
        Kedvencek kedv;
        CsaladiFilm* cs_teszt = new CsaladiFilm("Shrek",120,2000,12);
        kat.hozzaad(cs_teszt);
        kedv.hozzaad(cs_teszt);
        kedv.hozzaad(cs_teszt);
        kedv.mutato_eltavolitas(kat.getterFilm(0));
        kat.torles(0);
        EXPECT_EQ(0,kedv.get_db());

    } END

    TEST(Mentes,Otodik_teszt){
        Katalogus kat;
        CsaladiFilm* cs_teszt = new CsaladiFilm("Shrek",120,2000,12);
        DokumentumFilm* d_teszt = new DokumentumFilm("Farkasok",90,2015,"Falka");
        kat.hozzaad(cs_teszt);
        kat.hozzaad(d_teszt);
        kat.mentes("test.txt");
        Katalogus kat2;
        kat2.betoltes("test.txt");
        EXPECT_EQ(2,kat2.get_db());
        EXPECT_STREQ("Shrek", kat2.getterFilm(0)->getNev().c_str());

    } END

    TEST(Kiirasok,Hatodik_teszt){
        Katalogus kat;
        Kedvencek kedv;
        CsaladiFilm* cs_teszt = new CsaladiFilm("Shrek",120,2000,12);
        DokumentumFilm* d_teszt = new DokumentumFilm("Farkasok",90,2015,"Falka");
        kat.hozzaad(cs_teszt);
        kat.hozzaad(d_teszt);
        kedv.hozzaad(cs_teszt);
        std::stringstream ss;
        kat.listazas(ss);
        kat.kereses("Sh",ss);
        kedv.listazas(ss);
        

        
        EXPECT_NO_THROW(kedv.exportalas("teszt_export.txt"));
        EXPECT_NO_THROW(kedv.mentes("teszt_kedv.txt"));

    } END

    TEST(Betoltes,Hetedig_teszt){
        Katalogus kat;
        EXPECT_THROW(kat.betoltes("nem_letezik.txt"), Fajlhiba);

    } END

    TEST(Film_getter,Nyolcadik_teszt){
        CsaladiFilm* cs_teszt = new CsaladiFilm("Shrek",120,2000,12);
        std::string nev = cs_teszt->getNev();
        int ido = cs_teszt->getIdo();
        int kel = cs_teszt->getKeletkezes();

        EXPECT_STREQ("Shrek",nev.c_str());
        EXPECT_EQ(120,ido);
        EXPECT_EQ(2000,kel);
        
        delete cs_teszt;
           
    } END

    TEST(Atmeretez,Kilencedik_teszt){
        Katalogus kat;
        Kedvencek kedv;

        CsaladiFilm* cs_teszt0 = new CsaladiFilm("Shrek0",120,2000,12);
        CsaladiFilm* cs_teszt1 = new CsaladiFilm("Shrek1",120,2000,12);
        CsaladiFilm* cs_teszt2 = new CsaladiFilm("Shrek2",120,2000,12);
        CsaladiFilm* cs_teszt3 = new CsaladiFilm("Shrek3",120,2000,12);
        CsaladiFilm* cs_teszt4 = new CsaladiFilm("Shrek4",120,2000,12);

        kat.hozzaad(cs_teszt0);
        kat.hozzaad(cs_teszt1);
        kat.hozzaad(cs_teszt2);
        kat.hozzaad(cs_teszt3);
        kat.hozzaad(cs_teszt4);

        kedv.hozzaad(cs_teszt0);
        kedv.hozzaad(cs_teszt1);
        kedv.hozzaad(cs_teszt2);
        kedv.hozzaad(cs_teszt3);
        kedv.hozzaad(cs_teszt4);

        EXPECT_EQ(5,kat.get_db());
        EXPECT_EQ(5,kedv.get_db());

    }   END

}

int main() {
#ifdef CPORTA

    tesztek_futattasa();
    
#else

    Logika Program;
    Program.inditas();
    
#endif

    return 0;
}