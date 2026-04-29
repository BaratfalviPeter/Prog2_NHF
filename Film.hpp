#include <string>


class Film{
protected:
    std::string nev;
    int ido;
    int keletkezes;
public:
    Film() : nev(""), ido(0), keletkezes(0){}
    Film(std::string n, int i, int k) : nev(n), ido(i), keletkezes(k) {}
    virtual void kiir() const = 0;
    virtual void mentes() const = 0;
    virtual ~Film() {}
};

class CsaladiFilm : public Film{
    int korhatar;
public:
    CsaladiFilm(std::string n, int i, int k, int kh) : Film(n, i, k), korhatar(kh) {}
    void kiir() const override;
    void mentes() const override;
    ~CsaladiFilm(){}
};

class DokumentumFilm : public Film{
    std::string leiras;
public:
    DokumentumFilm(std::string n, int i, int k, std::string l) : Film(n, i, k), leiras(l) {}
    void kiir() const override;
    void mentes() const override;
    ~DokumentumFilm(){}
};
