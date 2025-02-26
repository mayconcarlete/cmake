#include <cassert>

#include <Chip8Stack.hpp>
#include <Chip8Registers.hpp>

void check_stack_in_bounds(Registers &registers){
   assert(registers.stack_pointer < CHIP8_TOTAL_STACK_DEPTH);
}

void Stack::push(TwoBytes value, Registers &registers){
    check_stack_in_bounds(registers);
    const OneByte index = registers.stack_pointer;
    stack[index] = value;
    registers.stack_pointer += 1;
}

TwoBytes Stack::pop(Registers &registers){
    registers.stack_pointer -= 1;
    check_stack_in_bounds(registers);
    const OneByte index = registers.stack_pointer;
    TwoBytes value = stack[index];
    return value;
}