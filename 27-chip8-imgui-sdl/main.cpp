
#include <iostream>
#include <SDL2/SDL.h>
#include <imgui.h>
#include <imgui_impl_sdl2.h>
#include <imgui_impl_sdlrenderer2.h>

#include <Chip8Keyboard.hpp>
#include <Config.hpp>
#include <Chip8Memory.hpp>
#include <Chip8Registers.hpp>
#include <Chip8Stack.hpp>
#include <Chip8Cpu.hpp>
#include <Chip8Screen.hpp>
#include <sstream>

int main(){
  SDL_Init(SDL_INIT_EVERYTHING);

  SDL_Window* window = SDL_CreateWindow(
      EMULATOR_WINDOW_TITLE,
      SDL_WINDOWPOS_UNDEFINED,
      SDL_WINDOWPOS_UNDEFINED,
      1024, 860,
      SDL_WINDOW_SHOWN
      );

  if(window == NULL){
    std::cout << "SDL Window Error: " << SDL_GetError() << std::endl;
  }

  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

  if(renderer == NULL){
    std::cout << "SDL Renderer Error: " << SDL_GetError() << std::endl;
  }

  auto memory = Memory();
  Registers registers;
  auto stack = Stack();
  auto screen = Screen();
  auto chip8 = Chip8Cpu(memory, registers, stack, screen);
  
  chip8.push_stack(0xFF);
  chip8.push_stack(0xaa);
  
  auto keyboard = Keyboard();

  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO& io = ImGui::GetIO();

  ImGui_ImplSDL2_InitForSDLRenderer(window, renderer);

  ImGui_ImplSDLRenderer2_Init(renderer);

  ImGui_ImplSDLRenderer2_NewFrame();
  ImGui_ImplSDL2_NewFrame();


  bool shouldCloseWindow{false};
  while(!shouldCloseWindow){
    SDL_Event event;
    while(SDL_PollEvent(&event)){
      ImGui_ImplSDL2_ProcessEvent(&event);
      if( event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE ){
        shouldCloseWindow = true;
      }else if( event.type == SDL_MOUSEBUTTONDOWN ){

      } else if(event.type == SDL_KEYDOWN){
        for(int i = 0; i < CHIP8_KEYBOARD_TOTAL_KEYS; i++){
          if(event.key.keysym.sym == keyboard.map_keys[i]){
            keyboard.key_down(event.key.keysym.sym);
          }
        }
      }else if(event.type == SDL_KEYUP){
        for(int i = 0; i < CHIP8_KEYBOARD_TOTAL_KEYS; i++){
          if(event.key.keysym.sym == keyboard.map_keys[i]){
            keyboard.key_up(event.key.keysym.sym);
          }
        }
      }
    }

    SDL_SetRenderDrawColor(renderer, 120, 180, 255, 255);
    SDL_RenderClear(renderer);
    // SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    
    chip8.screen.set(0, 0);
    chip8.screen.set(10, 10);

    for(int x = 0; x < CHIP8_WIDTH; x++){
      for (int y = 0; y < CHIP8_HEIGHT; y++){
        // SDL_RenderDrawRect(renderer, &rect); // desenha sem preencher a are do retangulo.
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        if(chip8.screen.is_set(x, y)){
          SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        }
        SDL_Rect rect;
        rect.x = x * CHIP8_WINDOW_MULTIPLIER;
        rect.y = y * CHIP8_WINDOW_MULTIPLIER;
        rect.w = CHIP8_WINDOW_MULTIPLIER;
        rect.h = CHIP8_WINDOW_MULTIPLIER;
        SDL_RenderFillRect(renderer, &rect); // preenche toda a area do retangulo.
      }
    }




    ImGui::NewFrame();
    ////////////////////////////////////////////////////////////
    //  Draw all imgui widgets here.
    ////////////////////////////////////////////////////////////
    ImGui::Begin("Hello, Dear ImGui with SDL2");
    ImGui::Text("This is just a basic Hello World!");
    ImGui::End();

    ////////////////////
    // Stack
    ///////////////////
    ImGui::Begin("Stack Information");
    ImGui::BeginTable("Stack Information", 3);
                ImGui::TableSetupColumn("Position");
                ImGui::TableSetupColumn("Value Hex");
                ImGui::TableSetupColumn("Value Int");
                ImGui::TableHeadersRow();

       for (int row = 0; row < CHIP8_TOTAL_STACK_DEPTH; row++)
            {
                ImGui::TableNextRow();
                ImGui::TableNextColumn();
                std::stringstream buffer;
                buffer << std::hex << row;
                std::string index = buffer.str();
                ImGui::Text("%s",index.c_str());
                ImGui::TableNextColumn();
                
                std::string message = chip8.stack.stack[row] == 0 ? "0x00" : "0x%x";
                ImGui::Text(message.c_str(), chip8.stack.stack[row]);
                ImGui::TableNextColumn();
                
                std::string value = std::to_string(chip8.stack.stack[row]);
                ImGui::Text("%s", value.c_str());
            }
    ImGui::EndTable();
    ImGui::End();

    ImGui::Begin("Interpreter Memory");
    ImGui::BeginTable("a", 16);
            for(int i = 0; i < 16; i++){
              // sstring.clear();
              std::stringstream sstring; // to convert int into char
              sstring << std::hex << i;
              std::string str = sstring.str();
              ImGui::TableSetupColumn(str.c_str());
            }
            ImGui::TableHeadersRow();

    ImGui::EndTable();
    ImGui::End();

    ImGui::Begin("Memory");
    ImGui::BeginTable("a", 16);
            for(int i = 0; i < 16; i++){
              // sstring.clear();
              std::stringstream sstring; // to convert int into char
              sstring << std::hex << i;
              std::string str = sstring.str();
              ImGui::TableSetupColumn(str.c_str());
            }
            ImGui::TableHeadersRow();

    ImGui::EndTable();
    ImGui::End();

    // ////////////////////
    // // Keybaord
    // ///////////////////
    ImGui::Begin("Keyboard Information");
    ImGui::BeginTable("Keyboard", 4);

    // ImGui::TableHeadersRow();
    ImGui::TableNextRow();
    ImGui::TableNextColumn();

    // for(int i = 0; i < 4; i++){
    //   for(int j = 0; j < 4; j++){
    //     const auto index = (j * 4) + i;
    //     int key = keyboard.screen_map[index];
    //     const auto iskeydown = keyboard.is_key_down(key);
    //     std::cout << "Pressionada sim, colorir!!! << "<< key << iskeydown << "\n";
    //     ImGui::Text("%c",key);
    //   }

    //   ImGui::TableNextColumn();

    // }


    ImGui::EndTable();
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