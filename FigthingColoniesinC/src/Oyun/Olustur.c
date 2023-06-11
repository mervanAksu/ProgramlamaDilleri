#include "Olustur.h"
#include "stdlib.h"
#include "stdio.h"

Olustur new_Olustur()
{
    Olustur this=(Olustur)malloc(sizeof(struct OLUSTUR));
    this->kolonileriOlustur=&kolonileriOlustur;
    this->rastgeleTaktik=&rastgeleTaktik;
    this->rastgeleUretim=&rastgeleUretim;
    this->yokEt=&yokEtOlustur;
}
Koloni* kolonileriOlustur(const Olustur this ,Icerik icerik)
{
    Koloni* koloniler=(Koloni*)malloc(sizeof(Koloni) * icerik->parcalanmisIcerik->uzunluk);
    for (size_t i = 0; i < icerik->parcalanmisIcerik->uzunluk; i++)
    {
        Taktik taktik=this->rastgeleTaktik(this);
        Uretim uretim=this->rastgeleUretim(this);
        koloniler[i]=new_Koloni(icerik->parcalanmisIcerik->sayilar[i],taktik,uretim); // parcalanmis icerik icerisinde bize verilen sayi array'in elemanlarını tutuyor.
    }
    return koloniler;
}
Taktik rastgeleTaktik(const Olustur this)
{
    int rastgeleSayi=rand()%2;
    Taktik taktik;
    switch (rastgeleSayi)
    {
    case daire:
        taktik=(Taktik)(new_TaktikDaire()->super);
        break;
    case hilal:
        taktik=(Taktik)(new_TaktikHilal()->super);
        break;
    default:
        break;
    }
    return taktik;
}
Uretim rastgeleUretim(const Olustur this)
{
    int rastgeleSayi=rand()%4;
    Uretim uretim;
    switch (rastgeleSayi)
    {
    case av:
        uretim=(Uretim)(new_Avcilik()->super);
        break;
    case balik:
        uretim=(Uretim)(new_Balikcilik()->super);
        break;
    case hayvan:
        uretim=(Uretim)(new_Hayvancilik()->super);
        break;
    case tarimm:
        uretim=(Uretim)(new_Tarim()->super);
        break;
    default:
        break;
    }
    return uretim;
}
void yokEtOlustur(const Olustur this)
{
    if(this == NULL) return;
    free(this);
}