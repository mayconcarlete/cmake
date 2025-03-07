#ifndef CHIP8_MEMORY_H
#define CHIP8_MEMORY_H

#include <array>
#include <Config.hpp>
#include <cstring>

class Memory {
    public:
        Memory();
        ~Memory() = default;
        void Set(int index, OneByte value);
        OneByte Get(int index);
    private: 
        std::array<OneByte, CHIP8_MEMORY_SIZE> memory;
};

#endif