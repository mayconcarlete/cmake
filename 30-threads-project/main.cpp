#include <iostream>
#include <queue>
#include <thread>
#include <boost/thread.hpp>
#include <chrono>


void worker1(){
    for(int i = 0; i < 5; ++i){
        std::cout << "[Worker 1]: " << i << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(600));
    }
}

void worker2(){
    for(int i = 0; i < 5; ++i){
        std::cout << "[Worker 2]: " << i << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(400));
    }
}

int main(){

    boost::thread thread_worker1(worker1);
    boost::thread thread_worker2(worker2);

    thread_worker1.join();
    thread_worker2.join();


    std::cout << "End Threads" << "\n";
    return EXIT_SUCCESS;   
}