
// 3-7
#ifndef BALIKCILIK_H
#define BALIKCILIK_H

#include "Uretim.h"
#include "stdlib.h"

struct BALIKCILIK
{
    Uretim super;
    void (*yokEt)(struct BALIKCILIK*);
};

typedef struct BALIKCILIK* Balikcilik;

Balikcilik new_Balikcilik();
int uretBalikcilik(const Balikcilik);
void yokEtBalikcilik(const Balikcilik);

#endif