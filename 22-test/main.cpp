#include <iostream>
#include "nlohmann/json.hpp"

int main(){
    std::cout << "Hello world" << std::endl;
    
    nlohmann::json j;
    
    j["pi"] = 3.1415;
    j["happy"] = true;
    std::cout << j << std::endl;
    return EXIT_SUCCESS;
}