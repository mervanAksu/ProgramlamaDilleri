#include "Tarim.h"

Tarim new_Tarim()
{
    Tarim this=(Tarim)malloc(sizeof(struct TARIM));
    this->super=new_Uretim();
    this->super->uret=&uretTarim;
    this->yokEt=&yokEtTarim;
    return this;
}
int uretTarim(const Tarim this)
{
    return rand()%7+2;
}
void yokEtTarim(const Tarim this)
{
    if(this==NULL) return;
    this->super->yokEt(this->super);
    free(this);
}