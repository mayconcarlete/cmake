#ifndef CONFIG_H
#define CONFIG_H


#define EMULATOR_WINDOW_TITLE "Chip 8 Emulator"
#define CHIP8_MEMORY_SIZE 4096
#define CHIP8_WIDTH 64
#define CHIP8_HEIGHT 32
#define CHIP8_TOTAL_REGISTERS 16

#define CHIP8_WINDOW_MULTIPLIER 10

typedef unsigned char OneByte; // 0 to 0x0f
typedef unsigned short TwoBytes; // 0 to 0xff

#endif