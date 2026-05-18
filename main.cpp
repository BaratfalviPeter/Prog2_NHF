//WM53NO
#include "Logika.hpp"
#include "gtest_lite.hpp"
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
       EXPECT_THROW(kat.getterFilm(99),std::out_of_range);
       EXPECT_THROW(kat.rendezes(Cim,Nov),std::runtime_error);
       EXPECT_THROW(kat.torles(99),std::out_of_range);
       EXPECT_THROW(kedv.torles(99),std::out_of_range);

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