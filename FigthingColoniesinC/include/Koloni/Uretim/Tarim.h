// 2-8
#ifndef TARIM_H
#define TARIM_H
#include "Uretim.h"
#include "stdlib.h"

struct TARIM
{
    Uretim super;
    void (*yokEt)(struct TARIM*);
};

typedef struct TARIM* Tarim;

Tarim new_Tarim();
int uretTarim(const Tarim);
void yokEtTarim(const Tarim);

#endif