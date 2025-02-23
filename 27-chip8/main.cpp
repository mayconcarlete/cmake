
#include <iostream>
#include <SDL2/SDL.h>
#include <imgui.h>
#include <imgui_impl_sdl2.h>
#include <imgui_impl_sdlrenderer2.h>

int main(){
   SDL_Init(SDL_INIT_EVERYTHING);

   SDL_Window* window = SDL_CreateWindow(
       "SDL2 It's Works!",
       50, 30,
       1280, 720,
       SDL_WINDOW_SHOWN
       );

    SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);
    
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();

    ImGui_ImplSDL2_InitForSDLRenderer(window, renderer);

    ImGui_ImplSDLRenderer2_Init(renderer);

   while(true){
     SDL_Event event;
     while(SDL_PollEvent(&event)){
        ImGui_ImplSDL2_ProcessEvent(&event);
       if( event.type == SDL_QUIT ){
         exit(0);
       }else if( event.type == SDL_MOUSEBUTTONDOWN ){
        
       }
     }

    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 120, 180, 255, 255);

    ImGui_ImplSDLRenderer2_NewFrame();
    ImGui_ImplSDL2_NewFrame();
    ImGui::NewFrame();
    

    ImGui::Begin("Hello, Dear ImGui with SDL2");
    ImGui::Text("This is just a basic Hello World!");
    ImGui::End();
    ImGui::Render();
    
    ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData(), renderer);

    SDL_RenderPresent(renderer);
   }

    ImGui_ImplSDLRenderer2_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();

   SDL_DestroyRenderer(renderer);
   SDL_DestroyWindow(window);
   SDL_Quit();


    return EXIT_SUCCESS;
}