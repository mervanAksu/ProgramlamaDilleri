#ifndef OYUN_H
#define OYUN_H
#include "Koloni.h"
#include "Icerik.h"
#include "Savaslar.h"
#include "OyunTuru.h"


// normalde koloni ve icerigi icinde field olarak barındırsa daha iyi olacakmış ama baştan öyle kurgulamammıştım sonrada değiştirmedim.
// istersen değiştirebilirsin.
struct OYUN
{
    Icerik icerik;
    Koloni* koloniler;
    OyunTuru oyunTuru;

    int turSayisi;

    void (*basla)(struct OYUN*);
    // void (*savasSonundaYapilacaklar)(struct OYUN*,Koloni*,int,int,int);
    // int* (*eslesme)(struct OYUN*,int*,int*,int);
    // void (*tur)(struct OYUN*,int);
  
    boolean (*oyunBittimi)(struct OYUN*);
    void (*toString)(struct OYUN*);  // ,Koloni
    void (*yokEt)(struct OYUN*);
};

typedef struct OYUN* Oyun;

Oyun new_Oyun();
void basla(const Oyun);
// void savasSonundaYapilacaklar(const Oyun,Koloni*,int,int,int);
// void tur(const Oyun,int);
// int* eslesme(const Oyun,int*,int*,int);
boolean oyunBittimi(const Oyun);
void toStringOyun(const Oyun);// ,Koloni
void yokEtOyun(const Oyun);


#endif