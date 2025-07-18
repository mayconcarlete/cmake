#include <iostream>
#include <thread>
#include <cstdint>
#include <mutex>

/*
    Example 1
*/
int counter = 0;

void increment_counter(){
    for(std::uint32_t i = 0; i < 1000000; i++){
        ++counter;
    }
}

/*
    Example 2
*/
std::mutex m;
int counter_two = 0;
void increment_counter_two(){
    for(std::int32_t i = 0; i < 1000000; i++){
        std::lock_guard<std::mutex> lock(m);
        ++counter_two;
    }
}

int main(){ 
    // adicionar para printar o compilador se o build for tipo debugger
    // devo usar std::uint ou size_t para for loops
    
    std::thread t1(increment_counter);
    std::thread t2(increment_counter);

    t1.join(); // segura main até a thread acabar
    t2.join(); // segura main até a thread acabar

    std::cout << "Counter value: " << counter << "\n";


    // example two
    std::thread t3(increment_counter_two);
    std::thread t4(increment_counter_two);

    t3.join();
    t4.join();

    std::cout << "Counter two value: " << counter_two << "\n";

    return EXIT_SUCCESS;
}