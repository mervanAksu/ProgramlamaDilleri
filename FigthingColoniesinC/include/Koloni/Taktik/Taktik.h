#ifndef TAKTIK_H
#define TAKTIK_H
#include "stdlib.h"

// 


// abstract class 
// savas fonksiyonu sanal fonksiyon oldugundan nesne olusturmamalısın.

struct TAKTIK
{
    
    int (*savas)(); // aslında burda parametrelerin boş olmasının sebebi parametre almaması değil ne aldığnı bilmememiz. Yani tanımladığım yerde parametre alabilir.
    void (*yokEt)(struct TAKTIK*);
};

typedef struct TAKTIK* Taktik;

Taktik new_Taktik();
void yokEtTaktik(const Taktik);


#endif