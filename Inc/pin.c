#include "pin.h"

int getPinFromKeypad(uint8_t *pin) {
  
}

int resetPin(uint8_t * pin) {
  memset(pin, 0x00, MAXPINSIZE);
  return 1;
}

int checkPinSize(uint8_t *pin) {
  return strlen(pin);
}

int checkPins(uint8_t *first, uint8_t *second, uint32_t size) {
  int i = 0;
  for(i; i < size; i++) {
    if(first[i] != second[i]) return 0;
    first[i] = 0;
  }
  return 1; 
}