#include <iostream>
#include <cstdint>
#include "math.hpp"

int main(int argv, char** argc){
    const auto result = fatorial(5);
    std::cout << "Result: " << result << "\n";
    return 0;
}