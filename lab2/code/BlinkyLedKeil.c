/*-------------------------------------------------------
 * Name:     BlinkyLedKeil.c
 * Purpose:  LED PG7 Flasher for MCBSTM32F200
 *------------------------------------------------------*/
 
#include "stm32f2xx.h" // Gives neames for STM32 register and peripherals

void delay()
{
    unsigned long i;
    i = 0;
    for(i = 0; i < 2000000; i++) {}
}

int main()
{
    RCC->AHB1ENR = 1ul << 6;
    GPIOG->MODER = (GPIOG->MODER & ~(1ul << 15)) | (1ul << 14);

    for(;;)
    {
        GPIOG->ODR = 1ul << 7;
        delay();
        GPIOG->ODR &= ~(1ul << 7);
        delay();
    }
}