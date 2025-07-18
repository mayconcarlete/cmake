#include <iostream>
#include <queue>
#include <string>


int main(){
    std::queue<std::string> queue;
    queue.push("package 1");
    queue.push("package 2");
    queue.push("package 3");

    std::cout << "Queue size: " << queue.size() << "\n";
    std::cout << "First element: " << queue.front() << "\n";

    // remover elementos
    while(!queue.empty()){
        std::cout << "Processando: " << queue.front() << "\n";
        queue.pop();
    }

    // std::boolalpha parsea o valor da stream que faz com que booleanos  1 ou 0 se tornem true/false 
    std::cout << "Empty Queue? " << std::boolalpha << queue.empty() << "\n";
    return EXIT_SUCCESS;
}