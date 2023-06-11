#include "TaktikHilal.h"
#include "time.h"

TaktikHilal new_TaktikHilal()
{
    TaktikHilal this=(TaktikHilal)malloc(sizeof(struct TAKTIKHILAL));
    this->super=new_Taktik();
    this->super->savas=&savasTaktikHilal;
    this->yokEt=&yokEtTaktikHilal;
    return this;
}
int savasTaktikHilal(const TaktikHilal this)
{
    return rand()%501+200;
}
void yokEtTaktikHilal(const TaktikHilal this)
{
    if(this == NULL) return;
    this->super->yokEt(this->super);
    free(this);
}