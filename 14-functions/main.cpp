#include <iostream>
#include <cstdint>

constexpr ::uint32_t fatorial(std::uint32_t n){
    std::uint32_t result = 1;
    for(std::uint32_t i = n;  i > 1; --i){
        result *= i;
    }
    return result;
}

int main(){
    constexpr auto result = fatorial(5);
    std::cout << "Result: " << result << "\n";
    return EXIT_SUCCESS;
}