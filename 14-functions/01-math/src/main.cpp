#include <iostream>
#include <cstdint>
#include "math.hpp"

int main(int argv, char** argc){
    const auto result = fatorial(5);
    std::cout << "Result: " << result << "\n";
    const auto sumFloat = sum<float>(3.14, 3.00);
    const auto sumInt = sum<int>(3, 4);
    std::cout << "Sum Float: " << sumFloat << "Sum Int: " << sumInt << "\n";
    return 0;
}