#ifndef OLUSTUR_H
#define OLUSTUR_H
#include "Koloni.h"
#include "Icerik.h"
#include "Taktik.h"
#include "TaktikDaire.h"
#include "TaktikHilal.h"
#include "Uretim.h"
#include "Avcilik.h"
#include "Balikcilik.h"
#include "Hayvancilik.h"
#include "Tarim.h"

enum Taktikler{daire,hilal};
enum Uretimler{av,balik,hayvan,tarimm};
struct OLUSTUR
{
    Koloni* (*kolonileriOlustur)(struct OLUSTUR*,Icerik);
    Taktik (*rastgeleTaktik)(struct OLUSTUR*);
    Uretim (*rastgeleUretim)(struct OLUSTUR*);
    void (*yokEt)(struct OLUSTUR*);
};

typedef struct OLUSTUR* Olustur;

Olustur new_Olustur();
Koloni* kolonileriOlustur(const Olustur,Icerik);
Taktik rastgeleTaktik(const Olustur);
Uretim rastgeleUretim(const Olustur);
void yokEtOlustur(const Olustur);

#endif