/**
  ******************************************************************************
  * File Name          : main.h
  * Description        : This file contains the common defines of the application
  ******************************************************************************
  *
  * COPYRIGHT(c) 2017 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H
  /* Includes ------------------------------------------------------------------*/

/* USER CODE BEGIN Includes */
#include "ringbuf.h"

/* USER CODE END Includes */

/* Private define ------------------------------------------------------------*/

#define B1_Pin GPIO_PIN_13
#define B1_GPIO_Port GPIOC
#define KEYBOARD_ROW_0_Pin GPIO_PIN_0
#define KEYBOARD_ROW_0_GPIO_Port GPIOC
#define KEYBOARD_ROW_1_Pin GPIO_PIN_1
#define KEYBOARD_ROW_1_GPIO_Port GPIOC
#define KEYBOARD_COL_2_Pin GPIO_PIN_3
#define KEYBOARD_COL_2_GPIO_Port GPIOC
#define KEYBOARD_COL_1_Pin GPIO_PIN_0
#define KEYBOARD_COL_1_GPIO_Port GPIOA
#define KEYBOARD_COL_0_Pin GPIO_PIN_1
#define KEYBOARD_COL_0_GPIO_Port GPIOA
#define USART_TX_Pin GPIO_PIN_2
#define USART_TX_GPIO_Port GPIOA
#define USART_RX_Pin GPIO_PIN_3
#define USART_RX_GPIO_Port GPIOA
#define KEYBOARD_ROW_3_Pin GPIO_PIN_4
#define KEYBOARD_ROW_3_GPIO_Port GPIOA
#define LD2_Pin GPIO_PIN_5
#define LD2_GPIO_Port GPIOA
#define RELAY_IN_Pin GPIO_PIN_5
#define RELAY_IN_GPIO_Port GPIOC
#define KEYBOARD_ROW_2_Pin GPIO_PIN_0
#define KEYBOARD_ROW_2_GPIO_Port GPIOB
#define DOOR_SENSOR_Pin GPIO_PIN_2
#define DOOR_SENSOR_GPIO_Port GPIOB
#define PINLED_G2_Pin GPIO_PIN_12
#define PINLED_G2_GPIO_Port GPIOB
#define PINLED_G1_Pin GPIO_PIN_13
#define PINLED_G1_GPIO_Port GPIOB
#define PINLED_G0_Pin GPIO_PIN_14
#define PINLED_G0_GPIO_Port GPIOB
#define PINLED_R0_Pin GPIO_PIN_15
#define PINLED_R0_GPIO_Port GPIOB
#define RGB_RED_Pin GPIO_PIN_6
#define RGB_RED_GPIO_Port GPIOC
#define RGB_BLUE_Pin GPIO_PIN_7
#define RGB_BLUE_GPIO_Port GPIOC
#define RGB_GREEN_Pin GPIO_PIN_8
#define RGB_GREEN_GPIO_Port GPIOC
#define PINLED_G3_Pin GPIO_PIN_8
#define PINLED_G3_GPIO_Port GPIOA
#define PINLED_G4_Pin GPIO_PIN_9
#define PINLED_G4_GPIO_Port GPIOA
#define PINLED_G5_Pin GPIO_PIN_10
#define PINLED_G5_GPIO_Port GPIOA
#define PINLED_G6_Pin GPIO_PIN_11
#define PINLED_G6_GPIO_Port GPIOA
#define PINLED_G7_Pin GPIO_PIN_12
#define PINLED_G7_GPIO_Port GPIOA
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
/* USER CODE BEGIN Private defines */


/* USER CODE END Private defines */

/**
  * @}
  */ 

/**
  * @}
*/ 

#endif /* __MAIN_H */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
