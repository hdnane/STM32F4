#include "led.h"

Led_Type led1;
Led_Type led2;

int main(void) {
    // Initialize USART2 for UART communication
    USART2_Init();
    
    // Test print statement to ensure UART is working
    printf("UART communication initialized successfully.\n\r");

    // Construct LED objects
    Led_ctor(&led2, BLUE, ON);
    Led_ctor(&led1, RED, OFF);

    // Get the current state of the LEDs
    Led_getState(&led1);
    Led_getState(&led2);

    // Set the state of led1 to ON
    Led_setState(&led1, ON);

    while (1) {
        // Main loop
    }

    return 0; 
}
