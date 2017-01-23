/**
  ******************************************************************************
  * File Name          : main.c
  * Description        : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f0xx_hal.h"
#include "usart.h"
#include "gpio.h"

/* USER CODE BEGIN Includes */
#include "stm32f0xx_it.h"
#include "ringbuf.h"
#include <stdlib.h>
#include "keypad.h"
#include "pin.h"
#include "pinled.h"
#define DELAY 500
#define DEBUG 0

/* USER CODE END Includes */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
void Error_Handler(void);

/* USER CODE BEGIN PFP */
/* Private function prototypes -----------------------------------------------*/
int openDoor(void);
int closeDoor(void);

/* USER CODE END PFP */

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

int main(void)
{

  /* USER CODE BEGIN 1 */
  /* USER CODE END 1 */

  /* MCU Configuration----------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* Configure the system clock */
  SystemClock_Config();

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();

  /* USER CODE BEGIN 2 */

  HAL_GPIO_WritePin(KEYBOARD_COL_0_GPIO_Port, KEYBOARD_COL_0_Pin, 0);
  HAL_GPIO_WritePin(KEYBOARD_COL_1_GPIO_Port, KEYBOARD_COL_1_Pin, 0);
  HAL_GPIO_WritePin(KEYBOARD_COL_2_GPIO_Port, KEYBOARD_COL_2_Pin, 0);
  HAL_GPIO_WritePin(RGB_BLUE_GPIO_Port, RGB_BLUE_Pin, 0);
  HAL_GPIO_WritePin(RGB_GREEN_GPIO_Port, RGB_GREEN_Pin, 0);
  HAL_GPIO_WritePin(RGB_RED_GPIO_Port, RGB_RED_Pin, 0);
  
  uint8_t pincode[] = {0,0,0,0,0,0,0,0, 0x00};
  uint8_t defpin[] = {'1', '1', '1', '1', '1', '1', '1', '1', 0x0};
  uint8_t servpin[] = {'3', '1', '4', '1', '5', '9', '2', '6', 0x0};
  
  resetLeds();

  uint8_t a = 0x00;
	uint8_t b[] = {0,0};
	uint8_t	tmpfile = 0;
  uint8_t *s = malloc(15);
  ringbuf_init(&rb);
  ringbuf_SendMessage(&rb, "Ready!\r\n > \0");
  
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
		HAL_UART_Receive_IT(&huart2, b, 1);
		if(b[0]) {
			ringbuf_SendMessage(&rb, "COMMAND:\n\r\0");
			Delay(50);
			ringbuf_SendMessage(&rb, b);
			b[0] = 0;
		}
		
		a = 0;
    if(DEBUG)
      ringbuf_SendMessage(&rb, "DEBUG MODE\r\n\0");
		
    a = checkKeypad();
    switch (a) {
      case NO_KEY:
        break;
      case KEY_STAR:
        getPinFromKeypad(pincode);
          ringbuf_SendMessage(&rb, pincode);
          if(!checkPins(pincode, defpin)) {
            openDoor();
            blinkLED();
            setLeds();
            Delay(2000);
            blinkLED();
            closeDoor();
          }
        break;
      case KEY_HASH:
        while (1) {
          a = checkKeypad();
            if(a == KEY_HASH) {
              getPinFromKeypad(pincode);
              if(checkPins(pincode, servpin)) {
                ringbuf_SendMessage(&rb, "Servpin correct. Enter new pin for doors:\r\n\0");
                getPinFromKeypad(defpin);
                ringbuf_SendMessage(&rb, defpin);
                ringbuf_SendMessage(&rb, "\r\n\0");
              }
            }
        }
        resetLeds();
        resetPin(pincode);
        break;
    }
    
      a = NO_KEY;
  }

  /* USER CODE END WHILE */

  /* USER CODE BEGIN 3 */

  /* USER CODE END 3 */

}

/** System Clock Configuration
*/
void SystemClock_Config(void)
{

  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_PeriphCLKInitTypeDef PeriphClkInit;

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = 16;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL12;
  RCC_OscInitStruct.PLL.PREDIV = RCC_PREDIV_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }

  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART2;
  PeriphClkInit.Usart2ClockSelection = RCC_USART2CLKSOURCE_PCLK1;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }

    /**Configure the Systick interrupt time 
    */
  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

    /**Configure the Systick 
    */
  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}

/* USER CODE BEGIN 4 */
int openDoor() {
  HAL_GPIO_WritePin(RELAY_IN_GPIO_Port, RELAY_IN_Pin, 0);
}
int closeDoor() {
  HAL_GPIO_WritePin(RELAY_IN_GPIO_Port, RELAY_IN_Pin, 1);
}


/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler */
  /* User can add his own implementation to report the HAL error return state */
  while(1) 
  {
  }
  /* USER CODE END Error_Handler */ 
}

#ifdef USE_FULL_ASSERT

/**
   * @brief Reports the name of the source file and the source line number
   * where the assert_param error has occurred.
   * @param file: pointer to the source file name
   * @param line: assert_param error line source number
   * @retval None
   */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
    ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */

}

#endif

/**
  * @}
  */ 

/**
  * @}
*/ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
