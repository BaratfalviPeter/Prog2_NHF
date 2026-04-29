#pragma once
#include <string>


class Film{
protected:
    std::string nev;
    int ido;
    int keletkezes;
public:
    Film();
    Film(std::string n, int i, int k);
    virtual void kiir() const = 0;
    virtual void mentes() const = 0;
    virtual ~Film();
};

class CsaladiFilm : public Film{
    int korhatar;
public:
    CsaladiFilm(std::string n, int i, int k, int kh);
    void kiir() const override;
    void mentes() const override;
    ~CsaladiFilm();
};

class DokumentumFilm : public Film{
    std::string leiras;
public:
    DokumentumFilm(std::string n, int i, int k, std::string l);
    void kiir() const override;
    void mentes() const override;
    ~DokumentumFilm();
};
