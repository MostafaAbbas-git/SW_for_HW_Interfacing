/*
 * Author : Abdullah Drwesh
 * Date   : 8/12/2021
 * Version: 1.0.0
 */
#include "Keypad.h"
#include "GPIO.h"
#include "stm32f401cc_interface.h"

unsigned char Keypad_Pressed_Value;
unsigned char buttonState = 0;
unsigned char Keypad_Matrix[4][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {0, 0, 0}};

void delay30ms()
{
    for (unsigned int i = 0; i < 30000; i++)
    {
    }
}

void Keypad_Init()
{
    unsigned char i;
    GPIO_EnableClock('B');

    // Columns as output
    for (i = 0; i < 3; i++)
    {
        GPIO_Init('B', i, OUTPUT, PUSH_PULL);
    }
    // Rows as input
    for (i = 3; i < 7; i++)
    {
        GPIO_Init('B', i, INPUT, PULL_UP);
    }
}

void Keypad_Manage()
{
    unsigned char i;
    unsigned char j;
    if (buttonState == 0)
    {
        for (i = 0; i < 3; i++)
        {
            // Reset 1 column and set the others
            GPIO_WritePin('B', i % 3, 0);
            GPIO_WritePin('B', (i + 1) % 3, 1);
            GPIO_WritePin('B', (i + 2) % 3, 1);

            for (j = 3; j < 7; j++)
            {
                // Read input pins
                if (GPIO_ReadPin('B', j) == 0)
                {
                    delay30ms();
                    if (GPIO_ReadPin('B', j) == 0)
                    {
                        // Change buttonState
                        buttonState = 1;
                        // Store the pressed key value
                        Keypad_Pressed_Value = Keypad_Matrix[j - 3][i];
                        KeypadCallouts_KeyPressNotificaton();
                    }
                }
            }
        }
    }
}

unsigned char Keypad_GetKey()
{
    // Change buttonState
    buttonState = 0;
    // Return the pressed key value
    return Keypad_Pressed_Value;
}
