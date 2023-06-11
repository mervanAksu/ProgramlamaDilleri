#include "Hayvancilik.h"

Hayvancilik new_Hayvancilik()
{
    Hayvancilik this=(Hayvancilik)malloc(sizeof(struct HAYVANCILIK));
    this->super=new_Uretim();
    this->super->uret=&uretHayvancilik;
    this->yokEt=&yokEtHayvancilik;
    return this;
}
int uretHayvancilik(const Hayvancilik this)
{
    return rand()%7+2;
}
void yokEtHayvancilik(const Hayvancilik this)
{
    if(this==NULL) return;
    this->super->yokEt(this->super);
    free(this);
}