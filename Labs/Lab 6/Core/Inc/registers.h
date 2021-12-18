/*
 * Lookup.h
 *
 *  Created on: Dec 18, 2021
 *      Author: mosta
 */

#ifndef INC_LOOKUP_H_
#define INC_LOOKUP_H_

#define GPIO_REG(PORT_ID, REG_ID) ((unsigned int *)(PORT_ID + REG_ID))

#define GPIOA_MODER GPIO_REG(GPIOA_Boundary, MODER_OFFSET)
#define GPIOA_OTYPER GPIO_REG(GPIOA_Boundary, OTYPER_OFFSET)
#define GPIOA_PUPDR GPIO_REG(GPIOA_Boundary, PUPDR_OFFSET)
#define GPIOA_IDR GPIO_REG(GPIOA_Boundary, IDR_OFFSET)
#define GPIOA_ODR GPIO_REG(GPIOA_Boundary, ODR_OFFSET)

#define GPIOB_MODER GPIO_REG(GPIOB_Boundary, MODER_OFFSET)
#define GPIOB_OTYPER GPIO_REG(GPIOB_Boundary, OTYPER_OFFSET)
#define GPIOB_PUPDR GPIO_REG(GPIOB_Boundary, PUPDR_OFFSET)
#define GPIOB_IDR GPIO_REG(GPIOB_Boundary, IDR_OFFSET)
#define GPIOB_ODR GPIO_REG(GPIOB_Boundary, ODR_OFFSET)

#define RCC_AHB1ENR GPIO_REG(RCC_Boundary, AHB1ENR_OFFSET)

// Boundaries
#define GPIOA_Boundary 0x40020000
#define GPIOB_Boundary 0x40020400
#define GPIOC_Boundary 0x40020800
#define GPIOD_Boundary 0x40020C00
#define GPIOE_Boundary 0x40021000
#define GPIOH_Boundary 0x40021C00
#define CRC_Boundary 0x40023000
#define RCC_Boundary 0x40023800

// OFFSET
#define MODER_OFFSET 0x00
#define OTYPER_OFFSET 0x04
#define OSPEEDR_OFFSET 0x08
#define PUPDR_OFFSET 0x0C
#define IDR_OFFSET 0x10
#define ODR_OFFSET 0x14
#define BSRR_OFFSET 0x18
#define LCKR_OFFSET 0x1C
#define AFRL_OFFSET 0x20
#define AFRH_OFFSET 0x24
#define AHB1ENR_OFFSET 0x30

#define CLOCK 0
#define MODER 1
#define OTYPER 2
#define PUPDR 3
#define IDR 4
#define ODR 5
#define OSPEEDR 6
#define BSRR 7
#define LCKR 8
#define AFRL 9
#define AFRH 10

unsigned int *LookUp[2][6] = {
    {RCC_AHB1ENR, GPIOA_MODER, GPIOA_OTYPER, GPIOA_PUPDR, GPIOA_IDR, GPIOA_ODR},

    {RCC_AHB1ENR, GPIOB_MODER, GPIOB_OTYPER, GPIOB_PUPDR, GPIOB_IDR, GPIOB_ODR}};

#endif /* INC_LOOKUP_H_ */
