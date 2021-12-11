#include "GPIO.h"
#include "stm32f401xc.h"
#include "stm32f401cc_interface.h"
/* You are required to build a software that display a decimal counter value on a seven segment display. */
void delay(int secs);

int main(void)
{
    int i = 0;
    int counter = 0;
    // Common Cathode Configuration
    unsigned char lookup[10] = {
        0x3f, 0x06, 0x5b, 0x4f, 0x66,
        0x6d, 0x7d, 0x07, 0x7f, 0x6f};

    for (i = 0; i <= 6; i++)
    {
        // Configure 7-SEG pins
        GPIO_Init('A', i, OUTPUT, PUSH_PULL, NO_STATE);
    }

    // a function that takes a number from look up table
    while (1)
    {
        for (counter = 0; counter < 10; counter++)
        {
            for (i = 0; i <= 6; i++)
            {
                GPIO_WritePin('A', i, 0); //reset all pins
            }
            GPIO_WritePin('A', 0, lookup[counter]); //set
            delay(1000000);
        }
        counter = 0;
    }

    return 0;
}
void delay(int secs)
{
    for (int i = 0; i < secs; i++)
    {
    }
}
