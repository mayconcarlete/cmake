#ifndef CHIP8_KEYBOARD_H
#define CHIP8_KEYBOARD_H

#include <array>
#include <Config.hpp>
#include <SDL.h>


class Keyboard {
    public:
        std::array<char, CHIP8_KEYBOARD_TOTAL_KEYS> map_keys{
            SDLK_0, SDLK_1, SDLK_2, SDLK_4, SDLK_5,
            SDLK_6, SDLK_7, SDLK_8, SDLK_9, SDLK_a, 
            SDLK_b, SDLK_c, SDLK_d, SDLK_e, SDLK_f, 
        };
        std::array<bool, CHIP8_KEYBOARD_TOTAL_KEYS> keyboard;
        void key_down(int key);
        void key_up(int key);
        bool is_key_down(int key);
        int get_map_key(char key);
};

#endif