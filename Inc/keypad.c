#include "keypad.h"

uint8_t translateKeyToChar(int key) {
  return translateArray[key];
}
uint8_t checkKeypad() {
  uint8_t currKeycode = NO_KEY;
  
  HAL_GPIO_WritePin(KEYBOARD_COL_0_GPIO_Port, KEYBOARD_COL_0_Pin, 1);
  
  if(GPIO_SmartRead_Pin(KEYBOARD_ROW_0_GPIO_Port, KEYBOARD_ROW_0_Pin)) currKeycode = KEY_1;
  if(GPIO_SmartRead_Pin(KEYBOARD_ROW_1_GPIO_Port, KEYBOARD_ROW_1_Pin)) currKeycode = KEY_4;
  if(GPIO_SmartRead_Pin(KEYBOARD_ROW_2_GPIO_Port, KEYBOARD_ROW_2_Pin)) currKeycode = KEY_7;
  if(GPIO_SmartRead_Pin(KEYBOARD_ROW_3_GPIO_Port, KEYBOARD_ROW_3_Pin)) currKeycode = KEY_STAR;
  
  HAL_GPIO_WritePin(KEYBOARD_COL_0_GPIO_Port, KEYBOARD_COL_0_Pin, 0);
  
  HAL_GPIO_WritePin(KEYBOARD_COL_1_GPIO_Port, KEYBOARD_COL_1_Pin, 1);
  
  if(GPIO_SmartRead_Pin(KEYBOARD_ROW_0_GPIO_Port, KEYBOARD_ROW_0_Pin)) currKeycode = KEY_2;
  if(GPIO_SmartRead_Pin(KEYBOARD_ROW_1_GPIO_Port, KEYBOARD_ROW_1_Pin)) currKeycode = KEY_5;
  if(GPIO_SmartRead_Pin(KEYBOARD_ROW_2_GPIO_Port, KEYBOARD_ROW_2_Pin)) currKeycode = KEY_8;
  if(GPIO_SmartRead_Pin(KEYBOARD_ROW_3_GPIO_Port, KEYBOARD_ROW_3_Pin)) currKeycode = KEY_0;
  
  HAL_GPIO_WritePin(KEYBOARD_COL_1_GPIO_Port, KEYBOARD_COL_1_Pin, 0);
  
  HAL_GPIO_WritePin(KEYBOARD_COL_2_GPIO_Port, KEYBOARD_COL_2_Pin, 1);
  
  if(GPIO_SmartRead_Pin(KEYBOARD_ROW_0_GPIO_Port, KEYBOARD_ROW_0_Pin)) currKeycode = KEY_3;
  if(GPIO_SmartRead_Pin(KEYBOARD_ROW_1_GPIO_Port, KEYBOARD_ROW_1_Pin)) currKeycode = KEY_6;
  if(GPIO_SmartRead_Pin(KEYBOARD_ROW_2_GPIO_Port, KEYBOARD_ROW_2_Pin)) currKeycode = KEY_9;
  if(GPIO_SmartRead_Pin(KEYBOARD_ROW_3_GPIO_Port, KEYBOARD_ROW_3_Pin)) currKeycode = KEY_HASH;
  
  HAL_GPIO_WritePin(KEYBOARD_COL_2_GPIO_Port, KEYBOARD_COL_2_Pin, 0);
  
  return currKeycode;
  
}