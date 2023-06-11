#ifndef KOLONI_H
#define KOLONI_H
#include "Taktik.h"
#include "Uretim.h"
#include "OnIcerikler.h"



struct KOLONI
{
    long int populasyon;
    long int yemek;
    char sembol;
    int kazanma;
    int kaybetme;
    Taktik taktik; // Polymorphism denemesi
    Uretim uretim; // Polymorphism denemesi
    boolean (*yasiyormu)(struct KOLONI*);
    int (*savas)(struct KOLONI*); // taktigin savas fonksiyonunu cagir burada.
    void (*uret)(struct KOLONI*);
    void (*tuket)(struct KOLONI*);
    void (*ureme)(struct KOLONI*);
    int (*savasYemekKaybi)(struct KOLONI*);
    void (*savasCanKaybi)(struct KOLONI*,int );
    void (*savasGanimeti)(struct KOLONI*,int);
    void (*toString)(struct KOLONI*);
    void (*yokEt)(struct KOLONI*);
};

typedef struct KOLONI* Koloni;


Koloni new_Koloni();
int savasKoloni(const Koloni); // taktigin savas fonksiyonunu cagir burada.
void uretKoloni(const Koloni);
void tuketKoloni(const Koloni);
int savasYemekKaybi(const Koloni);
void ureme(const Koloni);
boolean yasiyormu(const Koloni);
void savasCanKaybi(const Koloni,int);
void savasGanimeti(const Koloni,int);
void toStringKoloni(const Koloni);
void yokEtKoloni(const Koloni);
#endif