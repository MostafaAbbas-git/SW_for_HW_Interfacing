/*
 * Author : Abdullah Drwesh
 * Date   : 7/12/2021
 * Version: 1.0.0
 */

#include "GPIO.h"
#include "registers.h"

#define _OUTTYPE_MASK ((unsigned char)0x01)
#define _OUTTYPE_SHIFT 0

#define _PUPD_MASK ((unsigned char)0x06)
#define _PUPD_SHIFT 1

void GPIO_EnableClock(unsigned char PortId)
{
  PortId -= 'A';
  *LookUp[PortId][CLOCK] |= (0x01 << PortId); // Enable Clock
}

void GPIO_Init(unsigned char PortId, unsigned char PinNum, unsigned char PinMode, unsigned char DefaultState)
{
  // GPIO_Init('A', i, OUTPUT, PUSH_PULL);

  PortId -= 'A';

  *LookUp[PortId][MODER] &= ~(0x03 << 2 * PinNum);
  *LookUp[PortId][MODER] |= PinMode << 2 * PinNum;

  *LookUp[PortId][OTYPER] &= ~(1 << PinNum);
  *LookUp[PortId][OTYPER] |= ((DefaultState & _OUTTYPE_MASK) >> _OUTTYPE_SHIFT) << PinNum;

  *LookUp[PortId][PUPDR] &= ~(0x03 << 2 * PinNum);
  *LookUp[PortId][PUPDR] |= ((DefaultState & _PUPD_MASK) >> _PUPD_SHIFT) << (2 * PinNum);
}

unsigned char GPIO_WritePin(unsigned char PortId, unsigned char PinNum, unsigned char Data)
{
  unsigned char result;
  PortId -= 'A'; //   result = 0 or 1
  if (((*LookUp[PortId][MODER] & (0x03 << 2 * PinNum)) >> (2 * PinNum)) == 1)
  {
    if (Data)
    {
      *LookUp[PortId][ODR] |= (1 << PinNum);
    }
    else
    {
      *LookUp[PortId][ODR] &= ~(1 << PinNum);
    }
    result = OK;
  }
  else
  {
    result = NOK;
  }
  return result;
}

unsigned char GPIO_ReadPin(unsigned char PortId, unsigned char PinNum)
{
  PortId -= 'A'; //   result = 0 or 1
  unsigned char data = 0;

  data = (*LookUp[PortId][IDR] & (1 << PinNum)) >> PinNum;

  return data;
}
