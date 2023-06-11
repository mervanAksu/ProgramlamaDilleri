#ifndef TRY_CATCH_H
#define TRY_CATCH_H

#include "setjmp.h"

jmp_buf jumper;

#define try do{ if(!setjmp(jumper)){
#define catch } else {
#define tryEnd }}while(0)
#define throw longjmp(jumper,1)

#endif