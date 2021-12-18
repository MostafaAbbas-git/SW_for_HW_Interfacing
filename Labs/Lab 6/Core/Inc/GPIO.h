/*
 * Author : Abdullah Drwesh
 * Date   : 7/12/2021
 * Version: 1.0.0
 */
#ifndef GPIO_H
#define GPIO_H

// Ports
#define PORTA 'A'
#define PORTB 'B'

// Result status
#define OK ((unsigned char)0)
#define NOK ((unsigned char)1)

// Pin value
#define LOW 0
#define HIGH 1

// Mode types
#define INPUT ((unsigned char)0x00)
#define OUTPUT ((unsigned char)0x01)
#define ALTERNATE_FUN ((unsigned char)0x02)
#define ANALOG ((unsigned char)0x03)

// Output modes
#define PUSH_PULL ((unsigned char)0x00)
#define OPEN_DRAIN ((unsigned char)0x01)

// Resistor modes
#define NO_PULL ((unsigned char)0x00)
#define PULL_UP ((unsigned char)0x02)
#define PULL_DOWN ((unsigned char)0x04)

void GPIO_EnableClock(unsigned char PortId);

void GPIO_Init(unsigned char PortId, unsigned char PinNum, unsigned char PinDir,
               unsigned char DefaultState);
unsigned char GPIO_WritePin(unsigned char PortId, unsigned char PinNum,
                            unsigned char Data);

unsigned char GPIO_ReadPin(unsigned char PortId, unsigned char PinNum);

#endif /* GPIO_H */
