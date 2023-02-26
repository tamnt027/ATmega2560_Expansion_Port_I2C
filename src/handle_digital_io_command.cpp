#include "handle_digital_io_command.h"

#include <Arduino.h>
#include "pins_define.h"

extern unsigned char receivingBuffer[128];
extern unsigned char sendingBuffer[128];
extern byte receivingLength;
extern byte sendingLength;

extern bool isResponseReady;

extern uint32_t digitalPinModeBits;  // Bit 0, output , 1 input
extern uint32_t digitalPinValueBits; // Bit 0 low, Bit 1 high


#if (ACTIVE_BOARD == BOARD_ATMEGA2560)
byte digitalPinList[PIN_DIGITAL_NUM] = { PIN_DIGITAL_1,  PIN_DIGITAL_2,  PIN_DIGITAL_3,  PIN_DIGITAL_4,  PIN_DIGITAL_5,
                            PIN_DIGITAL_6,  PIN_DIGITAL_7,  PIN_DIGITAL_8,  PIN_DIGITAL_9,  PIN_DIGITAL_10,
                            PIN_DIGITAL_11, PIN_DIGITAL_12, PIN_DIGITAL_13, PIN_DIGITAL_14, PIN_DIGITAL_15,
                            PIN_DIGITAL_16, PIN_DIGITAL_17, PIN_DIGITAL_18, PIN_DIGITAL_19, PIN_DIGITAL_20,
                            PIN_DIGITAL_21, PIN_DIGITAL_22, PIN_DIGITAL_23, PIN_DIGITAL_24, PIN_DIGITAL_25 };
#else
byte digitalPinList[PIN_DIGITAL_NUM] = {};
#endif

void getDigitalPinMode(){
    if (receivingLength != 2) {  // check if request length is valid
        sendingBuffer[0] = RESPONSE_BAD_REQUEST;
        sendingLength = 1;
        isResponseReady = true;
        return;
    }

    byte pin = receivingBuffer[1];
    bool isPinValid = false;
    int pin_index = 0;
    for (pin_index = 0; pin_index < PIN_DIGITAL_NUM; pin_index++)
    {
        if (pin == digitalPinList[pin_index]){
            isPinValid = true;
            break;
        }
    }

    if (isPinValid) {

        sendingBuffer[0] = RESPONSE_OK;
        sendingBuffer[1] = (bool)(digitalPinModeBits & (1 << pin_index));
        sendingLength = 2;
        isResponseReady = true;

    }
    else{  // Invalid pin
        sendingBuffer[0] = RESPONSE_FAIL;
        sendingLength = 1;
        isResponseReady = true;
        return;
    }   
}

void setDigitalPinMode(){
    if (receivingLength != 3) {  // check if request length is valid
        sendingBuffer[0] = RESPONSE_BAD_REQUEST;
        sendingLength = 1;
        isResponseReady = true;
        return;
    }

    byte pin = receivingBuffer[1];
    byte mode = receivingBuffer[2];

    bool isPinValid = false;
    int pin_index = 0;
    for (pin_index = 0; pin_index < PIN_DIGITAL_NUM; pin_index++)
    {
        if (pin == digitalPinList[pin_index]){
            isPinValid = true;
            break;
        }
    }

    if (isPinValid) {

        if (mode == 1) {  // Input
            digitalPinModeBits = digitalPinModeBits | (1 << pin_index);
            pinMode(digitalPinList[pin_index], INPUT);
        }else
        {
            digitalPinModeBits = digitalPinModeBits & (~(1 << pin_index));
            pinMode(digitalPinList[pin_index], OUTPUT);
        }

        sendingBuffer[0] = RESPONSE_OK;
        sendingLength = 1;
        isResponseReady = true;

    }
    else{  // Invalid pin
        sendingBuffer[0] = RESPONSE_FAIL;
        sendingLength = 1;
        isResponseReady = true;
        return;
    }   
}

