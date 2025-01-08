#ifndef __UART_H
#define __UART_H

#include "stm32f4xx.h"
#include <stdio.h>

// Function to initialize USART2
void USART2_Init(void);

// Function to write a character to USART2
int USART2_write(int ch);

// Function to read a character from USART2
int USART2_read(void);

// Test setup function
void test_setup(void);

#endif // __UART_H
