#include <iostream>
#include <queue>
#include <thread>
#include <boost/thread.hpp>
#include <boost/lockfree/queue.hpp>
#include <chrono>
#include <string>
#include <memory>
#include <atomic>
#include <fmt/core.h>

struct Message {
    int event_type;
    int x;
    int y;
};

struct SharedData {
    boost::lockfree::queue<Message> queue;
    std::atomic<bool> done;
    SharedData(): queue(128), done(false){}
};

void producer(std::shared_ptr<SharedData> shared_data){
    for(int i = 0; i < 10; ++i){
        auto event_name = fmt::format("Move: {}", i);
        auto msg = Message{.event_type=i, .x=10, .y=50};
        shared_data->queue.push(msg);
        std::cout << "[Producer] Sent a message: " << i << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    shared_data->done = true;
}

void consumer(std::shared_ptr<SharedData> shared_data){
    Message msg;
    while(!shared_data->done || !shared_data->queue.empty()){
        if(shared_data->queue.pop(msg)){
            auto consumer_msg = fmt::format("[Consumer]: {} X: {} Y: {}", msg.event_type, msg.x, msg.y);
            std::cout << consumer_msg << "\n";
        } else {
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }
}

int main(){

    auto shared_data = std::make_shared<SharedData>();

    boost::thread thread_worker1(producer, shared_data);
    boost::thread thread_worker2(consumer, shared_data);

    thread_worker1.join();
    thread_worker2.join();


    std::cout << "End Threads" << "\n";
    return EXIT_SUCCESS;   
}