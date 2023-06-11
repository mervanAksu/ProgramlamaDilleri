#include "Oyun.h"
#include "stdlib.h"
#include "stdio.h"
#include "Icerik.h"
#include "Koloni.h"
#include "Olustur.h"
#include "OnIcerikler.h"
#include "Savaslar.h"
#include "ctype.h"

Oyun new_Oyun()
{
    Oyun this=(Oyun)malloc(sizeof(struct OYUN));
    this->icerik=new_Icerik();
    
    //OyunTuru'nu burada başlatamam çünkü koloni sayısına ihtiyacım var. 

    // Koloniyi burda başlangıçta oluşturamıyorum çünkü oyun başlamadan nasıl koloni oluşsun.
    // ama koloni dizisinin adresisni bir degiskeni olarak icerisinde tutuyor
    
    this->turSayisi=0;
    this->basla=&basla;
    // this->tur=&tur;
    this->oyunBittimi=&oyunBittimi;
    this->toString=&toStringOyun;
    this->yokEt=&yokEtOyun;

    return this;
}

void basla(const Oyun this)  // istersen oyun bitince yeni bir oyun al.
{
    // char ch;
    // do
    // {
        system("cls");
        this->icerik->oku(this->icerik);
        Olustur olustur=new_Olustur();
        this->koloniler = olustur->kolonileriOlustur(olustur,this->icerik);
        this->oyunTuru=new_OyunTuru(this->icerik->parcalanmisIcerik->uzunluk);

        
        while (!this->oyunBittimi(this)) // oyun bitene kadar tur atacak
        {   
            this->toString(this); 
            this->turSayisi++;
            this->oyunTuru->tur(this->oyunTuru,this->koloniler);
        }
        this->toString(this); //son durumu yazdırdım.



        for (size_t i = 0; i < this->icerik->parcalanmisIcerik->uzunluk; i++)
        {
            this->koloniler[i]->yokEt(this->koloniler[i]);
        }
        free(this->koloniler);
        this->oyunTuru->yokEt(this->oyunTuru);
        this->oyunTuru=NULL;
        olustur->yokEt(olustur);
        olustur=NULL;
        
    //     do
    //     {
    //         printf("\n\nYeni bir oyuna başlamak ister misiniz (E/H) : ");
    //         scanf("%c",&ch);
    //         toupper(ch);
    //     } while (!(ch=='E'||ch=='H'));

    // } while (ch=='E');
}


boolean oyunBittimi(const Oyun this)
{
    int sayac=0;
    for (size_t i = 0; i < this->icerik->parcalanmisIcerik->uzunluk; i++)
    {
        if(this->koloniler[i]->populasyon>0 && this->koloniler[i]->yemek>0) 
        {
            sayac++;
            if(sayac>1) return false;
        }
    }
    return true;
}
void toStringOyun(const Oyun this) //,Koloni koloniler
{
    printf("\n------------------------------------------------------------\n");
    printf("Tur sayisi: %d \n",this->turSayisi);
    printf("Koloni\tPopulasyon\tYemekStogu\tKazanma\tKaybetme\n");
    for (size_t i = 0; i < this->icerik->parcalanmisIcerik->uzunluk; i++)
    {
        this->koloniler[i]->toString(this->koloniler[i]);
    }
    printf("\n-----------------------------------------------------------\n");
}
void yokEtOyun(const Oyun this)
{
    if(this==NULL) return;
    if(this->icerik!=NULL) this->icerik->yokEt(this->icerik);
    if(this->oyunTuru!=NULL) this->oyunTuru->yokEt(this->oyunTuru);
    free(this);
}



// void savasSonundaYapilacaklar(const Oyun this,Koloni* koloniler,int kazanan,int kaybeden,int savasSonucu)  // her turda kimin kimle savaşacağı
// // savaş sonu popülasyon azalır ve yemek stoğu düşer.
// {
//     koloniler[kaybeden]->savasCanKaybi(koloniler[kaybeden],savasSonucu);
//     int yemekkaybi=koloniler[kaybeden]->savasYemekKaybi(koloniler[kaybeden]);
//     koloniler[kazanan]->savasGanimeti(koloniler[kazanan],yemekkaybi);  // birinin kaybı birinin kazancı
// }



