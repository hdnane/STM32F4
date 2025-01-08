#include "uart.h"


void USART2_Init(void){
	
// Enable clock access to USART2
RCC->APB1ENR |= 0x20000;  // This is correct

// Enable clock access to PortA
RCC->AHB1ENR |= 0x01;     // Use |= to avoid overwriting other bits

	
// Enable pins for alternate functions, PA2, PA3
GPIOA->MODER &= ~0x00F0;  // Clear MODER for PA2 and PA3
GPIOA->MODER |= 0x00A0;   // Set PA2 and PA3 to alternate function mode

// Configure type of alternate function
GPIOA->AFR[0] &= ~0xFF00; // Clear AFR settings
GPIOA->AFR[0] |= 0x7700;  // Set alternate function 7 (USART2) for PA2 and PA3

	

// Configure USART2
USART2->BRR = 0x0683;     // Set baud rate to 9600
USART2->CR1 = 0x000C;     // Enable Tx and Rx
USART2->CR2 = 0x0000;     // Default
USART2->CR3 = 0x0000;     // Default
USART2->CR1 |= 0x2000;    // Enable USART

	
}
int USART2_write(int ch){
	while(!(USART2->SR & 0x0080)){}
	USART2->DR = (ch & 0xFF);	
  
	return ch;		
}	

int USART2_read(void){
	while(!(USART2->SR & 0x0020)){}
	return USART2->DR;
		
	
}	
// Standard I/O library interface
struct _FILE {int handle;};
FILE __stdin = {0};
FILE __stdout = {1};
FILE __stderr = {2};

int fgetc(FILE *f) {
    int c;
    c = USART2_read();  // Read character from console
    if (c == '\r') {    // If carriage return, add newline
        USART2_write(c); 
        c = '\n';
    }
    USART2_write(c);    // Echo character
    return c;
}   

int fputc(int c, FILE *f) {
    return USART2_write(c); // Write character to console
}


int n;
char str[80];

void test_setup(void){
	printf("Please enter a number: ");
	scanf("%d", &n);
	printf("the number entered is: %d\r\n" ,n);
	printf("Please type a character string: ");
	gets(str);
	printf("the character string entered is: ");
	puts(str);
	printf("\r\n");
}
	
