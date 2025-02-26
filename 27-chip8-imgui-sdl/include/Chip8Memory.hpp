#ifndef CHIP8_MEMORY_H
#define CHIP8_MEMORY_H

#include <array>
#include <Config.hpp>

class Memory {
    public:
        void Set(int index, OneByte value);
        OneByte Get(int index);
    private: 
        void CheckMemoryBoundary(int index);
        std::array<OneByte, CHIP8_MEMORY_SIZE> memory;
};

#endif