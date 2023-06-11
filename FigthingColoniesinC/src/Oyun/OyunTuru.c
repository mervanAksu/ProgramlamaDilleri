#include "OyunTuru.h"
#include "stdlib.h"
#include "stdio.h"

OyunTuru new_OyunTuru(int koloniSayisi)
{
    OyunTuru this=(OyunTuru)malloc(sizeof(struct OYUNTURU));
    this->koloniSayisi=koloniSayisi;
    this->savaslar=new_Savaslar();

    // this->toStringOyunTuru=&toStringOyunTuru;
    this->tur=&tur;
    this->yokEt=&yokEtOyunTuru;
    return this;
}
void tur(const OyunTuru this,Koloni* koloniler)
{
    // başlangıçta kesinlikle 1 savaş olacak zaten tur() fonksiyonu çalıştıysa  bu demektirki
    // oyun.c basla() fonksiyonundaki algoritmada canli en az 2 tane koloni var, var ki bu fonksiyondayız. 
    int savasSayisi=0; 
    int olenKoleniIndex;
    int yasayanKoloniSayisiOnceki=0;
    int yasayanKoloniSayisiSonraki=0;
    
    for (size_t i = 0; i < this->koloniSayisi; i++)
    {   
        if(koloniler[i]->yasiyormu(koloniler[i])) 
        {
            yasayanKoloniSayisiOnceki++; 
            savasSayisi+=yasayanKoloniSayisiOnceki;                       
        } 
    }
    savasSayisi-=yasayanKoloniSayisiOnceki;

    // savasSayisi=yasayanKoloniSayisiOnceki*(yasayanKoloniSayisiOnceki-1); // kombinasyon koloni     koloni sayısının 2 ile olan permütasyonu
    // savasSayisi=savasSayisi/2;
    
    this->eslesmeA = (int*)malloc(sizeof(int)*savasSayisi+1);  // savas sayisi kadar yer ayırdım. +1 olmasına gerek yok ama denemeye üşendim [] sembolü çalışıyor eminim, ama riske atmadım. savassayisi 0 olur diye +1 yaptım.
    this->eslesmeB = (int*)malloc(sizeof(int)*savasSayisi+1);

    for (size_t i = 0; i < savasSayisi; i++)
    {
        this->eslesmeA[i]=-1;
        this->eslesmeB[i]=-1;
    }

    int* eslesmeler; 
    for (size_t i = 0; i < savasSayisi; i++)  // savas sayisi kadar tekrar edecek
    {
        eslesmeler=this->savaslar->eslesme(this->savaslar,koloniler,this->koloniSayisi,this->eslesmeA,this->eslesmeB,i); // i çünkü savaş sayısını veriyor 
        int savasSonucu=koloniler[eslesmeler[0]]->savas(koloniler[eslesmeler[0]]) - koloniler[eslesmeler[1]]->savas(koloniler[eslesmeler[1]]);
        if (savasSonucu>0) // eslesmeler[0]. koloni yendi
        {
            this->savaslar->savasSonundaYapilacaklar(this->savaslar,koloniler,eslesmeler[0],eslesmeler[1],savasSonucu);
            
        }
        else if(savasSonucu<0) // eslesmeler[1]. koloni yendi
        {
            this->savaslar->savasSonundaYapilacaklar(this->savaslar, koloniler, eslesmeler[1],eslesmeler[0], savasSonucu); 
        }
        else   // Eğerki savassonucu==0 ise popülasyonu büyük olan kazansın diye buraya girecek
        {
            long int populasyon=koloniler[eslesmeler[0]]->populasyon-koloniler[eslesmeler[1]]->populasyon;
            savasSonucu=100; //savasSonucu eşit olmasına rağmen kaybedenden popülasyon eksilmeli
            if(populasyon>0) // eslesmeler[0]. koloni yendi
            {
                this->savaslar->savasSonundaYapilacaklar(this->savaslar,koloniler,eslesmeler[0],eslesmeler[1],savasSonucu);
            }
            else if(populasyon<0) //eslesmeler[1]. koloni yendi
            {
                this->savaslar->savasSonundaYapilacaklar(this->savaslar,koloniler,eslesmeler[1],eslesmeler[0],savasSonucu); 
            }
            else  // eğerki popülasyonlar eşitse rastgele biri kazanacak
            {
                int kazanan= rand()%2;
                this->savaslar->savasSonundaYapilacaklar(this->savaslar,koloniler,eslesmeler[kazanan],eslesmeler[1-kazanan],savasSonucu); // 1-kazanan == kaybeden oluyor 0 veya 1 gelen durumda algoritma böyle oluyor, düşün anlarsın.
            }
        }

        // buradan, üstteki for döngüsünün aşağıdaki bitişine kadar olan kodlar tamamen
        // turdaki savaslar sırasında ölen kolonileri savaştan çıkarmak için yapıldı
        // mantık olarak yukarıdaki eslesmeler değişkeni bana ölen kolonileri vermiyor.
        // ancak eğerki ben fazladan eslesme() fonksiyonuna sokarsam sonsuz döngüye giriyor.
        // çünkü kombinasyonda 5 koloniden dolayı 10 eşleşme olacaksa ve herhangi biri ölüp
        // koloni sayısı 4 e düştüyse eşleşmeyi bulamıyor.
        // bu yüzden benim eslesme() fonksiyonuna sokamam gerek.
        // alttaki kodların tamamıda bu savasSayisi'ni ölen koloni sayısını hesaba katıp güncellemek üzerine. 
        savasSayisi=0;
        yasayanKoloniSayisiSonraki=0;
        for (size_t j = 0; j < this->koloniSayisi; j++) // yeniden yasayan kolonileri hesaplıyorum
        {   
            if(koloniler[j]->yasiyormu(koloniler[j])) 
            {
                yasayanKoloniSayisiSonraki++; 
                savasSayisi+=yasayanKoloniSayisiSonraki;                       
            } 
            else if(this->eslesmeA[i]==j||this->eslesmeB[i]==j)   // son ölne koloniyi bulsun bana herhangi bir ölen koleniyi değil.
            {
                olenKoleniIndex=j;
            }
            
        }
        savasSayisi-=yasayanKoloniSayisiSonraki;  // kombinasyonu toplatarak aldım  eleman sayısının bir kesiğinin ardışık toplamıyla bulunuyor ben ekstra eleman sayısınıda toplamıştım onu cıkardım
        
        if (yasayanKoloniSayisiOnceki!=yasayanKoloniSayisiSonraki)  // zaten her tur kontrol ediyorum eğer bu tur öldüyse 1 azalmıştır. azalma varsa olasılıklar güncellenmeli.
        {
            for (size_t j = 0; j < i+1; j++) // i+1 kadar savas oldugundan yani eslesme oldugundan okadar eslesmelerde aradım
            {
                if(this->eslesmeA[j]==olenKoleniIndex || this->eslesmeB[j]==olenKoleniIndex)  // olen kolenin dahil oldugu savasları topluyorum burda birde bi yukarda guncel koloni sayısının olasılığını hesaplamıştım.
                {
                    savasSayisi++; // olen koleninin bu turda dahil oldugu savasları topluyorum devam etmeden guncel yapılabilecek savas sayısını bulmak için
                    
                }
            }
        }
        yasayanKoloniSayisiOnceki=yasayanKoloniSayisiSonraki;
        free(eslesmeler);
    }

    for (size_t i = 0; i < this->koloniSayisi; i++)
    {
        koloniler[i]->ureme(koloniler[i]);
        koloniler[i]->tuket(koloniler[i]);
    }
    
    
    free(this->eslesmeA);
    free(this->eslesmeB);
}

void yokEtOyunTuru(const OyunTuru this)
{
    if(this==NULL) return;
    this->savaslar->yokEt(this->savaslar);
    free(this);
}


// void toStringOyunTuru(const OyunTuru this,int turSayisi)
// {
//     printf("\n");
//     printf("------------------------------------------------------------\n");
//     printf("Tur sayisi: %d\n",turSayisi);
//     printf("Koloni\tPopulasyon\tYemekStogu\tKazanma\tKaybetme\n");
//     for (size_t i = 0; i < this->koloniSayisi; i++)
//     {
//         this->koloniler[i]->toString(this->koloniler[i]);
//     }
//     printf("\n-----------------------------------------------------------\n");
//     // printf("\n");
// }