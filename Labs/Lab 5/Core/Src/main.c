/*
 * Author : Abdullah Drwesh
 * Date   : 7/12/2021
 * Version: 1.0.0
 */
#include "GPIO.h"
#include "Keypad.h"

unsigned char sevenSegHex[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66,
                                 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

void KeypadCallouts_KeyPressNotificaton()
{
	// Get the pressed key value
    unsigned char value = Keypad_GetKey();
    // Display the pressed key on the seven segment
    for (unsigned char i = 0; i < 7; i++)
    {
        GPIO_WritePin('A', i, (sevenSegHex[value] & (1 << i)) >> i);
    }
}

int main(void)
{
    // initialization of seven-segment
    GPIO_EnableClock('A');
    for (unsigned char i = 0; i < 7; i++)
    {
        GPIO_Init('A', i, OUTPUT, PUSH_PULL);
    }

    // initialization of keypad
    Keypad_Init();

    while (1)
    {

        Keypad_Manage();
    }

    return 0;
}
