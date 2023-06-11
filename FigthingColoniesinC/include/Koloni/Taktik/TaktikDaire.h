#ifndef TAKTIKDAIRE_H
#define TAKTIKDAIRE_H
#include "Taktik.h"

// Hilal taktiği etkili bir taktik odlugunda 500-1000 arası döndürecek

struct TAKTIKDAIRE
{
    Taktik super;
    void (*yokEt)(struct TAKTIKDAIRE*);
};

typedef struct TAKTIKDAIRE* TaktikDaire;

TaktikDaire new_TaktikDaire();
int savasTaktikDaire(const TaktikDaire);
void yokEtTaktikDaire(const TaktikDaire);


#endif