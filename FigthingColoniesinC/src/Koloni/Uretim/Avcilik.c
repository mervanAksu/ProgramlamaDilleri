#include "Avcilik.h"


Avcilik new_Avcilik()
{
    Avcilik this=(Avcilik)malloc(sizeof(struct AVCILIK));
    this->super=new_Uretim();
    this->super->uret=&uretAvcilik;
    this->yokEt=&yokEtAvcilik;
    return this;
}
int uretAvcilik(const Avcilik this)
{
    return rand()%11;
}
void yokEtAvcilik(const Avcilik this)
{
    if(this==NULL) return;
    this->super->yokEt(this->super);
    free(this);
}