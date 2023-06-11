#ifndef SAVASLAR_H
#define SAVASLAR_H
#include "Koloni.h"
#include "Icerik.h"


struct SAVASLAR
{
    void (*savasSonundaYapilacaklar)(struct SAVASLAR*,Koloni*,int,int,int);
    int* (*eslesme)(struct SAVASLAR*,Koloni*,int,int*,int*,int);
    void (*yokEt)(struct SAVASLAR*);
};

typedef struct SAVASLAR* Savaslar;

Savaslar new_Savaslar();
void savasSonundaYapilacaklar(const Savaslar,Koloni*,int,int,int);
int* eslesme(const Savaslar,Koloni*,int,int*,int*,int);
void yokEtSavaslar(const Savaslar);

#endif