#ifndef URETIM_H
#define URETIM_H
#include "stdlib.h"

struct URETIM
{
    
    int (*uret)();
    void (*yokEt)(struct URETIM*);
};

typedef struct URETIM* Uretim;
Uretim new_Uretim();
void yokEtUretim(const Uretim);

#endif