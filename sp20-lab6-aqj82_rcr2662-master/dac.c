// dac.c
// This software configures DAC output
// Lab 6 requires a minimum of 4 bits for the DAC, but you could have 5 or 6 bits
// Runs on LM4F120 or TM4C123
// Program written by: put your names here
// Date Created: 3/6/17 
// Last Modified: 1/17/2020 
// Lab number: 6
// Hardware connections
/* 
DAC bit 0 = PB0
DAC bit 1 = PB1
DAC bit 2 = PB2
DAC bit 3 = PB3

Piano keys
key 0 = PE0
key 1 = PE1
key 2 = PE2
key 3 = PE3
*/

#include <stdint.h>
#include "../inc/tm4c123gh6pm.h"
// Code files contain the actual implemenation for public functions
// this file also contains an private functions and private data

// **************DAC_Init*********************
// Initialize 4-bit DAC, called once 
// Input: none
// Output: none
void DAC_Init(void){
	SYSCTL_RCGCGPIO_R |= 0x02;
	uint32_t delay = 0;
	GPIO_PORTB_DIR_R |= 0xF;
	GPIO_PORTB_DEN_R |= 0xF;
}

// **************DAC_Out*********************
// output to DAC
// Input: 4-bit data, 0 to 15 
// Input=n is converted to n*3.3V/15
// Output: none
void DAC_Out(uint32_t data){
	GPIO_PORTB_DATA_R = data & 0xF;
}
