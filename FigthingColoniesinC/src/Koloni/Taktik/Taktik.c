#include "Taktik.h"
#include "time.h"

Taktik new_Taktik()
{
    Taktik this=(Taktik)malloc(sizeof(struct TAKTIK));
    this->yokEt=&yokEtTaktik;
    return this;
}
void yokEtTaktik(const Taktik this)
{
    if(this== NULL) return;
    free(this);
}