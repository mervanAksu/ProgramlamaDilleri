#ifndef ICERIK_H
#define ICERIK_H

#include "IcerikParcala.h"
#include "Dizi.h"

struct ICERIK
{
    char icerik[800];
    // char* icerik;
    Dizi parcalanmisIcerik;
    IcerikParcala icerikParcala;

    void (*oku)(struct ICERIK*);
    void (*yokEt)(struct ICERIK*);

};

typedef struct ICERIK* Icerik;

Icerik new_Icerik(); 
void oku(const Icerik);
void yokEtIcerik(const Icerik);




#endif