void getDigitalPinValue(){
    if (receivingLength != 2) {  // check if request length is valid
        sendingBuffer[0] = RESPONSE_BAD_REQUEST;
        sendingLength = 1;
        isResponseReady = true;
        return;
    }

    byte pin = receivingBuffer[1];
    bool isPinValid = false;
    int pin_index = 0;
    for (pin_index = 0; pin_index < PIN_DIGITAL_NUM; pin_index++)
    {
        if (pin == digitalPinList[pin_index]){
            isPinValid = true;
            break;
        }
    }

    if (isPinValid) {
        if ((digitalPinModeBits & (1 << pin_index))) {  // input mode
            byte pinValue = (byte) digitalRead(digitalPinList[pin_index]);
            sendingBuffer[1] = pinValue;

        }else  // output mode
        { 
            if (digitalPinValueBits & (1 < pin_index)) {
                sendingBuffer[1] = 1;
            }else{
                sendingBuffer[1] = 0;
            }
        }

        sendingBuffer[0] = RESPONSE_OK;
        sendingLength = 2;
        isResponseReady = true;

    }
    else{  // Invalid pin
        sendingBuffer[0] = RESPONSE_FAIL;
        sendingLength = 1;
        isResponseReady = true;
        return;
    }   
}

void setDigitalPinValue(){
    if (receivingLength != 3) {  // check if request length is valid
        sendingBuffer[0] = RESPONSE_BAD_REQUEST;
        sendingLength = 1;
        isResponseReady = true;
        return;
    }

    byte pin = receivingBuffer[1];
    byte value = receivingBuffer[2];

    bool isPinValid = false;
    int pin_index = 0;
    for (pin_index = 0; pin_index < PIN_DIGITAL_NUM; pin_index++)
    {
        if (pin == digitalPinList[pin_index]){
            isPinValid = true;
            break;
        }
    }

    if (isPinValid) {

        if ((digitalPinModeBits & (1 << pin_index))) {  // input mode, can not set value on input mode
            sendingBuffer[0] = RESPONSE_FAIL;
            sendingLength = 1;
            isResponseReady = true;
            return;
        }
        else { // output mode

                    // bool isHigh = (bool)(digitalPinValueBits & (1 << i));
            if (value) {
                digitalWrite(digitalPinList[pin_index], HIGH);
                digitalPinValueBits = digitalPinValueBits | (1 << pin_index);
            }
            else {
                digitalWrite(digitalPinList[pin_index], LOW);
                digitalPinValueBits = digitalPinValueBits & ( ~(1 << pin_index));
            }

            sendingBuffer[0] = RESPONSE_OK;
            sendingLength = 1;
            isResponseReady = true;
        }

    }
    else{  // Invalid pin
        sendingBuffer[0] = RESPONSE_FAIL;
        sendingLength = 1;
        isResponseReady = true;
        return;
    }   
}


void handleDigitalIOCommand(unsigned char command_code){
    switch (command_code)
    {
    case CM_DIGITAL_PIN_GET_PINMODE:
        getDigitalPinMode();

        break;
    case CM_DIGITAL_PIN_SET_PINMODE:
        setDigitalPinMode();  
        break;

    case CM_DIGITAL_PIN_GET_VALUE:
        getDigitalPinValue(); 
        break; 
    case CM_DIGITAL_PIN_SET_VALUE:
        setDigitalPinValue();
        break; 

    default:
        sendingBuffer[0] = RESPONSE_UNKNOW_CM;
        sendingLength = 1;
        isResponseReady = true;
        break;
    }
}


// Bit 0 output , 1 input
// Bit 0 low, Bit 1 high
void setInitialDigitalPinMode(){
    digitalPinModeBits = 0;
    digitalPinValueBits = 0; // defaults all pin is low

    for (int i = 0; i < PIN_DIGITAL_NUM; i++){
        bool isInput = (bool)(digitalPinModeBits & (1 << i));
        if (isInput) {
            pinMode(digitalPinList[i], INPUT);
        }else // Output
        {
            pinMode(digitalPinList[i], OUTPUT);
            bool isHigh = (bool)(digitalPinValueBits & (1 << i));
            if (isHigh) digitalWrite(digitalPinList[i], HIGH);
            else digitalWrite(digitalPinList[i], LOW);
        }
    }


}