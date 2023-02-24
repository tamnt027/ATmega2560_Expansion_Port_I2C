#ifndef Pins_Define_h
#define Pins_Define_h

#include <pins_arduino.h>
#include "defines.h"

#if (ACTIVE_BOARD == BOARD_ATMEGA2560)
#define PIN_D13 (13)
#define PIN_D22 (22)
#define PIN_D30 (30)
#define PIN_D31 (31)
#define PIN_D32 (32)
#define PIN_D33 (33)
#define PIN_D50 (50)
#define PIN_D51 (51)
#define PIN_D52 (52)
#define PIN_D53 (53)
#elif (ACTIVE_BOARD == BOARD_ESP32_DEVKIT_V1)

    #define PIN_D3 (3)
    #define PIN_D4 (4)
    #define PIN_D13 (13)
    #define PIN_D16 (16)
    #define PIN_D17 (17)
    #define PIN_D18 (18)
    #define PIN_D19 (19)
    #define PIN_D21 (21)
    #define PIN_D22 (22)
    #define PIN_D23 (23)
    #define PIN_D25 (25)
    #define PIN_D26 (26)
    #define PIN_D27 (27)
    #define PIN_D32 (32)
    #define PIN_D33 (33)
#endif



#if (ACTIVE_BOARD == BOARD_ATMEGA2560)
    #define PIN_ADDR_0 PIN_D30
    #define PIN_ADDR_1 PIN_D31
    #define PIN_ADDR_2 PIN_D32
    #define PIN_ADDR_3 PIN_D33
#endif

#define IC2_ADDR_START_AT (0x30)


#if (ACTIVE_BOARD == BOARD_ESP32_DEVKIT_V1)
    	// 4; 13; 16; 17; 18; 19; 23; 25; 26; 27; 32; 33
    #define PIN_INTERUPT_FLOW_1 PIN_D4
    #define PIN_INTERUPT_FLOW_2 PIN_D13
    #define PIN_INTERUPT_FLOW_3 PIN_D16
    #define PIN_INTERUPT_FLOW_4 PIN_D17
    #define PIN_INTERUPT_FLOW_5 PIN_D18
    #define PIN_INTERUPT_FLOW_6 PIN_D19
    #define PIN_INTERUPT_FLOW_7 PIN_D23
    #define PIN_INTERUPT_FLOW_8 PIN_D25
    #define PIN_INTERUPT_FLOW_9 PIN_D26
    #define PIN_INTERUPT_FLOW_10 PIN_D27
    #define PIN_INTERUPT_FLOW_11 PIN_D32
    #define PIN_INTERUPT_FLOW_12 PIN_D33

#endif 


#if (ACTIVE_BOARD == BOARD_ATMEGA2560)
// Set LOW TO light
#define PIN_LED_OPERATE LED_BUILTIN  

#elif (ACTIVE_BOARD == BOARD_ESP32_DEVKIT_V1)
#define LED_BUILTIN 5
#define PIN_LED_OPERATE 2  

#define SDA_PIN 21
#define SCL_PIN 22
#endif


#define PIN_HARD_RESET PIN_D13

#define FLOW_INTERUPT_CHANGE_TYPE FALLING

#endif