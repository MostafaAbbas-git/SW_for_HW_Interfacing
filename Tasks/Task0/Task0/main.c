#include "stm32f4xx.h"

int main()
{
    // Activating CLOCK
    __HAL_RCC_GPIOB_CLK_ENABLE();

    // define a variable to get the state 
    GPIO_PinState state;

    // LED
    GPIO_InitTypeDef LED;
    LED.Mode = GPIO_MODE_OUTPUT_PP;
    LED.Pin = GPIO_PIN_2;
    HAL_GPIO_Init(GPIOB, &LED); // PB2

    // Button
    GPIO_InitTypeDef BTN;
    BTN.Mode = GPIO_MODE_INPUT;
    BTN.Pin = GPIO_PIN_0;
    HAL_GPIO_Init(GPIOB, &BTN); // PB2

    while (1)
    {
        state = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0); // PB0 (holding the button)
        if (state)
        {
            // Turn on LED
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_SET);
        }
        else
        {
            //// Turn off LED
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_RESET);
        }
    }
}
