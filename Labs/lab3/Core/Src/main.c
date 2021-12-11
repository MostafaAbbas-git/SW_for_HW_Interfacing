#include "stm32f401cc_interface.h"

int main(void) {

	// enable clock (GPIOAEN)
	RCC_AHB1ENR |= 1<<0;
	// PAO output
	GPIOA_MODER |= 1<<0;
	//push-pull output
	GPIOA_OTYPER &= ~(1<<0);

  while (1) {
	  int i;
	  int seconds = 1000000;
	  GPIOA_ODR |= 1<<0; //set
	  //delay 1 second.
	  for(i=0; i<seconds; i++) {}

	  GPIOA_ODR &= ~(1<<0); //clear

	  for(i=0; i<seconds; i++) {}

  }
  return 0;
}
