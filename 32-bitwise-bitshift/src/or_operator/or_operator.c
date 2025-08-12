#include "or_operator.h"

void or_comparison(unsigned char a, unsigned char b){
    unsigned char result = a | b;
    printf("a | b: %02X\n", result);
    printf("a | b: %b\n", result);
}