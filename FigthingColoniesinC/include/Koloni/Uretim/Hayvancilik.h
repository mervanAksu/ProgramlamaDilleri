
// 3-8
#ifndef HAYVANCILIK_H
#define HAYVANCILIK_H
#include "Uretim.h"
#include "stdlib.h"

struct HAYVANCILIK
{
    Uretim super;
    void (*yokEt)(struct HAYVANCILIK*);
};

typedef struct HAYVANCILIK* Hayvancilik;

Hayvancilik new_Hayvancilik();
int uretHayvancilik(const Hayvancilik);
void yokEtHayvancilik(const Hayvancilik);

#endif