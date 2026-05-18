//WM53NO
#pragma once
#include <string>

/**
 * @brief A filmek ososztalya
 * Ebbol szarmazik le a CsaladiFilm es DokumentumFilm
 */
class Film{
protected:
    std::string nev;
    int ido;
    int keletkezes;
public:

    /**
     * @brief Alapertelmezett konstrukor
     */
    Film();

    /**
     * @brief Parameteress konstruktor beallitja a film adatait
     * 
     * @param n A film cime
     * @param i A film idotartama (hossza)
     * @param k A keletkezes eve
     */
    Film(const std::string& n, int i, int k);

    /**
     * @brief Visszadja a film nevet
     * 
     * @return A film neve, const std::string& a masolas elkerulese erdekeben
     */
    const std::string& getNev() const {return nev;}

    /**
     * @brief Visszaadja a film idotartamat
     * 
     * @return A film idotartama percben
     */
    int getIdo() const {return ido;}

    /**
     * @brief Visszaadja a film keletkezeset
     * 
     * @return A keletkezes eve
     */
    int getKeletkezes() const {return keletkezes;}

    /**
     * @brief Teljesen virtualis fuggveny, az adatok kiirasara
     * 
     * @param os  A cel kimenet (std::cout vagy fajlba)
     */
    virtual void kiir(std::ostream& os) const = 0;
    
    /**
     * @brief Teljesen virtualis fuggveny, az adatok mentesere
     * 
     * @param os  A cel kimenet, fajlba ahova a mentes tortenik
     */
    virtual void mentes(std::ostream& os) const = 0;

    /**
     * @brief Virtualis destruktor a helyes felszabaditsert
     * 
     */
    virtual ~Film();
};

/**
 * @brief A film osztalybol szarmazik
 * Plusszba tarolja a korhatart is
 * 
 */
class CsaladiFilm : public Film{
    int korhatar;
public:

    /**
     * @brief A CSaladiFilm parameteres konstruktora
     * 
     * @param n A film cime
     * @param i A film idotartama
     * @param k A film keletkezesi ideje
     * @param kh A film korhatara
     */
    CsaladiFilm(const std::string& n, int i, int k, int kh);
    
    /**
     * @brief Kiirja az adott film adatait
     * 
     * @param os  A cel kimenet
     */
    void kiir(std::ostream& os) const override;
   
    /**
     * @brief Elmenti a film adatait egy elore megszabott specialis formatumba
     * 
     * @param os A cel kimenet
     */
    void mentes(std::ostream& os) const override;
    ~CsaladiFilm();
};

/**
 * @brief A film osztalybol szarmazik
 * Plusszba tarolja a film leirasat
 * 
 */
class DokumentumFilm : public Film{
    std::string leiras;
public:

    /**
     * @brief A DokumentumFilm parameteres kontruktora
     * 
     * @param n A film cime
     * @param i A film idotartama
     * @param k A film keletkezesi ideje
     * @param l A film leirasa
     */
    DokumentumFilm(const std::string& n, int i, int k, const std::string& l);

    /**
     * @brief Kiirja az adott film adatait
     * 
     * @param os A cel kimenet
     */
    void kiir(std::ostream& os) const override;

    /**
     * @brief Elmenti a film adatait egy elore megszabott specialis formatumba
     * 
     * @param os A cel kimenet
     */
    void mentes(std::ostream& os) const override;
    ~DokumentumFilm();
};
