#ifndef CHIP8_SCREEN_H
#define CHIP8_SCREEN_H

#include <Config.hpp>
#include <array>

class Screen{
    public:
        bool pixels[CHIP8_HEIGHT][CHIP8_WIDTH];    
        void set(int x, int y);
        bool is_set(int x, int y);    
    };

#endif