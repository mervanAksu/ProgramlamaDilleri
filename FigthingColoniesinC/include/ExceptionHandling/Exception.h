#ifndef EXCEPTION_H 
#define EXCEPTION_H

#include "Try_catch.h"

struct EXCEPTION
{  
    char* message;
    char* (*getMessage)(struct EXCEPTION*);
    void (*yokEt)(struct EXCEPTION*);
};
typedef struct EXCEPTION* Exception;

Exception new_Exception(char*);
char* getMessage(const Exception);
void yokEtException(const Exception);

#endif