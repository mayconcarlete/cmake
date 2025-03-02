#include <cassert>
#include <Chip8Keyboard.hpp>
#include <Config.hpp>

void chip8_keyboard_key_in_bounds(int key){
    assert(key>0 && key < CHIP8_KEYBOARD_TOTAL_KEYS);
}

int Keyboard::get_map_key(char key){

    for(int i = 0; i < CHIP8_KEYBOARD_TOTAL_KEYS; i++){
        if(map_keys[i] == key){
            return i;
        }
    }
    return -1;
}

void Keyboard::key_down(int key){
    keyboard[key] = true;
}

void Keyboard::key_up(int key){
    keyboard[key] = false;
}

bool Keyboard::is_key_down(int key){
    return keyboard[key];
}