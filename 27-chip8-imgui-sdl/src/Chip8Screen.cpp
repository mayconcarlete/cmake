#include <Chip8Screen.hpp>
#include <cassert>
#include <Config.hpp>

void chip8_screen_in_bounds(int x, int y){
    assert(x >= 0 && x < CHIP8_WIDTH && y >= 0 && y < CHIP8_HEIGHT);
}

void Screen::set(int x, int y){
    chip8_screen_in_bounds(x, y);
    pixels[y][x] = true;
}

bool Screen::is_set(int x, int y){
    chip8_screen_in_bounds(x, y);
    return pixels[y][x];
}