#include <iostream>
#include <SDL.h>

int main(int argc, char *argv[]) {
    std::cout << "Startei o game" << std::endl;
    bool game_is_running = false;
    SDL_Window* window;
    SDL_Renderer* renderer;

 if(SDL_Init(SDL_INIT_EVERYTHING) != 0){
        fprintf(stderr, "Error initializing SDL.\n");
        return false;
    }
    window = SDL_CreateWindow(
        "test",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        640,
        480,
        SDL_WINDOW_SHOWN
    );

    if(!window){
        fprintf(stderr, "Error creating SDL window.\n");
        return false;
    }

    renderer = SDL_CreateRenderer(
        window,
        -1,
        0
    );
    if(!renderer){
        fprintf(stderr, "Error creating SDL Renderer.\n");
    }
    std::cout << "Aqui eu to 1" << std::endl;
    SDL_Delay(3000);
    std::cout << "Aqui eu to 2" << std::endl;


SDL_DestroyWindow(window);
SDL_Quit();

return 0;
}