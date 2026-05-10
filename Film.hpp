//WM53NO
#pragma once
#include <string>


class Film{
protected:
    std::string nev;
    int ido;
    int keletkezes;
public:
    Film();
    Film(const std::string& n, int i, int k);
    //Teljesen virtualis fuggveny kesobb lesz felulirva
    virtual void kiir() const = 0;
    //Teljesen virtualis fuggveny kesobb lesz felulirva
    virtual void mentes(std::ostream& os) const = 0;
    virtual ~Film();
};

class CsaladiFilm : public Film{
    int korhatar;
public:
    CsaladiFilm(const std::string& n, int i, int k, int kh);
    //Kiiraja a kepernyore az adott film adatait.
    void kiir() const override;
    //Elmenti az adott film adatait a specialis formatumba
    void mentes(std::ostream& os) const override;
    ~CsaladiFilm();
};

class DokumentumFilm : public Film{
    std::string leiras;
public:
    DokumentumFilm(const std::string& n, int i, int k, const std::string& l);
    //Kiiraja a kepernyore az adott film adatait.
    void kiir() const override;
    //Elmenti az adott film adatait a specialis formatumba
    void mentes(std::ostream& os) const override;
    ~DokumentumFilm();
};
