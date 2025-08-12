#include <stdio.h>
#include <stdlib.h>
#include "and_operator.h"
#include "or_operator.h"



void xor_comparison(unsigned char a, unsigned char b){
    printf("a ^ b: %02X\n", a ^ b);
    printf("a ^ b: %b\n", a ^ b);
}

void not_inverter(unsigned char a){
    printf("NOT a: %02X\n", ~a);
    printf("NOT a: %b\n", ~a);
}

void shift_left(void){
    int a = 3;
    int value = a << 2; // Desloca todos os bits para a esquerda (multiplica por 2ⁿ)
    printf("shift left a << value: %d\n", value); //Desloca todos os bits para a direita (divide por 2ⁿ, arredonda para baixo)
}

void shift_right(void){
    int a = 100;
    int value = a >> 2;
    printf("shift right a >> value: %d\n", value);
}


int main(void){
    unsigned char a = 0b00001111; // 15 decimal
    unsigned char b = 0b00101010; // 42 decimal
    and_comparison(a, b);
    or_comparison(a, b);
    xor_comparison(a, b);
    not_inverter(a);
    shift_left();
    shift_right();

    return EXIT_SUCCESS;
}


// printf("a << 1: %02X\n", a << 1); // 1E
// printf("b >> 2: %02X\n", b >> 2); // 0A