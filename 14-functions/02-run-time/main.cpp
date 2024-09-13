#include <iostream>
#include <cstdint>
#include <exception>

std::uint32_t fatorial(const std::uint32_t n){
    std::uint32_t result = 1;
    for(std::uint32_t i = n; i > 1; --i){
        result *= i;
    }
    return result;
}

int main(int argc, char *argv[]){
    for(std::uint32_t i = 0; i < argc; ++i){
            std::cout << "Index: " << i << " value: " << argv[i] << "\n"; 
    }
    try{
        std::uint32_t number = std::stoi(argv[1]);
        const auto result = fatorial(number);
        std::cout << "Result: " << result << "\n";   
    } catch(const std::exception& error){
        std::cout << "Error: " << error.what() << "\n";
    }

    return EXIT_SUCCESS;
}