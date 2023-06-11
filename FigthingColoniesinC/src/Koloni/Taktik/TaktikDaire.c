#include "TaktikDaire.h"
#include "time.h"

TaktikDaire new_TaktikDaire()
{
    TaktikDaire this=(TaktikDaire)malloc(sizeof(struct TAKTIKDAIRE));
    this->super=new_Taktik();
    this->super->savas=&savasTaktikDaire;
    this->yokEt=&yokEtTaktikDaire;
    return this;
}
int savasTaktikDaire(const TaktikDaire this)
{
    return rand()%801+200;
}
void yokEtTaktikDaire(const TaktikDaire this)
{
    if(this == NULL) return;
    this->super->yokEt(this->super);
    free(this);
}