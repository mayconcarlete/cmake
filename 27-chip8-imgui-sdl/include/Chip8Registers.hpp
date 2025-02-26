#ifndef CHIP8_REGISTERS_H
#define CHIP8_REGISTERS_H

#include <array>
#include <Config.hpp>

typedef struct {
    TwoBytes program_counter;
    OneByte stack_pointer;
    TwoBytes I;
    std::array<OneByte, CHIP8_TOTAL_REGISTERS> V;
    OneByte delay_timer;
    OneByte sound_timer;
} Registers;

#endif