#include <iostream>
#include <cassert>

#include <Chip8Cpu.hpp>
#include <Chip8Memory.hpp>
#include <Chip8Registers.hpp>
#include <Chip8Stack.hpp>
#include <Chip8Screen.hpp>
#include <Config.hpp>

void Chip8Cpu::check_stack_in_bounds(){
    assert(registers.stack_pointer < CHIP8_TOTAL_STACK_DEPTH);
}

Chip8Cpu::Chip8Cpu(Memory memory, Registers registers, Stack stack, Screen screen):memory(memory),registers(registers),stack(stack),screen(screen){}

void Chip8Cpu::push_stack(TwoBytes value){
    check_stack_in_bounds();
    stack.stack[registers.stack_pointer] = value;
    registers.stack_pointer += 1;
}

TwoBytes Chip8Cpu::pop_stack(){
    registers.stack_pointer -= 1;
    check_stack_in_bounds();
    return stack.stack[registers.stack_pointer];
}
