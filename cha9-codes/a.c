#include "b.c"

int f(int i){
    extern int v;
    
    i=i+v;
    
    return i;
}