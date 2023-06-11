#include "Savaslar.h"
#include "stdlib.h"
#include "stdio.h"
#include "math.h"


Savaslar new_Savaslar()
{
    Savaslar this=(Savaslar)malloc(sizeof(struct SAVASLAR));
    this->savasSonundaYapilacaklar=&savasSonundaYapilacaklar;
    this->eslesme=&eslesme;
    this->yokEt=&yokEtSavaslar;
    return this;    
}


// savaş sonu popülasyon azalır ve yemek stoğu düşer. kazanana ve kaybedene +1'leri eklenir.
void savasSonundaYapilacaklar(const Savaslar this,Koloni* koloniler,int kazanan,int kaybeden,int savasSonucu) // her turdaki savaş
{
    savasSonucu=abs(savasSonucu);
    koloniler[kaybeden]->savasCanKaybi(koloniler[kaybeden],savasSonucu);
    long int yemekkaybi=koloniler[kaybeden]->savasYemekKaybi(koloniler[kaybeden]);
    koloniler[kazanan]->savasGanimeti(koloniler[kazanan],yemekkaybi);  // birinin kaybı birinin kazancı
    koloniler[kazanan]->kazanma++;
    koloniler[kaybeden]->kaybetme++;
}


int* eslesme(const Savaslar this,Koloni* koloniler,int koloniSayisi,int* eslesmeA,int* eslesmeB,int turdakiSavasSayisi) // turdaki yasanmis savas sayisini alıyorumki ekstra dönemyeyim
{
    // eslesmeA ve eslesmeB daha önceki eslesmeler anlamina geliyor. Tekrari önlüyorum ve rastgeleliği sağlıyorum.
    int* eslesmeler = (int*)malloc(sizeof(int)*2);
    int devammi;
    int sayi1,sayi2;
    
    do
    {
        devammi=0;
        do
        {
            sayi1=rand()%koloniSayisi; // olen koloninin sayısını döndüremiyor
        } while (!koloniler[sayi1]->yasiyormu(koloniler[sayi1]));

        do
        {
            sayi2=rand()%koloniSayisi; // olen koloninin sayısını döndüremiyor
        } while (!koloniler[sayi2]->yasiyormu(koloniler[sayi2]));

        if(sayi1==sayi2)
        {
            devammi=1;
        }
        else
        {
            int i;
            for (i = 0; i < turdakiSavasSayisi; i++)
            {
                if((sayi1==eslesmeA[i]&&sayi2==eslesmeB[i])||(sayi2==eslesmeA[i]&&sayi1==eslesmeB[i])) 
                {
                    devammi=1;
                    break;
                }
            }
            if(devammi==0)
            {
                eslesmeA[i]=sayi1;
                eslesmeB[i]=sayi2;
                eslesmeler[0]=sayi1;
                eslesmeler[1]=sayi2;
                devammi=0;
            }
        }
    }while (devammi);

    return eslesmeler;
}
void yokEtSavaslar(const Savaslar this)
{
    if(this==NULL)return;
    free(this);
}