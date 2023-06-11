#ifndef ICERIKPARCALA_H
#define ICERIKPARCALA_H

#include "IcerikKontrol.h"
#include "Exception.h"
#include "Dizi.h"

struct ICERIKPARCALA
{
    IcerikKontrol kontrol;
    Exception exception;
    Dizi (*parcala)(struct ICERIKPARCALA*,char*);
    char* (*substring)(struct ICERIKPARCALA*,char*,int,int);
    void (*yokEt)(struct ICERIKPARCALA*);

};

typedef struct ICERIKPARCALA* IcerikParcala;

IcerikParcala new_IcerikParcala();
char* substring(const IcerikParcala this,char* yazi,int position, int length);
Dizi parcala(const IcerikParcala,char*);
void yokEtIcerikParcala(const IcerikParcala);


#endif