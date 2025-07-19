#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <chrono>
#include <memory>

bool done = false;

struct SharedData {
    std::queue<int> queue;
    std::mutex mutex;
};

void producer(std::shared_ptr<SharedData> shared_data){
    for(int i = 0; i < 10; ++i){
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::lock_guard<std::mutex> lock(shared_data->mutex);
        shared_data->queue.push(i);
        std::cout << "Producer: " << i << "\n";
    }
    std::lock_guard<std::mutex> lock(shared_data->mutex);
    done = true;
}

void consumer(std::shared_ptr<SharedData> shared_data){
    bool running = true;
    while(running) {
        std::lock_guard<std::mutex> lock(shared_data->mutex);
        if(!shared_data->queue.empty()){
            int value = shared_data->queue.front();
            shared_data->queue.pop();
            std::cout << "Consumer: " << value << "\n";
        } else if(done) {
            running = false;
        }
    };
}



int main() {
    auto shared_data = std::make_shared<SharedData>();

    std::thread prod(producer, shared_data);
    std::thread cons(consumer, shared_data);

    prod.join();
    cons.join();
    return EXIT_SUCCESS;
}