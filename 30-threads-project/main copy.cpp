#include <iostream>
#include <thread>
#include <queue>
#include <condition_variable>
#include <chrono>

std::queue<int> data_queue;
std::mutex queue_mutex;
std::condition_variable cond_var;
bool done = false;

void producer(){
    for(int i = 1; i < 5; ++i){
       { 
        std::lock_guard<std::mutex> lock(queue_mutex);
        data_queue.push(i);
        std::cout << "[PRODUCER] produced: " << i << "\n";
        }
        cond_var.notify_one();
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }
    {
        std::lock_guard<std::mutex> lock(queue_mutex);
        done = true;
    }
    cond_var.notify_one();
}

void consumer(){
    while(true){
        std::unique_lock<std::mutex> lock(queue_mutex);
        cond_var.wait(lock, []{return !data_queue.empty() || done;});
        while(!data_queue.empty()){
            int value = data_queue.front();
            data_queue.pop();
            lock.unlock();
            std::cout << "[CONSUMER] Consumed: " << value << "\n";
            lock.lock();
        }
        if(done) break;
    }
} 

int main(){
    std::thread producer_thread(producer);
    std::thread consumer_thread(consumer);

    producer_thread.join();
    consumer_thread.join();

    std::cout << "End\n";

    return EXIT_SUCCESS;
}