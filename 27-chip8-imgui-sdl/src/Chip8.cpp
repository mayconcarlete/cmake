#include <iostream>
#include <Chip8.hpp>
#include <Chip8Memory.hpp>
#include <Chip8Registers.hpp>
#include <Chip8Stack.hpp>

Chip8::Chip8(Memory memory, Registers registers, Stack stack):memory(memory),registers(registers),stack(stack){}