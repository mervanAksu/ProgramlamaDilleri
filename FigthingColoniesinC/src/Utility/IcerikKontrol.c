#include "IcerikKontrol.h"
#include "string.h"
#include "stdlib.h"
#include "stdio.h"
#include "ctype.h"


IcerikKontrol new_IcerikKontrol()
{
    IcerikKontrol this=(IcerikKontrol)malloc(sizeof(struct ICERIKKONTROL));
    this->sayimi=&sayimi;
    this->yokEt=&yokEtIcerikKontrol;
    this->boslukmu=&boslukmu;
    return this;
}
boolean sayimi(const IcerikKontrol this ,char* yazi) // parcalanmis parca sayi geliyor sayi mi diye kontrol ediliyor.
{
    for (size_t i = 0; yazi[i]!='\0'; i++) // normalde olmaması gerekir ama burda \0 karakterini dahil ediyor. Cunku ben dahil etmisim mb
    {
        if(!(isdigit(yazi[i]))) return false;
    }
    
    return true;
}
boolean boslukmu(const IcerikKontrol this,char* yazi)
{
    for (int i = 0; yazi[i]!='\0'; i++) 
    {
        if(isspace(yazi[i])) return true;
    }
    return false;
}
void yokEtIcerikKontrol(const IcerikKontrol this)
{
    if(this==NULL) return;
    free(this);
}