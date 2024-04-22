#include <iostream>
#include "sum_lib/sum.h"

int main(){

    int soma = sum(10, 10);
    std::cout << "Result: " << soma << std::endl;
    return EXIT_SUCCESS;
}