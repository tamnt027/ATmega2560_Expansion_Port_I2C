#ifndef Pins_Define_h
#define Pins_Define_h

#include <pins_arduino.h>
#include "defines.h"

#if (ACTIVE_BOARD == BOARD_ATMEGA2560)
#define PIN_D2 (2)
#define PIN_D3 (3)
#define PIN_D4 (4)
#define PIN_D5 (5)
#define PIN_D6 (6)
#define PIN_D7 (7)
#define PIN_D8 (8)
#define PIN_D9 (9)
#define PIN_D10 (10)
#define PIN_D11 (11)
#define PIN_D12 (12)
#define PIN_D13 (13)
#define PIN_D22 (22)
#define PIN_D23 (23)
#define PIN_D24 (24)
#define PIN_D25 (25)
#define PIN_D26 (26)
#define PIN_D27 (27)
#define PIN_D28 (28)
#define PIN_D29 (29)
#define PIN_D30 (30)
#define PIN_D31 (31)
#define PIN_D32 (32)
#define PIN_D33 (33)
#define PIN_D34 (34)
#define PIN_D35 (35)
#define PIN_D36 (36)
#define PIN_D37 (37)
#define PIN_D38 (38)
#define PIN_D39 (39)
#define PIN_D40 (40)
#define PIN_D41 (41)
#define PIN_D42 (42)
#define PIN_D43 (43)
#define PIN_D44 (44)
#define PIN_D45 (45)
#define PIN_D46 (46)
#define PIN_D47 (47)
#define PIN_D48 (48)
#define PIN_D49 (49)
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
// D4; D5; D6; D7; D8; D9; D10; D11; D12.

#define PIN_PWM_1 PIN_D4
#define PIN_PWM_2 PIN_D5
#define PIN_PWM_3 PIN_D6
#define PIN_PWM_4 PIN_D7
#define PIN_PWM_5 PIN_D8
#define PIN_PWM_6 PIN_D9
#define PIN_PWM_7 PIN_D10
#define PIN_PWM_8 PIN_D11
#define PIN_PWM_9 PIN_D12

#define PIN_ANALOG_INPUT_1 A0
#define PIN_ANALOG_INPUT_2 A1
#define PIN_ANALOG_INPUT_3 A2
#define PIN_ANALOG_INPUT_4 A3
#define PIN_ANALOG_INPUT_5 A4
#define PIN_ANALOG_INPUT_6 A5
#define PIN_ANALOG_INPUT_7 A6
#define PIN_ANALOG_INPUT_8 A7
#define PIN_ANALOG_INPUT_9 A8

#define PIN_DIGITAL_1 PIN_D22
#define PIN_DIGITAL_2 PIN_D23
#define PIN_DIGITAL_3 PIN_D24
#define PIN_DIGITAL_4 PIN_D25
#define PIN_DIGITAL_5 PIN_D26
#define PIN_DIGITAL_6 PIN_D27
#define PIN_DIGITAL_7 PIN_D28
#define PIN_DIGITAL_8 PIN_D29
#define PIN_DIGITAL_9 PIN_D39
#define PIN_DIGITAL_10 PIN_D34
#define PIN_DIGITAL_11 PIN_D35
#define PIN_DIGITAL_12 PIN_D36
#define PIN_DIGITAL_13 PIN_D37
#define PIN_DIGITAL_14 PIN_D40
#define PIN_DIGITAL_15 PIN_D41
#define PIN_DIGITAL_16 PIN_D38
#define PIN_DIGITAL_17 PIN_D42
#define PIN_DIGITAL_18 PIN_D43
#define PIN_DIGITAL_19 PIN_D44
#define PIN_DIGITAL_20 PIN_D45
#define PIN_DIGITAL_21 PIN_D46
#define PIN_DIGITAL_22 PIN_D47
#define PIN_DIGITAL_23 PIN_D48
#define PIN_DIGITAL_24 PIN_D49
#define PIN_DIGITAL_25 PIN_D3


#elif (ACTIVE_BOARD == BOARD_ESP32_DEVKIT_V1)
#define LED_BUILTIN 5
#define PIN_LED_OPERATE 2  

#define SDA_PIN 21
#define SCL_PIN 22
#endif


#define PIN_HARD_RESET PIN_D13

#define FLOW_INTERUPT_CHANGE_TYPE FALLING

#endif