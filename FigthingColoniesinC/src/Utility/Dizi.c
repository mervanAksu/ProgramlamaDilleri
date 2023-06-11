#include "Dizi.h"
#include "stdlib.h"

Dizi new_Dizi()
{
    Dizi this=(Dizi)malloc(sizeof(struct DIZI));
    this->yokEt=&yokEtDizi;
    return this;
}
void yokEtDizi(const Dizi this)
{
    if(this==NULL) return;
    if(this->sayilar!=NULL) free(this->sayilar);
    free(this);
}