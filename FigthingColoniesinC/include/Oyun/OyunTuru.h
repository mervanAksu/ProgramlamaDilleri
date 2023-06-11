#ifndef OYUNTURU_H
#define OYUNTURU_H
#include "Savaslar.h"

struct OYUNTURU
{
    int koloniSayisi;
    int* eslesmeA;
    int* eslesmeB;
    int* eslesmeler;

    Savaslar savaslar;
    // void (*toStringOyunTuru)(struct OYUNTURU*,int);
    void (*tur)(struct OYUNTURU*,Koloni*);
    void (*yokEt)(struct OYUNTURU*);
};
typedef struct OYUNTURU* OyunTuru;

OyunTuru new_OyunTuru(int);
void tur(const OyunTuru,Koloni*);
// void toStringOyunTuru(const OyunTuru,int);
void yokEtOyunTuru(const OyunTuru);


#endif