// int* eslesme(const Oyun this,int* eslesmeA,int* eslesmeB,int turdakiSavasSayisi) // turdaki yasanmis savas sayisini alıyorumki ekstra dönemyeyim
// // eslesmeA ve eslesmeB daha önceki eslesmeler anlamina geliyor. Tekrari önlüyorum ve rastgeleliği sağlıyorum.
// {
//     int* eslesmeler = (int*)malloc(sizeof(int)*2);
//     int devammi=1;
//     int sayi1,sayi2;
//     while (devammi)
//     {
//         do
//         {
//             sayi1=rand()%this->icerik->parcalanmisIcerik->uzunluk; // koloni sayısı kadar
//         } while (/* condition */);
//         do
//         {
//             sayi2=rand()%this->icerik->parcalanmisIcerik->uzunluk; // koloni sayısı kadar
//         } while (/* condition */);
        
//         if(sayi1==sayi2)
//         {
//             devammi=1;
//         }
//         else
//         {
//             for (int i = 0; i < turdakiSavasSayisi; i++)
//             {
//                 if((sayi1==eslesmeA[i]&&sayi2==eslesmeB[i])||(sayi2==eslesmeA[i]&&sayi1==eslesmeB[i])) 
//                 {
//                     devammi=1;
//                     break;
//                 }
//                 else 
//                 {
//                     eslesmeA[i]=sayi1;
//                     eslesmeB[i]=sayi2;
//                     eslesmeler[0]=sayi1;
//                     eslesmeler[1]=sayi2;
//                     devammi=0;
//                     break;
//                 }
//             }
//         }
//     }
    
//     return eslesmeler;
// }

// void tur(const Oyun this,int savasSayisi)  // her turdaki savaslar ve oyun sonu güncellemelerini burda yapbilrisn.
// {
//     int * eslesmeA = (int*)malloc(sizeof(int)*savasSayisi);  // kaç tane sayı(koloni) varsa o uzunlukta yer ayırdım.
//     int * eslesmeB = (int*)malloc(sizeof(int)*savasSayisi);
//     for (int i = 0; i < savasSayisi; i++)
//     {
//         eslesmeA[i]=-1;
//         eslesmeB[i]=-1;
//     }
    
//     int* eslesmeler;
//     for (size_t i = 0; i < savasSayisi; i++)  // savas sayisi kadar tekrar edecek
//     {
//         eslesmeler=this->savaslar->eslesme(this->savaslar,this->koloniler,this->icerik->parcalanmisIcerik->uzunluk,eslesmeA,eslesmeB,i); // i çünkü savaş sayısını veriyor 
//         int savasSonucu=this->koloniler[eslesmeler[0]]->savas(this->koloniler[eslesmeler[0]]) - this->koloniler[eslesmeler[1]]->savas(this->koloniler[eslesmeler[1]]);
//         if (savasSonucu>0) // eslesmeler[0]. koloni yendi
//         {
//             this->savaslar->savasSonundaYapilacaklar(this->savaslar,this->koloniler,eslesmeler[0],eslesmeler[1],savasSonucu);
//         }
//         else if(savasSonucu<0) // eslesmeler[1]. koloni yendi
//         {
//             this->savaslar->savasSonundaYapilacaklar(this->savaslar, this->koloniler, eslesmeler[1],eslesmeler[0], savasSonucu); 
//         }
//         else   // Eğerki savassonucu==0 ise popülasyonu büyük olan kazansın diye buraya girecek
//         {
//             int populasyon=this->koloniler[eslesmeler[0]]->populasyon-this->koloniler[eslesmeler[1]]->populasyon;
//             savasSonucu=100; //savasSonucu eşit olmasına rağmen kaybedenden popülasyon eksilmeli
//             if(populasyon>0) // eslesmeler[0]. koloni yendi
//             {
//                 this->savaslar->savasSonundaYapilacaklar(this->savaslar,this->koloniler,eslesmeler[0],eslesmeler[1],savasSonucu);
//             }
//             else if(populasyon<0) //eslesmeler[1]. koloni yendi
//             {
//                 this->savaslar->savasSonundaYapilacaklar(this->savaslar,this->koloniler,eslesmeler[1],eslesmeler[0],savasSonucu); 
//             }
//             else  // eğerki popülasyonlar eşitse rastgele biri kazanacak
//             {
//                 int kazanan= rand()%2;
//                 this->savaslar->savasSonundaYapilacaklar(this->savaslar,this->koloniler,eslesmeler[kazanan],eslesmeler[1-kazanan],savasSonucu); // 1-kazanan == kaybeden oluyor 0 veya 1 gelen durumda algoritma böyle oluyor, düşün anlarsın.
//             }
//         }

//     }

//     for (size_t i = 0; i < this->icerik->parcalanmisIcerik->uzunluk; i++)
//     {
//         this->koloniler[i]->ureme(this->koloniler[i]);
//         this->koloniler[i]->tuket(this->koloniler[i]);
//     }
    
    
//     free(eslesmeler);
//     free(eslesmeA);
//     free(eslesmeB);
// }