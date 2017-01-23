#ifndef __KEYPAD_H
#define __KEYPAD_H
#include "main.h"
#include "gpio.h"

#define KEY_1 0x01
#define KEY_2 0x02
#define KEY_3 0x03
#define KEY_4 0x04
#define KEY_5 0x05
#define KEY_6 0x06
#define KEY_7 0x07
#define KEY_8 0x08
#define KEY_9 0x09
#define KEY_STAR 0x0A
#define KEY_0 0x0B
#define KEY_HASH 0x0C
#define NO_KEY 0x00

const uint8_t translateArray[] = {NULL, '1', '2', '3',
                                        '4', '5', '6',
                                        '7', '8', '9',
                                        '*', '0', '#'};

uint8_t checkKeypad();
uint8_t translateKeyToChar(int key);

#endif /* __KEYPAD_H */