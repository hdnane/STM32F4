#include "uart.h"

int main() {
    // Initialize USART2 for UART communication
    USART2_Init();  

    // Send "Hello" and a newline character
    const char* msg = "Hello \n";
    for (int i = 0; msg[i] != '\0'; i++) {
        USART2_write(msg[i]);
    }

    // Main loop: Read characters from UART and echo them back
    while (1) {
        int received_char = USART2_read();  // Read a character from UART
        USART2_write(received_char);        // Echo the received character
    }

    return 0; // Although this line will never be reached, it's good practice to include it
}
