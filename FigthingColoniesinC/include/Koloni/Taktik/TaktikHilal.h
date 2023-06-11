#ifndef TAKTIKHILAL_H
#define TAKTIKHILAL_H
#include "Taktik.h"

// Hilal taktiği etkili bir taktik odlugunda 500-1000 arası döndürecek

struct TAKTIKHILAL
{
    Taktik super;
    void (*yokEt)(struct TAKTIKHILAL*);
};

typedef struct TAKTIKHILAL* TaktikHilal;

TaktikHilal new_TaktikHilal();
int savasTaktikHilal(const TaktikHilal);
void yokEtTaktikHilal(const TaktikHilal);


#endif