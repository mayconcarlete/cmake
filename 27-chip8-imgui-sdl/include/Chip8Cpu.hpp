#ifndef CHIP8_H
#define CHIP8_H

#include <Config.hpp>
#include <Chip8Memory.hpp>
#include <Chip8Registers.hpp>
#include <Chip8Stack.hpp>
#include <Chip8Screen.hpp>

class Chip8Cpu{
    public:
        Memory memory;
        Registers registers;
        Stack stack;
        Screen screen;
        
        Chip8Cpu(Memory memory, Registers registers, Stack stack, Screen screen);
        ~Chip8Cpu() = default;
        void check_stack_in_bounds();
        void push_stack(TwoBytes value);
        TwoBytes pop_stack();
};


#endif