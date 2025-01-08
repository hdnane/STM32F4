#include "uart.h"

void USART2_Init(void) {
    // Enable clock access to USART2
    RCC->APB1ENR |= 0x20000;

    // Enable clock access to PortA
    RCC->AHB1ENR |= 0x01;

    // Enable pins for alternate functions, PA2, PA3
    GPIOA->MODER &= ~0x00F0;
    GPIOA->MODER |= 0x00A0;  // Enable alt. function for PA2, PA3

    // Configure type of alternate function
    GPIOA->AFR[0] &= ~0xFF00;
    GPIOA->AFR[0] |= 0x7700;

    // Configure USART2
    USART2->BRR = 0x0683;   // Set baud rate to 9600
    USART2->CR1 = 0x000C;   // Enable Tx and Rx
    USART2->CR2 = 0x0000;   // Default
    USART2->CR3 = 0x0000;   // Default
    USART2->CR1 |= 0x2000;  // Enable USART
}

int USART2_write(int ch) {
    while (!(USART2->SR & 0x0080)) {}  // Wait until Tx is ready
    USART2->DR = (ch & 0xFF);         // Write data
    return ch;
}

// Standard I/O library interface
struct _FILE {int handle;};
FILE __stdin = {0};
FILE __stdout = {1};
FILE __stderr = {2};

int fputc(int c, FILE *f) {
    return USART2_write(c); // Write character to console
}
