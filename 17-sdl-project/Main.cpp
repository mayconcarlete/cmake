// esse define abaixo serve para tirar o erro na hora de compilar para o windows que fica impedindo a compilacao de completar
//pois fala que a main ja fora definida em outro arquivo
#define SDL_MAIN_HANDLED
#include <iostream>
#include <SDL2/SDL.h>

int main(){

    std::cout<<"Test SDL"<< std::endl;
    SDL_Init(SDL_INIT_VIDEO);
    while(1){}
    SDL_Quit();
    return EXIT_SUCCESS;
}