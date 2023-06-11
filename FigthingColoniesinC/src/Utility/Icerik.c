#include "Icerik.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

Icerik new_Icerik()
{
    Icerik this=(Icerik)malloc(sizeof(struct ICERIK));
    this->parcalanmisIcerik=NULL;
    this->icerikParcala=new_IcerikParcala();
    this->oku=&oku;
    this->yokEt=&yokEtIcerik;
    return this;
}
void oku(const Icerik this)
{
    if(this->parcalanmisIcerik!=NULL) 
    {
        this->parcalanmisIcerik->yokEt(this->parcalanmisIcerik);
        this->parcalanmisIcerik=NULL;
    }
    do
    {
        printf("Bir sayi dizisi giriniz: ");
        fgets(this->icerik,800,stdin);  // pointker veya char array olsun farketmez, fgets fonksiyonu sonuna bir tane \n işareti koyuyor
        // scanf("%[^\n]%*c",this->icerik);  // patlarsa icerik'i char dizisi yapıp yukarıdaki fonksiyonu kullan
        try
        {
            this->parcalanmisIcerik = this->icerikParcala->parcala(this->icerikParcala,this->icerik);
        }
        catch
        {
            printf("%s\n",this->icerikParcala->exception->getMessage(this->icerikParcala->exception));
            if(this->parcalanmisIcerik!=NULL) this->parcalanmisIcerik->yokEt(this->parcalanmisIcerik);
            this->parcalanmisIcerik=NULL;
        }
        tryEnd;      
    } while (this->parcalanmisIcerik==NULL);
}
void yokEtIcerik(const Icerik this)
{
    if(this==NULL) return;
    this->icerikParcala->yokEt(this->icerikParcala);
    if(this->parcalanmisIcerik!=NULL) this->parcalanmisIcerik->yokEt(this->parcalanmisIcerik);
    free(this);
}