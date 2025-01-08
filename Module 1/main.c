#include "uart.h"

int main() {
    USART2_Init();  // Initialize USART2
    
    // Example of using custom write and read functions
    USART2_write('H');
    USART2_write('e');
    USART2_write('l');
    USART2_write('l');
    USART2_write('o');

	 
    
    while (1) {
        int received_char = USART2_read();  // Read a character from UART
        USART2_write(received_char);        // Echo the received character
    }
}
