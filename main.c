/*
 * Project S1_RTOS
 * Auther:Zhenfei Wang
 */


/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include <stdio.h>
#include <string.h>

void GPIO_Configuration(void);
void  Delay(uint32_t nCount);
void led(void);
void LCD_Delay(unsigned char i)
{
  while(i--);
}
int main(void)
{
      new_task(&led,1,0)
}

void led(void){
  uint8_t key;
  key = 5;

  GPIO_Configuration();
  key = 5;
  while (1)
  {
    GPIO_SetBits(GPIOF, GPIO_Pin_6);
    LCD_Delay(2);
    GPIO_ResetBits(GPIOF, GPIO_Pin_6);
    LCD_Delay(2);
    GPIO_SetBits(GPIOF,GPIO_Pin_7);
    LCD_Delay(1);
    GPIO_ResetBits(GPIO, GPIO_Pin_7);
    LCD_Delay(1);
  }
}

void GPIO_Configuration(void)
{
   GPIO_InitTypeDef GPIO_InitStructure;
  
  RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOF | RCC_APB2Periph_GPIOG , ENABLE);              
/**
 *  LED1 -> PF6 , LED2 -> PF7 , LED3 -> PF8 , LED4 -> PF9
 */          
  GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 
  GPIO_Init(GPIOF, &GPIO_InitStructure);

  /* Key */
  GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 
  GPIO_Init(GPIOC, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_6 | GPIO_Pin_8;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOG, &GPIO_InitStructure);
}

void Delay(uint32_t nCount)
{
  for(; nCount != 0; nCount--);
}


#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif
