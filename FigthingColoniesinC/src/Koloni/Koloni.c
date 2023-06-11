#include "Koloni.h"
#include "stdlib.h"
#include "stdio.h"
#include "math.h"
#include "stdio.h"
#include "OnIcerikler.h"


// HAta olabilecek durumlar:
// Eğerki taktik'i ve üretimi parametre olarak veren silerse sıkıntı büyük bu yüzden onların adresini almak yerine baska bir sey dene 

Koloni new_Koloni(int populasyon,Taktik taktik,Uretim uretim)  
{
    Koloni this=(Koloni)malloc(sizeof(struct KOLONI));
    this->taktik=taktik;  // polymorphism seklinde olması bekleniyor.
    this->uretim=uretim;  // polymorphism seklinde olması bekleniyor.
    this->populasyon=populasyon;
    this->yemek=populasyon*populasyon;
    this->sembol=(char)(rand()%444)+57;
    this->kazanma=0;
    this->kaybetme=0;


    this->uret=&uretKoloni;
    this->savas=&savasKoloni;
    this->tuket=&tuketKoloni;
    this->ureme=&ureme;
    this->yasiyormu=&yasiyormu;
    this->savasYemekKaybi=&savasYemekKaybi;
    this->savasCanKaybi=&savasCanKaybi;
    this->savasGanimeti=&savasGanimeti;
    this->toString=&toStringKoloni;
    this->yokEt=&yokEtKoloni;

    return this;
}
int savasKoloni(const Koloni this) // taktigin savas fonksiyonunu cagir burada.
{
    return this->taktik->savas(this->taktik);
}
void uretKoloni(const Koloni this) // her tur sonu uretim yapılıcna cagırılacak
{
    int yemekArtisi= this->uretim->uret(this->uretim);
    this->yemek+=yemekArtisi;
}
void tuketKoloni(const Koloni this) // el sonu tuketim yapılınca cagıraln fonksiyon olacak
{
    long int yemekTuketimi = this->populasyon*2;
    this->yemek-=yemekTuketimi;
}
int savasYemekKaybi(const Koloni this)
{
    long int yemekKaybi=this->yemek/10;
    this->yemek-=yemekKaybi;
    return yemekKaybi;
}
void savasGanimeti(const Koloni this,int yemekMiktari)
{
    this->yemek+=yemekMiktari;
}
void savasCanKaybi(const Koloni this,int savasSonucu)
{
    double canKaybetmeOrani=(double)savasSonucu/1000;
    long int canKaybi=this->populasyon*canKaybetmeOrani;
    if(canKaybi<2) canKaybi=2;
    this->populasyon-=canKaybi;

}
void ureme(const Koloni this)
{
    this->populasyon+=this->populasyon/5;
}
boolean yasiyormu(const Koloni this)
{
    boolean bool=(this->populasyon>0 && this->yemek>0) ? true : false;
    return bool;
}
void toStringKoloni(const Koloni this)
{   
    if(this->yasiyormu(this))
    {
        printf("%3c %9d %17d %13d %6d\n",this->sembol,this->populasyon,this->yemek,this->kazanma,this->kaybetme);
    }
    else
    {
        printf("%3c %9s %17s %13s %6s\n",this->sembol,"--","--","--","--");
    }
}

void yokEtKoloni(const Koloni this)
{
    if(this == NULL) return;
    this->taktik->yokEt(this->taktik);
    this->uretim->yokEt(this->uretim);
    free(this);
}