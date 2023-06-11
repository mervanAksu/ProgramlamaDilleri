#include "IcerikParcala.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "Dizi.h"

IcerikParcala new_IcerikParcala()
{
    IcerikParcala this=(IcerikParcala)malloc(sizeof(struct ICERIKPARCALA));
    this->kontrol=new_IcerikKontrol(); // Association bağlantısı, Kalıtım değil bilerek yaptım
    this->exception=new_Exception("Girilen ifadelerin hepsi sayi olmali\n");
    this->parcala=&parcala;
    this->substring=&substring;
    this->yokEt=&yokEtIcerikParcala;
    return this;
}
char* substring(const IcerikParcala this,char* yazi,int position, int length)
{
    char* substr=(char*)malloc(sizeof(char)*length+1);  // sondaki \0 karakteri icin
    int i=0;
    while(i<length)
    {
        substr[i]=yazi[position+i];  // karakter karakter assign ediyorum
        i++;
    }
    substr[length]='\0';
    return substr;
}
// cagrılan yerde free'lenmesi gerekir.
Dizi parcala(const IcerikParcala this,char* yazi)  // egerki girilen ifadede sayi ve bosluktan baska bir sey varsa throw'luyor. 
{
    Dizi dizi=new_Dizi();
    char* sayi;
    int uzunluk=strlen(yazi); // sondaki bitis karakterine göre de okuyacagim  Eğerki icerik fgets ile okunduysa +1 yapmana gerek yok sondaki karakteri \n karakterini sayıyor.
    int sonSayiIndex=0;
    dizi->sayilar =(int*)malloc(sizeof(int)*uzunluk);
    dizi->uzunluk=0;
    for (int i = 0; i < uzunluk; i++)
    {
        if(yazi[i]==' '|| yazi[i]=='\n') // bosluga gore ayırıyorum.  Eğerki char * ile okuduysan \0 yap \n yerine scanf sonuna \0 koyuyor fgets sonuna \n koyuyor.
        {   
            sayi=(char*)malloc(sizeof(char)*(i-sonSayiIndex+1)); // boslugu buldugunda o kadarlık yer ayırıyorum.
            int k=0;
            for (int j = sonSayiIndex; j < i; j++) // son sayıyı buldugu yerden yeni sayiyi buldugu yere kadar
            {
                if(yazi[j]==' ') continue;
                sayi[k]=yazi[j];
                sonSayiIndex=i+1;
                k++;
            }
            sayi[k]='\0';
            if((strcmp(sayi,"")))  // burayı bende anlamadım ama böyle düzgün calisiyor ! koymam gerekir diye düsünüyorum ama böyle calisiyor.
            {
                if(!(this->kontrol->sayimi(this->kontrol,sayi))) throw;
                dizi->sayilar[dizi->uzunluk]=atoi(sayi);
                dizi->uzunluk++;
            }
            free(sayi);
        }
    }

    // if(dizi->uzunluk==0) throw; // sadece bosluk girilirse diye onlem aldım ancak garip bir yavaslık yapıyor kodda.


    return dizi;

    // char str[]=yazi;
    // int* sayilar=(int*)malloc(sizeof(int)*strlen(yazi));
    // char* sayi="";
    // int i = 0;
    // while(1)
    // {

    //     sayi= strtok(str," "); // icerisine verdigin parametre char array olmalı. char* kabul etmiyor.
    //     int uzunluk = strlen(sayi);
    //     sayilar[i]=atoi(sayi);
    // }
}
void yokEtIcerikParcala(const IcerikParcala this)
{
    if(this==NULL) return;
    this->kontrol->yokEt(this->kontrol);
    this->exception->yokEt(this->exception);
    free(this);

}