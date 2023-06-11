#include "stdlib.h"
#include "Exception.h"


Exception new_Exception(char* message)
{
    Exception this=(Exception)malloc(sizeof(struct EXCEPTION));
    this->message=message;
    this->getMessage=&getMessage;
    this->yokEt=&yokEtException;
    return this;
}
char* getMessage(const Exception this)
{
    return this->message;
}
void yokEtException(const Exception this) // burda mesajı silmeye gerek yok cunku malloc kullanılmayan hicbir sey silinemez
// string literal olarak geldi message
{
    if(this==NULL) return;
    free(this);
}
