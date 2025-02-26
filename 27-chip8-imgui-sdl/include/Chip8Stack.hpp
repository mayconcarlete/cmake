#ifndef CHIP8_STACK_H
#define CHIP8_STACK_H

#include <array>
#include <Config.hpp>
#include <Chip8Registers.hpp>

class Stack{
    public:
        std::array<TwoBytes, CHIP8_TOTAL_STACK_DEPTH> stack;
        void push(TwoBytes value, Registers &registers);
        TwoBytes pop(Registers &registers);
};


#endif