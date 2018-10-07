#include "font.h"
#include "types.h"

u8 font[GLYPH_BYTE_COUNT] = {
    // Space " "
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,

    // Exclamation mark "!"
    0b00011000,
    0b00011000,
    0b00011000,
    0b00011000,
    0b00000000,
    0b00011000,
    0b00000000,
    0b00000000,

    // Quotation mark """
    0b01100110,
    0b01100110,
    0b01000100,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,

    // Cross hatch "#"
    0b00010100,
    0b00010100,
    0b01111110,
    0b00101000,
    0b01111110,
    0b00101000,
    0b00000000,
    0b00000000,

    // Dollar sign "$"
    0b00111100,
    0b01101010,
    0b01111100,
    0b00111110,
    0b01010110,
    0b00111100,
    0b00010000,
    0b00000000,

    // Percent sign "%"
    0b00100010,
    0b01010100,
    0b00101000,
    0b00010100,
    0b00101010,
    0b01000100,
    0b00000000,
    0b00000000,

    // Ampersand "&"
    0b00110000,
    0b01001000,
    0b00110010,
    0b01001100,
    0b01001100,
    0b00110010,
    0b00000000,
    0b00000000,

    // Closing single quote "'"
    0b00011000,
    0b00011000,
    0b00010000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,

    // Opening parentheses "("
    0b00001100,
    0b00011000,
    0b00110000,
    0b00110000,
    0b00110000,
    0b00110000,
    0b00011000,
    0b00001100,

    // Closing parentheses ")"
    0b00110000,
    0b00011000,
    0b00001100,
    0b00001100,
    0b00001100,
    0b00001100,
    0b00011000,
    0b00110000,

    // Asterisk "*"
    0b00011000,
    0b01111110,
    0b00011000,
    0b00100100,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,

    // Plus "+"
    0b00000000,
    0b00011000,
    0b00011000,
    0b01111110,
    0b00011000,
    0b00011000,
    0b00000000,
    0b00000000,

    // Comma ""
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00011000,
    0b00011000,
    0b00010000,
    0b00000000,

    // Hyphen "-"
    0b00000000,
    0b00000000,
    0b00000000,
    0b00111100,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,

    // Period "."
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00011000,
    0b00011000,
    0b00000000,
    0b00000000,

    // Forward slash "/"
    0b00000010,
    0b00000110,
    0b00001100,
    0b00011000,
    0b00110000,
    0b01100000,
    0b01000000,
    0b00000000,

    // 0
    0b00111010,
    0b01100100,
    0b01001010,
    0b01010010,
    0b00100110,
    0b01011100,
    0b00000000,
    0b00000000,

    // 1
    0b00011000,
    0b00111000,
    0b00011000,
    0b00011000,
    0b00011000,
    0b00111100,
    0b00000000,
    0b00000000,

    // 2
    0b00111000,
    0b01001100,
    0b00001100,
    0b00011000,
    0b00110000,
    0b01111110,
    0b00000000,
    0b00000000,

    // 3
    0b00111100,
    0b01000110,
    0b00011100,
    0b00000110,
    0b01000110,
    0b00111100,
    0b00000000,
    0b00000000,

    // 4
    0b00001100,
    0b00011100,
    0b00101100,
    0b01001100,
    0b01111110,
    0b00001100,
    0b00000000,
    0b00000000,

    // 5
    0b01111110,
    0b01100000,
    0b01111100,
    0b00000110,
    0b01000110,
    0b00111100,
    0b00000000,
    0b00000000,

    // 6
    0b00111100,
    0b01100000,
    0b01111100,
    0b01100110,
    0b01100110,
    0b00111100,
    0b00000000,
    0b00000000,

    // 7
    0b01111110,
    0b01100110,
    0b00001100,
    0b00111110,
    0b00011000,
    0b00011000,
    0b00000000,
    0b00000000,

    // 8
    0b00111100,
    0b01100110,
    0b00111100,
    0b01100110,
    0b01100110,
    0b00111100,
    0b00000000,
    0b00000000,

    // 9
    0b00111100,
    0b01100110,
    0b01100110,
    0b00111110,
    0b00000110,
    0b00111100,
    0b00000000,
    0b00000000,

    // Colon ":"
    0b00000000,
    0b00011000,
    0b00011000,
    0b00000000,
    0b00011000,
    0b00011000,
    0b00000000,
    0b00000000,

    // Semicolon ";"
    0b00000000,
    0b00011000,
    0b00011000,
    0b00000000,
    0b00011000,
    0b00011000,
    0b00010000,
    0b00000000,

    // Less than sign "<"
    0b00000000,
    0b00000110,
    0b00011000,
    0b01100000,
    0b00011000,
    0b00000110,
    0b00000000,
    0b00000000,

    // Equals sign "="
    0b00000000,
    0b00000000,
    0b01111110,
    0b00000000,
    0b01111110,
    0b00000000,
    0b00000000,
    0b00000000,

    // Greater than sign ">"
    0b00000000,
    0b01100000,
    0b00011000,
    0b00000110,
    0b00011000,
    0b01100000,
    0b00000000,
    0b00000000,

    // Question mark "?"
    0b00111100,
    0b01100110,
    0b01100110,
    0b00001100,
    0b00011000,
    0b00000000,
    0b00011000,
    0b00000000,

    // At sign "@"
    0b01111100,
    0b10000010,
    0b10111010,
    0b10101010,
    0b10111110,
    0b01000000,
    0b00111110,
    0b00000000,

    // A
    0b00011000,
    0b00111100,
    0b00100100,
    0b01111110,
    0b01100110,
    0b01100110,
    0b00000000,
    0b00000000,

    // B
    0b01111100,
    0b01100110,
    0b01111100,
    0b01100110,
    0b01100110,
    0b01111100,
    0b00000000,
    0b00000000,

    // C
    0b00111100,
    0b01100110,
    0b01100000,
    0b01100010,
    0b01111110,
    0b00111100,
    0b00000000,
    0b00000000,

    // D
    0b01111100,
    0b01100110,
    0b01100110,
    0b01100110,
    0b01111110,
    0b01111100,
    0b00000000,
    0b00000000,

    // E
    0b01111110,
    0b01100000,
    0b01111100,
    0b01100000,
    0b01111110,
    0b01111110,
    0b00000000,
    0b00000000,

    // F
    0b01111110,
    0b01100000,
    0b01111100,
    0b01100000,
    0b01100000,
    0b01100000,
    0b00000000,
    0b00000000,

    // G
    0b00111100,
    0b01100110,
    0b01100000,
    0b01101110,
    0b01100110,
    0b00111100,
    0b00000000,
    0b00000000,

    // H
    0b01100110,
    0b01100110,
    0b01111110,
    0b01100110,
    0b01100110,
    0b01100110,
    0b00000000,
    0b00000000,

    // I
    0b01111110,
    0b00011000,
    0b00011000,
    0b00011000,
    0b01111110,
    0b01111110,
    0b00000000,
    0b00000000,

    // J
    0b00111110,
    0b00001100,
    0b00001100,
    0b01001100,
    0b01111100,
    0b00111000,
    0b00000000,
    0b00000000,

    // K
    0b01100110,
    0b01101100,
    0b01111000,
    0b01111000,
    0b01101100,
    0b01100110,
    0b00000000,
    0b00000000,

    // L
    0b01100000,
    0b01100000,
    0b01100000,
    0b01100000,
    0b01111110,
    0b01111110,
    0b00000000,
    0b00000000,

    // M
    0b01000010,
    0b01100110,
    0b01111110,
    0b01011010,
    0b01011010,
    0b01000010,
    0b00000000,
    0b00000000,

    // N
    0b01000110,
    0b01100110,
    0b01110110,
    0b01111110,
    0b01101110,
    0b01100110,
    0b00000000,
    0b00000000,

    // O
    0b00111100,
    0b01100110,
    0b01100110,
    0b01100110,
    0b01111110,
    0b00111100,
    0b00000000,
    0b00000000,

    // P
    0b01111100,
    0b01100110,
    0b01111110,
    0b01111100,
    0b01100000,
    0b01100000,
    0b00000000,
    0b00000000,

    // Q
    0b00111100,
    0b01100110,
    0b01100010,
    0b01101010,
    0b01111110,
    0b00111100,
    0b00000010,
    0b00000000,

    // R
    0b01111100,
    0b01100110,
    0b01111110,
    0b01111100,
    0b01101100,
    0b01100110,
    0b00000000,
    0b00000000,

    // S
    0b00111100,
    0b01100010,
    0b01111100,
    0b00111110,
    0b01000110,
    0b00111100,
    0b00000000,
    0b00000000,

    // T
    0b01111110,
    0b00011000,
    0b00011000,
    0b00011000,
    0b00011000,
    0b00011000,
    0b00000000,
    0b00000000,

    // U
    0b01100110,
    0b01100110,
    0b01100110,
    0b01100110,
    0b01111110,
    0b00111100,
    0b00000000,
    0b00000000,

    // V
    0b01100110,
    0b01100110,
    0b01100110,
    0b00100100,
    0b00111100,
    0b00011000,
    0b00000000,
    0b00000000,

    // W
    0b01000010,
    0b01011010,
    0b01011010,
    0b01111110,
    0b01100110,
    0b01000010,
    0b00000000,
    0b00000000,

    // X
    0b01100110,
    0b00111100,
    0b00011000,
    0b00111100,
    0b01100110,
    0b01000010,
    0b00000000,
    0b00000000,

    // Y
    0b01100110,
    0b01100110,
    0b00111100,
    0b00011000,
    0b00011000,
    0b00011000,
    0b00000000,
    0b00000000,

    // Z
    0b01111110,
    0b00001100,
    0b00011000,
    0b00110000,
    0b01111110,
    0b01111110,
    0b00000000,
    0b00000000,

    // Opening square bracket "["
    0b00011100,
    0b00011000,
    0b00011000,
    0b00011000,
    0b00011000,
    0b00011000,
    0b00011000,
    0b00011100,

    // Back slash "\"
    0b01000000,
    0b01100000,
    0b00110000,
    0b00011000,
    0b00001100,
    0b00000110,
    0b00000010,
    0b00000000,

    // Closing square bracket "]"
    0b00111000,
    0b00011000,
    0b00011000,
    0b00011000,
    0b00011000,
    0b00011000,
    0b00011000,
    0b00111000,

    // Caret "^"
    0b00011000,
    0b00100100,
    0b01000010,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,

    // Underscore "_"
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b11111111,

    // Opening single quote "`"
    0b00011000,
    0b00011000,
    0b00001000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,

    // a
    0b00000000,
    0b00000000,
    0b00111000,
    0b01100100,
    0b01100100,
    0b00111010,
    0b00000000,
    0b00000000,

    // b
    0b00110000,
    0b00110000,
    0b00111100,
    0b00110010,
    0b00110010,
    0b01011100,
    0b00000000,
    0b00000000,

    // c
    0b00000000,
    0b00000000,
    0b00111100,
    0b01100000,
    0b01100010,
    0b00111100,
    0b00000000,
    0b00000000,

    // d
    0b00001100,
    0b00001100,
    0b00111100,
    0b01001100,
    0b01001100,
    0b00111010,
    0b00000000,
    0b00000000,

    // e
    0b00000000,
    0b00000000,
    0b00111000,
    0b01101000,
    0b01110010,
    0b00111100,
    0b00000000,
    0b00000000,

    // f
    0b00000000,
    0b00000000,
    0b00011100,
    0b00110010,
    0b00110000,
    0b01111100,
    0b00110000,
    0b00110000,

    // g
    0b00000000,
    0b00000000,
    0b00111010,
    0b01100110,
    0b01100110,
    0b00111110,
    0b01000110,
    0b00111100,

    // h
    0b01100000,
    0b01100000,
    0b01111100,
    0b01100010,
    0b01100010,
    0b01100010,
    0b00000000,
    0b00000000,

    // i
    0b00110000,
    0b00000000,
    0b00110000,
    0b00110000,
    0b00110100,
    0b00011000,
    0b00000000,
    0b00000000,

    // j
    0b00000110,
    0b00000000,
    0b00000110,
    0b00000110,
    0b00000110,
    0b00000110,
    0b01000110,
    0b00111100,

    // k
    0b01100000,
    0b01100100,
    0b01101000,
    0b01111000,
    0b01100100,
    0b01100010,
    0b00000000,
    0b00000000,

    // l
    0b00110000,
    0b00110000,
    0b00110000,
    0b00110000,
    0b00110100,
    0b00011000,
    0b00000000,
    0b00000000,

    // m
    0b00000000,
    0b00000000,
    0b01010100,
    0b01101010,
    0b01101010,
    0b01100010,
    0b00000000,
    0b00000000,

    // n
    0b00000000,
    0b00000000,
    0b01011100,
    0b01100010,
    0b01100010,
    0b01100010,
    0b00000000,
    0b00000000,

    // o
    0b00000000,
    0b00000000,
    0b00111100,
    0b01100010,
    0b01100010,
    0b00111100,
    0b00000000,
    0b00000000,

    // p
    0b00000000,
    0b00000000,
    0b01011100,
    0b01100110,
    0b01100110,
    0b01111100,
    0b01100000,
    0b01100000,

    // q
    0b00000000,
    0b00000000,
    0b00110100,
    0b01001100,
    0b01001100,
    0b00111100,
    0b00001110,
    0b00001100,

    // r
    0b00000000,
    0b00000000,
    0b01011100,
    0b01100010,
    0b01100000,
    0b01100000,
    0b00000000,
    0b00000000,

    // s
    0b00000000,
    0b00111100,
    0b01100010,
    0b00011000,
    0b01000110,
    0b00111100,
    0b00000000,
    0b00000000,

    // t
    0b00110000,
    0b00110000,
    0b01111000,
    0b00110000,
    0b00110010,
    0b00011100,
    0b00000000,
    0b00000000,

    // u
    0b00000000,
    0b00000000,
    0b01100110,
    0b01100110,
    0b01100110,
    0b00111010,
    0b00000000,
    0b00000000,

    // v
    0b00000000,
    0b00000000,
    0b01100010,
    0b01100010,
    0b00110100,
    0b00011000,
    0b00000000,
    0b00000000,

    // w
    0b00000000,
    0b00000000,
    0b01000010,
    0b01011010,
    0b01011010,
    0b00101100,
    0b00000000,
    0b00000000,

    // x
    0b00000000,
    0b00000000,
    0b01100010,
    0b00110100,
    0b00011000,
    0b01100110,
    0b00000000,
    0b00000000,

    // y
    0b00000000,
    0b00000000,
    0b01100110,
    0b01100110,
    0b01100110,
    0b00111110,
    0b01000110,
    0b00111100,

    // z
    0b00000000,
    0b00000000,
    0b01111110,
    0b00001100,
    0b00110000,
    0b01111110,
    0b00000000,
    0b00000000,

    // Opening curly bracket "{"
    0b00011100,
    0b00110000,
    0b00110000,
    0b00011000,
    0b00011000,
    0b00110000,
    0b00110000,
    0b00011100,

    // Vertical line "|"
    0b00011000,
    0b00011000,
    0b00011000,
    0b00011000,
    0b00011000,
    0b00011000,
    0b00011000,
    0b00011000,

    // Closing curly bracket "{"
    0b00111000,
    0b00001100,
    0b00001100,
    0b00011000,
    0b00011000,
    0b00001100,
    0b00001100,
    0b00111000,

    // Tilde "~"
    0b00000000,
    0b00000000,
    0b01110000,
    0b01011010,
    0b00001110,
    0b00000000,
    0b00000000,
    0b00000000,
};