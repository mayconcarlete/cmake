#ifndef CONFIG_H
#define CONFIG_H

#define EMULATOR_WINDOW_TITLE "Chip 8 Emulator"
#define CHIP8_MEMORY_SIZE 4096
#define CHIP8_WIDTH 64
#define CHIP8_HEIGHT 32
#define CHIP8_TOTAL_REGISTERS 16

#define CHIP8_WINDOW_MULTIPLIER 15
#define CHIP8_TOTAL_STACK_DEPTH 16
#define CHIP8_KEYBOARD_TOTAL_KEYS 16

typedef unsigned char OneByte; // 8 bits representation - 0 to 0xFF.
typedef unsigned short TwoBytes; // 16 bits representation - 0 to 0xFFFF.

#endif