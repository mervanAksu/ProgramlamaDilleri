#include "Uretim.h"


Uretim new_Uretim()
{
    Uretim this=(Uretim)malloc(sizeof(struct URETIM));
    this->yokEt=&yokEtUretim;
    return this;
}
void yokEtUretim(const Uretim this)
{
    if(this==NULL) return;
    free(this);
}