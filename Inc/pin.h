#ifndef __PIN_H
#define __PIN_H
#include <stdint.h>
#include <string.h>

#define MAXPINSIZE 8

int getPinFromKeypad(uint8_t pin[]);
int resetPin(uint8_t pin[]);
int checkPinSize(uint8_t pin[]);
int checkPins(uint8_t *first, uint8_t *second);

#endif /* __PIN_H */