#include <stdio.h>
#include <stdlib.h>
#include "and_operator.h"
#include "or_operator.h"

#define READ  0x01 // 0b00000001 || (1 << 0)
#define WRITE 0x02 // 0b00000010 || (1 << 1)
#define EXEC  0x04 // 0b00000100 || (1 << 2)


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

    // permission test
    unsigned char permissions = 0x00; // 0
    permissions |= READ;
    permissions |= WRITE;
    printf("Permissions enabled: %b\n", permissions);

    if(permissions & READ){
        printf("Tem leitura!\n");
    }
    if(permissions & EXEC) {
        printf("Tem execução!\n");
    }

    permissions &= ~WRITE;
    if(permissions & WRITE){
        printf("Ta com a permissao ainda\n");
    }else {
        printf("Permissao foi removida!\n");
    }

    return EXIT_SUCCESS;
}


// printf("a << 1: %02X\n", a << 1); // 1E
// printf("b >> 2: %02X\n", b >> 2); // 0A