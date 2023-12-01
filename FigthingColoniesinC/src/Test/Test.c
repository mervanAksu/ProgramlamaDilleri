#include "stdio.h"
#include "stdlib.h"
#include "Try_catch.h"
#include "string.h"
#include "Oyun.h"
#include "time.h"
#include "Icerik.h"
#include "OnIcerikler.h"


// Yapilan Degisiklik
typedef struct YAPI Yapi;

int main()
{
    srand(time(0));
    
    Oyun oyun=new_Oyun();
    oyun->basla(oyun);
    oyun->yokEt(oyun);
    
    return 0;
}

