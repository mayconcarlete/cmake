#include "math.hpp"
#include <cstdint>

std::uint32_t fatorial(std::uint32_t n){
    std::uint32_t result = 1;
    for(std::uint32_t i = n;  i > 1; --i){
        result *= i;
    }
    return result;
}

template <typename T>
T sum(T a, T b){
    return a + b;
}