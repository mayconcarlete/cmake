#include "and_operator.h"
#include <stdlib.h>
#include <stdio.h>

void and_comparison(unsigned char a, unsigned char b){
    unsigned char result = a & b;
    printf("a & b: %02X\n");        
}