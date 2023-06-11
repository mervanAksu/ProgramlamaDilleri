// 0-10
#ifndef AVCILIK_H
#define AVCILIK_H

#include "Uretim.h"
#include "stdlib.h"

struct AVCILIK
{
    Uretim super;
    void (*yokEt)(struct AVCILIK*);
};

typedef struct AVCILIK* Avcilik;

Avcilik new_Avcilik();
int uretAvcilik(const Avcilik);
void yokEtAvcilik(const Avcilik);

#endif