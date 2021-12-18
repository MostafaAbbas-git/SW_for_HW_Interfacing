/*
 * Author : Abdullah Drwesh
 * Date   : 8/12/2021
 * Version: 1.0.0
 */

#ifndef KEYPAD_H
#define KEYPAD_H

void Keypad_Init();

void Keypad_Manage();

void KeypadCallouts_KeyPressNotificaton();

unsigned char Keypad_GetKey();

#endif /* KEYPAD_H */
