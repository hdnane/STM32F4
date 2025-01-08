#ifndef LED_H
#define LED_H

#include <stdint.h>
#include "uart.h"
#include "stm32f4xx.h"

#define LED_PORT   GPIOB

#define LED_PORT_CLOCK    (1u<<1)

#define LED_RED_PIN         (1u<<14)
#define LED_GREEN_PIN       (1u<<12)
#define LED_BLUE_PIN        (1u<<15)
#define LED_YELLOW_PIN      (1u<<13)

#define LED_RED_MODE_BIT    (1u<<28)
#define LED_GREEN_MODE_BIT  (1u<<24)
#define LED_YELLOW_MODE_BIT (1u<<26)
#define LED_BLUE_MODE_BIT   (1u<<30)

typedef enum {
    RED = 0,
    GREEN,
    YELLOW,
    BLUE
} LedColor_Type;

typedef enum {
    OFF = 0,
    ON = 1
} LedState_Type;

typedef struct {
    LedColor_Type color;
    LedState_Type state;
    uint32_t last_update;
} Led_Type;

void Led_ctor(Led_Type * const pr, LedColor_Type _color, LedState_Type _state);
void Led_setState(Led_Type * const pr, LedState_Type _state);
LedState_Type Led_getState(Led_Type * const pr);
void Set_LED_State(GPIO_TypeDef *port, uint32_t pin, LedState_Type state, const char *color);

#endif // LED_H
