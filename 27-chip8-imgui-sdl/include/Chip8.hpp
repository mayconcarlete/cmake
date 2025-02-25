#ifndef CHIP8_H
#define CHIP8_H

#include <Config.hpp>
#include <Chip8Memory.hpp>

class Chip8{
    public:
        Chip8(Memory memory);
        ~Chip8() = default;
        Memory m_memory;
};


#endif