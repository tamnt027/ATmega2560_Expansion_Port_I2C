#include "handle_analog_input_command.h"
#include <Arduino.h>
#include "pins_define.h"

extern unsigned char receivingBuffer[128];
extern unsigned char sendingBuffer[128];
extern byte receivingLength;
extern byte sendingLength;

extern bool isResponseReady;

#if (ACTIVE_BOARD == BOARD_ATMEGA2560)

void getAnalogInputPin(){
    if (receivingLength != 2) {  // check if request length is valid
        sendingBuffer[0] = RESPONSE_BAD_REQUEST;
        sendingLength = 1;
        isResponseReady = true;
        return;
    }

    byte pin = receivingBuffer[1];

    if (pin == PIN_ANALOG_INPUT_1 || pin== PIN_ANALOG_INPUT_2 || pin == PIN_ANALOG_INPUT_3 ||
        pin == PIN_ANALOG_INPUT_4 || pin== PIN_ANALOG_INPUT_5 || pin == PIN_ANALOG_INPUT_6 ||
        pin == PIN_ANALOG_INPUT_7 || pin== PIN_ANALOG_INPUT_8 || pin == PIN_ANALOG_INPUT_9 ) {

        sendingBuffer[0] = RESPONSE_OK;
        uint16_t value = analogRead(pin);
        unsigned char const * p = reinterpret_cast<unsigned char const *>(&value);
        for (int i = 0; i != sizeof(uint16_t); ++i)
        {
            sendingBuffer[1  + i] = p[i];
        }

        sendingLength = 3;
        isResponseReady = true;

    }
    else{  // Invalid pin
        sendingBuffer[0] = RESPONSE_FAIL;
        sendingLength = 1;
        isResponseReady = true;
        return;
    }   
}

void getAllAnalogInputPins() {
    if (receivingLength != 1) {  // check if request length is valid
        sendingBuffer[0] = RESPONSE_BAD_REQUEST;
        sendingLength = 1;
        isResponseReady = true;
        return;
    }

    sendingBuffer[0] = RESPONSE_OK;
    int offset = 0;
    uint16_t value1 = analogRead(PIN_ANALOG_INPUT_1);
    unsigned char const * p1 = reinterpret_cast<unsigned char const *>(&value1);
    for (int i = 0; i != sizeof(uint16_t); ++i)
    {
        sendingBuffer[1  + offset + i] = p1[i];
    }
    offset += sizeof(uint16_t);

    uint16_t value2 = analogRead(PIN_ANALOG_INPUT_2);
    unsigned char const * p2 = reinterpret_cast<unsigned char const *>(&value2);
    for (int i = 0; i != sizeof(uint16_t); ++i)
    {
        sendingBuffer[1  + offset + i] = p2[i];
    }
    offset += sizeof(uint16_t);

    uint16_t value3 = analogRead(PIN_ANALOG_INPUT_3);
    unsigned char const * p3 = reinterpret_cast<unsigned char const *>(&value3);
    for (int i = 0; i != sizeof(uint16_t); ++i)
    {
        sendingBuffer[1  + offset + i] = p3[i];
    }
    offset += sizeof(uint16_t);

    uint16_t value4 = analogRead(PIN_ANALOG_INPUT_4);
    unsigned char const * p4 = reinterpret_cast<unsigned char const *>(&value4);
    for (int i = 0; i != sizeof(uint16_t); ++i)
    {
        sendingBuffer[1  + offset + i] = p4[i];
    }
    offset += sizeof(uint16_t);

    uint16_t value5 = analogRead(PIN_ANALOG_INPUT_5);
    unsigned char const * p5 = reinterpret_cast<unsigned char const *>(&value5);
    for (int i = 0; i != sizeof(uint16_t); ++i)
    {
        sendingBuffer[1  + offset + i] = p5[i];
    }
    offset += sizeof(uint16_t);

    uint16_t value6 = analogRead(PIN_ANALOG_INPUT_6);
    unsigned char const * p6 = reinterpret_cast<unsigned char const *>(&value6);
    for (int i = 0; i != sizeof(uint16_t); ++i)
    {
        sendingBuffer[1  + offset + i] = p6[i];
    }
    offset += sizeof(uint16_t);

    uint16_t value7 = analogRead(PIN_ANALOG_INPUT_7);
    unsigned char const * p7 = reinterpret_cast<unsigned char const *>(&value7);
    for (int i = 0; i != sizeof(uint16_t); ++i)
    {
        sendingBuffer[1  + offset + i] = p7[i];
    }
    offset += sizeof(uint16_t);

    uint16_t value8 = analogRead(PIN_ANALOG_INPUT_8);
    unsigned char const * p8 = reinterpret_cast<unsigned char const *>(&value8);
    for (int i = 0; i != sizeof(uint16_t); ++i)
    {
        sendingBuffer[1  + offset + i] = p8[i];
    }
    offset += sizeof(uint16_t);

    uint16_t value9 = analogRead(PIN_ANALOG_INPUT_9);
    unsigned char const * p9 = reinterpret_cast<unsigned char const *>(&value9);
    for (int i = 0; i != sizeof(uint16_t); ++i)
    {
        sendingBuffer[1  + offset + i] = p9[i];
    }
    offset += sizeof(uint16_t);

    sendingLength = 19;
    isResponseReady = true;
}


void handleAnalogInputCommand(unsigned char command_code){
    switch (command_code)
    {
    case CM_ANALOG_INPUT_PIN_VALUE:
        getAnalogInputPin();
        break;
    case CM_ANALOG_INPUT_ALL_PIN_VALUES:
        getAllAnalogInputPins();
        break; 

    default:
        sendingBuffer[0] = RESPONSE_UNKNOW_CM;
        sendingLength = 1;
        isResponseReady = true;
        break;
    }
}

void setAnalogInputPinmode(){
    pinMode(PIN_ANALOG_INPUT_1, INPUT);
    pinMode(PIN_ANALOG_INPUT_2, INPUT);
    pinMode(PIN_ANALOG_INPUT_3, INPUT);
    pinMode(PIN_ANALOG_INPUT_4, INPUT);
    pinMode(PIN_ANALOG_INPUT_5, INPUT);
    pinMode(PIN_ANALOG_INPUT_6, INPUT);
    pinMode(PIN_ANALOG_INPUT_7, INPUT);
    pinMode(PIN_ANALOG_INPUT_8, INPUT);
    pinMode(PIN_ANALOG_INPUT_9, INPUT);

}

#endif