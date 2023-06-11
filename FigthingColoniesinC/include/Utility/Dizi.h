#ifndef DIZI_H
#define DIZI_H

struct DIZI
{
    int* sayilar;
    int uzunluk;
    void (*yokEt)(struct DIZI*);

};
typedef struct DIZI* Dizi;

Dizi new_Dizi();
void yokEtDizi(const Dizi);

#endif