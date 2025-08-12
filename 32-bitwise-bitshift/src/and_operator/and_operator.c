#include "and_operator.h"
#include <stdlib.h>
#include <stdio.h>

/*
    AND - &
    Mantém 1 (on) apenas onde ambos os bits são 1
     * 0b00001111
     *          &
     * 0b00101010
     * ----------
     * 0b00001010
*/

void and_comparison(unsigned char a, unsigned char b){
    unsigned char result = a & b;
    printf("a & b: %X\n", result);       
    printf("a & b: %b\n", result);
}