#include "led.h"

void Led_ctor(Led_Type * const pr, LedColor_Type _color, LedState_Type _state) {
    pr->color = _color;
    pr->state = _state;

    // Hardware Init
    RCC->AHB1ENR |= LED_PORT_CLOCK;

    switch (_color) {
        case RED:
            LED_PORT->MODER |= LED_RED_MODE_BIT;
            Set_LED_State(LED_PORT, LED_RED_PIN, pr->state, "Red");
            break;
        case YELLOW:
            LED_PORT->MODER |= LED_YELLOW_MODE_BIT;
            Set_LED_State(LED_PORT, LED_YELLOW_PIN, pr->state, "Yellow");
            break;
        case BLUE:
            LED_PORT->MODER |= LED_BLUE_MODE_BIT;
            Set_LED_State(LED_PORT, LED_BLUE_PIN, pr->state, "Blue");
            break;
        case GREEN:
            LED_PORT->MODER |= LED_GREEN_MODE_BIT;
            Set_LED_State(LED_PORT, LED_GREEN_PIN, pr->state, "Green");
            break;
    }
}

void Led_setState(Led_Type * const pr, LedState_Type _state) {
    pr->state = _state;

    switch (pr->color) {
        case RED:
            Set_LED_State(LED_PORT, LED_RED_PIN, pr->state, "Red");
            break;
        case YELLOW:
            Set_LED_State(LED_PORT, LED_YELLOW_PIN, pr->state, "Yellow");
            break;
        case BLUE:
            Set_LED_State(LED_PORT, LED_BLUE_PIN, pr->state, "Blue");
            break;
        case GREEN:
            Set_LED_State(LED_PORT, LED_GREEN_PIN, pr->state, "Green");
            break;
    }
}

LedState_Type Led_getState(Led_Type * const pr) {
    const char *color_name;
    switch (pr->color) {
        case RED:
            color_name = "Red";
            break;
        case YELLOW:
            color_name = "Yellow";
            break;
        case BLUE:
            color_name = "Blue";
            break;
        case GREEN:
            color_name = "Green";
            break;
    }
    printf("The %s LED is currently %d\n\r", color_name, pr->state);
    return pr->state;
}

void Set_LED_State(GPIO_TypeDef *port, uint32_t pin, LedState_Type state, const char *color) {
    if (state == ON) {
        port->ODR |= pin;
        printf("The %s LED is set ON\n\r", color);
    } else {
        port->ODR &= ~pin;
        printf("The %s LED is set OFF\n\r", color);
    }
}
