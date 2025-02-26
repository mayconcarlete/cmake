#ifndef CHIP8_H
#define CHIP8_H

#include <Config.hpp>
#include <Chip8Memory.hpp>
#include <Chip8Registers.hpp>
#include <Chip8Stack.hpp>

class Chip8{
    public:
        Chip8(Memory memory, Registers registers, Stack stack);
        ~Chip8() = default;
        Memory memory;
        Registers registers;
        Stack stack;
};


#endif