#include <iostream>
#include <cstdint>

int main(int argc, char *argv[]){
    for(std::uint32_t i = 0; i < argc; ++i){
            std::cout << "Index: " << i << " value: " << argv[i] << "\n"; 
    }

    return EXIT_SUCCESS;
}