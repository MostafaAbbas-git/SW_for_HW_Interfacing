#include "stm32f401cc_interface.h"
#include "GPIO.h"

//#define RESET_BIT(var, bit) var &= ~(0x01 << bit);
//#define SET_BIT(var, bit) var |= (0x01 << bit);
//#define ASSIGN_TWO_BITS(var, bit, value) \
//    var &= ~(0x03 << 2 * bit);           \
//    var |= (value << 2 * bit);

void delay(int secs);
void color_mix(int color);

int main()
{
    int i;

    // Configure PB5->PB7 pins of as digital output pins
    for (i = 5; i <= 7; i++)
    {
        GPIO_Init('B', i, OUTPUT, PUSH_PULL, NO_STATE);
    }

    /* Configure PB3 as a digital input pin */
    GPIO_Init('B', 3, INPUT, PUSH_PULL, PULL_UP);

    int color = 1;
    // initial state for the LED: TURN ALL ON
    while (1)

    {
        char state = GPIO_ReadPin('B', 3);
        delay(1000);

        // Check current state of the button to change the color if it's pressed.
        if (state && !GPIO_ReadPin('B', 3))
        {
            color_mix((color) % 8);
            color++;
        }
    }
    return 0;
}

void delay(int time)
{
    while (time--)
    {
    }
}
void color_mix(int color)
{
    // Reset(clear) all pins
    GPIOB_ODR &= ~(7 << 5);

    // Set to new color
    GPIO_WritePin('B', 5, color);
}
