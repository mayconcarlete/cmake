#ifndef CHIP8_MEMORY_H
#define CHIP8_MEMORY_H

#include <vector>
#include <Config.hpp>

class Memory {
    public:
        void Set(int index, unsigned char value);
        unsigned char Get(int index);
    private: 
        void CheckMemoryBoundary(int index);
        unsigned char m_memory[CHIP8_MEMORY_SIZE];
};

#endif