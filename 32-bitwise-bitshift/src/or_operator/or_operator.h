#ifndef OR_OPERATOR_H
#define OR_OPERATOR_H

/*
    OR - |
    Mantém 1 (on) apenas onde pelo menos 1 dos bits é 1
     * 0b00001111
     *          |
     * 0b00101010
     * ----------
     * 0b00101111
*/

void or_comparison(unsigned char a, unsigned char b);

#endif