#include "Balikcilik.h"

Balikcilik new_Balikcilik()
{
    Balikcilik this=(Balikcilik)malloc(sizeof(struct BALIKCILIK));
    this->super=new_Uretim();
    this->super->uret=&uretBalikcilik;
    this->yokEt=&yokEtBalikcilik;
    return this;
}
int uretBalikcilik(const Balikcilik this) 
{
    return rand()%5+3; //3-7
}
void yokEtBalikcilik(const Balikcilik this)
{
    if(this==NULL) return;
    this->super->yokEt(this->super);
    free(this);
}
