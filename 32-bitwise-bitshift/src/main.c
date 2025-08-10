#include <stdio.h>
#include <stdlib.h>
#include "and_operator.h"

int main(void){
    unsigned char a = 0b00001111; // 15 decimal
    unsigned char b = 0b00101010; // 42 decimal
    and_comparison(a, b);
    return EXIT_SUCCESS;
}