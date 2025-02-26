#include <iostream>
#include <cassert>

#include <Chip8Memory.hpp>
#include <Config.hpp>


void Memory::CheckMemoryBoundary(int index){
    assert(index >= 0  && index < CHIP8_MEMORY_SIZE);
}

void Memory::Set(int index, unsigned char value){
    CheckMemoryBoundary(index);
    memory[index] = value;
}

unsigned char Memory::Get(int index){
     CheckMemoryBoundary(index);
    return memory[index]; 
}