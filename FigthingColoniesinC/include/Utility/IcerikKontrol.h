#ifndef ICERIKKONTROL_H
#define ICERIKKONTROL_H
#include "OnIcerikler.h"

struct ICERIKKONTROL
{
    boolean (*sayimi)(struct ICERIKKONTROL*,char*);
    void (*yokEt)(struct ICERIKKONTROL*);
    boolean (*boslukmu)(struct ICERIKKONTROL*,char*);

};

typedef struct ICERIKKONTROL* IcerikKontrol;

IcerikKontrol new_IcerikKontrol();
boolean sayimi(const IcerikKontrol,char*);
boolean boslukmu(const IcerikKontrol,char*);
void yokEtIcerikKontrol(const IcerikKontrol);


#endif