#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <chrono>

std::queue<int> buffer;
std::mutex buffer_mutex;
bool done = false;

void producer(){
    for(int i = 0; i < 10; ++i){
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::lock_guard<std::mutex> lock(buffer_mutex);
        buffer.push(i);
        std::cout << "Producer: " << i << "\n";
    }
    std::lock_guard<std::mutex> lock(buffer_mutex);
    done = true;
}

void consumer(){
    while(true){
        std::lock_guard<std::mutex> lock(buffer_mutex);
        if(!buffer.empty()){
            int value = buffer.front();
            buffer.pop();
            std::cout << "Consumer: " << value << "\n";
        } else if(done ){
            break;
        }
    }
}




int main() {
    std::thread t1(producer);
    std::thread t2(consumer);

    t1.join();
    t2.join();
    return EXIT_SUCCESS;
}