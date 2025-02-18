#include <iostream>
#include "nlohmann/json.hpp"
#include <cstdint>

typedef struct {
    std::uint32_t x;
    std::uint32_t y;
    char c;
} Transport;

class CTransport{
    public:
        std::uint32_t x;
        std::uint32_t y;
        char c;
        char d;
};

int main(){
    std::cout << "Hello world" << std::endl;
    
    nlohmann::json j;
    
    j["pi"] = 3.1415;
    j["happy"] = true;
    std::cout << j["pi"] << std::endl;
    std::string message = j.dump();
    std::cout << "json in str: " << message<< std::endl;


    Transport t;
    std::cout << "Size: " << sizeof(std::uint32_t) << std::endl;
    std::cout << "Size: " << sizeof(char) << std::endl;
    CTransport c;
    std::cout << "Size of class: " << sizeof(c) << std::endl;
    
    return EXIT_SUCCESS;
}