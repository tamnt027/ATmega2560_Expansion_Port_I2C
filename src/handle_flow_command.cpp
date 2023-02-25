#include "handle_flow_command.h"
#include <Arduino.h>
#include "pins_define.h"

#if (ACTIVE_BOARD == BOARD_ESP32_DEVKIT_V1)

extern uint16_t pulseCount1, pulseCount2, pulseCount3, pulseCount4, pulseCount5, pulseCount6;
extern uint16_t pulseCount7, pulseCount8, pulseCount9, pulseCount10, pulseCount11, pulseCount12;

extern unsigned long oldTime1, oldTime2, oldTime3, oldTime4, oldTime5, oldTime6;
extern unsigned long oldTime7, oldTime8, oldTime9, oldTime10, oldTime11, oldTime12; 


extern float flowRate1, flowRate2, flowRate3, flowRate4, flowRate5, flowRate6;
extern float flowRate7, flowRate8, flowRate9, flowRate10, flowRate11, flowRate12;

extern bool isEnableFlow1, isEnableFlow2,isEnableFlow3,isEnableFlow4,isEnableFlow5,isEnableFlow6;
extern bool isEnableFlow7, isEnableFlow8,isEnableFlow9,isEnableFlow10,isEnableFlow11,isEnableFlow12;

// The hall-effect flow sensor outputs approximately 4.5 pulses per second per
// litre/minute of flow.
float calibrationFactor = 4.5;


extern unsigned char receivingBuffer[128];
extern unsigned char sendingBuffer[128];

extern byte receivingLength;
extern byte sendingLength;

extern bool isResponseReady;


void enable_flow_pin()
{
    if (receivingLength != 2) {  // check if request length is valid
        sendingBuffer[0] = RESPONSE_BAD_REQUEST;
        sendingLength = 1;
        isResponseReady = true;
        return;
    }

    byte pin = receivingBuffer[1];
    // check pin is valid
    switch (pin)
    {
    case PIN_INTERUPT_FLOW_1:
        if (isEnableFlow1 == false) { // Enable already, just return ok.
            isEnableFlow1 = true;
            attachInterrupt(PIN_INTERUPT_FLOW_1, pulseCounter1, FLOW_INTERUPT_CHANGE_TYPE);
        }
        sendingBuffer[0] = RESPONSE_OK;
        sendingLength = 1;
        isResponseReady = true;
        return;
        break;
    case PIN_INTERUPT_FLOW_2:
        if (isEnableFlow2 == false) { // Enable already, just return ok.
            isEnableFlow2 = true;
            attachInterrupt(PIN_INTERUPT_FLOW_2, pulseCounter2, FLOW_INTERUPT_CHANGE_TYPE);
        }
        sendingBuffer[0] = RESPONSE_OK;
        sendingLength = 1;
        isResponseReady = true;
        return;
        break;
    case PIN_INTERUPT_FLOW_3:
        if (isEnableFlow3 == false) { // Enable already, just return ok.
            isEnableFlow3 = true;
            attachInterrupt(PIN_INTERUPT_FLOW_3, pulseCounter3, FLOW_INTERUPT_CHANGE_TYPE);
        }
        sendingBuffer[0] = RESPONSE_OK;
        sendingLength = 1;
        isResponseReady = true;
        return;
        break;
    case PIN_INTERUPT_FLOW_4:
        if (isEnableFlow4 == false) { // Enable already, just return ok.
            isEnableFlow4 = true;
            attachInterrupt(PIN_INTERUPT_FLOW_4, pulseCounter4, FLOW_INTERUPT_CHANGE_TYPE);
        }
        sendingBuffer[0] = RESPONSE_OK;
        sendingLength = 1;
        isResponseReady = true;
        return;        
        break;
    case PIN_INTERUPT_FLOW_5:
        if (isEnableFlow5 == false) { // Enable already, just return ok.
            isEnableFlow5 = true;
            attachInterrupt(PIN_INTERUPT_FLOW_5, pulseCounter5, FLOW_INTERUPT_CHANGE_TYPE);
        }
        sendingBuffer[0] = RESPONSE_OK;
        sendingLength = 1;
        isResponseReady = true;
        return;              
        break;
    case PIN_INTERUPT_FLOW_6:
        if (isEnableFlow6 == false) { // Enable already, just return ok.
            isEnableFlow6 = true;
            attachInterrupt(PIN_INTERUPT_FLOW_6, pulseCounter6, FLOW_INTERUPT_CHANGE_TYPE);
        }
        sendingBuffer[0] = RESPONSE_OK;
        sendingLength = 1;
        isResponseReady = true;
        return;         
        break;
    case PIN_INTERUPT_FLOW_7:
        if (isEnableFlow7 == false) { // Enable already, just return ok.
            isEnableFlow7 = true;
            attachInterrupt(PIN_INTERUPT_FLOW_7, pulseCounter7, FLOW_INTERUPT_CHANGE_TYPE);
        }
        sendingBuffer[0] = RESPONSE_OK;
        sendingLength = 1;
        isResponseReady = true;
        return;         
        break;
    case PIN_INTERUPT_FLOW_8:
        if (isEnableFlow8 == false) { // Enable already, just return ok.
            isEnableFlow8 = true;
            attachInterrupt(PIN_INTERUPT_FLOW_8, pulseCounter8, FLOW_INTERUPT_CHANGE_TYPE);
        }
        sendingBuffer[0] = RESPONSE_OK;
        sendingLength = 1;
        isResponseReady = true;
        return;         
        break;
    case PIN_INTERUPT_FLOW_9:
        if (isEnableFlow9 == false) { // Enable already, just return ok.
            isEnableFlow9 = true;
            attachInterrupt(PIN_INTERUPT_FLOW_9, pulseCounter9, FLOW_INTERUPT_CHANGE_TYPE);
        }
        sendingBuffer[0] = RESPONSE_OK;
        sendingLength = 1;
        isResponseReady = true;
        return;          
        break;
    case PIN_INTERUPT_FLOW_10:
        if (isEnableFlow10 == false) { // Enable already, just return ok.
            isEnableFlow10 = true;
            attachInterrupt(PIN_INTERUPT_FLOW_10, pulseCounter10, FLOW_INTERUPT_CHANGE_TYPE);
        }
        sendingBuffer[0] = RESPONSE_OK;
        sendingLength = 1;
        isResponseReady = true;
        return;        
        break;
    case PIN_INTERUPT_FLOW_11:
        if (isEnableFlow11 == false) { // Enable already, just return ok.
            isEnableFlow11 = true;
            attachInterrupt(PIN_INTERUPT_FLOW_11, pulseCounter11, FLOW_INTERUPT_CHANGE_TYPE);
        }
        sendingBuffer[0] = RESPONSE_OK;
        sendingLength = 1;
        isResponseReady = true;
        return;           
        break;
    case PIN_INTERUPT_FLOW_12:
        if (isEnableFlow12 == false) { // Enable already, just return ok.
            isEnableFlow12 = true;
            attachInterrupt(PIN_INTERUPT_FLOW_12, pulseCounter12, FLOW_INTERUPT_CHANGE_TYPE);
        }
        sendingBuffer[0] = RESPONSE_OK;
        sendingLength = 1;
        isResponseReady = true;
        return;           
        break;
    
    default:  // invalid pin.
        sendingBuffer[0] = RESPONSE_FAIL;
        sendingLength = 1;
        isResponseReady = true;
        return;
        break;
    }
}

void disable_flow_pin()
{
    if (receivingLength != 2) {  // check if request length is valid
        sendingBuffer[0] = RESPONSE_BAD_REQUEST;
        sendingLength = 1;
        isResponseReady = true;
        return;
    }

    byte pin = receivingBuffer[1];
    // check pin is valid
    switch (pin)
    {
    case PIN_INTERUPT_FLOW_1:
        if (isEnableFlow1 == true) { // Enable already, just return ok.
            isEnableFlow1 = false;
            detachInterrupt(PIN_INTERUPT_FLOW_1);
        }
        sendingBuffer[0] = RESPONSE_OK;
        sendingLength = 1;
        isResponseReady = true;
        return;
        break;
    case PIN_INTERUPT_FLOW_2:
        if (isEnableFlow2 == true) { // Enable already, just return ok.
            isEnableFlow2 = false;
            detachInterrupt(PIN_INTERUPT_FLOW_2);
        }
        sendingBuffer[0] = RESPONSE_OK;
        sendingLength = 1;
        isResponseReady = true;
        return;
        break;
    case PIN_INTERUPT_FLOW_3:
        if (isEnableFlow3 == true) { // Enable already, just return ok.
            isEnableFlow3 = false;
            detachInterrupt(PIN_INTERUPT_FLOW_3);
        }
        sendingBuffer[0] = RESPONSE_OK;
        sendingLength = 1;
        isResponseReady = true;
        return;
        break;
    case PIN_INTERUPT_FLOW_4:
        if (isEnableFlow4 == true) { // Enable already, just return ok.
            isEnableFlow4 = false;
            detachInterrupt(PIN_INTERUPT_FLOW_4);
        }
        sendingBuffer[0] = RESPONSE_OK;
        sendingLength = 1;
        isResponseReady = true;
        return;        
        break;
    case PIN_INTERUPT_FLOW_5:
        if (isEnableFlow5 == true) { // Enable already, just return ok.
            isEnableFlow5 = false;
            detachInterrupt(PIN_INTERUPT_FLOW_5);
        }
        sendingBuffer[0] = RESPONSE_OK;
        sendingLength = 1;
        isResponseReady = true;
        return;              
        break;
    case PIN_INTERUPT_FLOW_6:
        if (isEnableFlow6 == true) { // Enable already, just return ok.
            isEnableFlow6 = false;
            detachInterrupt(PIN_INTERUPT_FLOW_6);
        }
        sendingBuffer[0] = RESPONSE_OK;
        sendingLength = 1;
        isResponseReady = true;
        return;         
        break;
    case PIN_INTERUPT_FLOW_7:
        if (isEnableFlow7 == true) { // Enable already, just return ok.
            isEnableFlow7 = false;
            detachInterrupt(PIN_INTERUPT_FLOW_7);
        }
        sendingBuffer[0] = RESPONSE_OK;
        sendingLength = 1;
        isResponseReady = true;
        return;         
        break;
    case PIN_INTERUPT_FLOW_8:
        if (isEnableFlow8 == true) { // Enable already, just return ok.
            isEnableFlow8 = false;
            detachInterrupt(PIN_INTERUPT_FLOW_8);
        }
        sendingBuffer[0] = RESPONSE_OK;
        sendingLength = 1;
        isResponseReady = true;
        return;         
        break;
    case PIN_INTERUPT_FLOW_9:
        if (isEnableFlow9 == true) { // Enable already, just return ok.
            isEnableFlow9 = false;
            detachInterrupt(PIN_INTERUPT_FLOW_9);
        }
        sendingBuffer[0] = RESPONSE_OK;
        sendingLength = 1;
        isResponseReady = true;
        return;          
        break;
    case PIN_INTERUPT_FLOW_10:
        if (isEnableFlow10 == true) { // Enable already, just return ok.
            isEnableFlow10 = false;
            detachInterrupt(PIN_INTERUPT_FLOW_10);
        }
        sendingBuffer[0] = RESPONSE_OK;
        sendingLength = 1;
        isResponseReady = true;
        return;        
        break;
    case PIN_INTERUPT_FLOW_11:
        if (isEnableFlow11 == true) { // Enable already, just return ok.
            isEnableFlow11 = false;
            detachInterrupt(PIN_INTERUPT_FLOW_11);
        }
        sendingBuffer[0] = RESPONSE_OK;
        sendingLength = 1;
        isResponseReady = true;
        return;           
        break;
    case PIN_INTERUPT_FLOW_12:
        if (isEnableFlow12 == true) { // Enable already, just return ok.
            isEnableFlow12 = false;
            detachInterrupt(PIN_INTERUPT_FLOW_12);
        }
        sendingBuffer[0] = RESPONSE_OK;
        sendingLength = 1;
        isResponseReady = true;
        return;           
        break;
    
    default:  // invalid pin.
        sendingBuffer[0] = RESPONSE_FAIL;
        sendingLength = 1;
        isResponseReady = true;
        return;
        break;
    }
}

void get_flow_value()
{
    if (receivingLength != 2) {  // check if request length is valid
        sendingBuffer[0] = RESPONSE_BAD_REQUEST;
        sendingLength = 1;
        isResponseReady = true;
        return;
    }

    byte pin = receivingBuffer[1];
    // check pin is valid
    switch (pin)
    {
    case PIN_INTERUPT_FLOW_1:
        {
            unsigned char const * p1 = reinterpret_cast<unsigned char const *>(&flowRate1);
            for (std::size_t i = 0; i != sizeof(float); ++i)
            {
                sendingBuffer[1 + i] = p1[i];
            }
        }

        sendingBuffer[0] = RESPONSE_OK;
        sendingLength = 1 + sizeof(float);
        isResponseReady = true;
        return;
        break;
    case PIN_INTERUPT_FLOW_2:
        {
            unsigned char const * p2 = reinterpret_cast<unsigned char const *>(&flowRate2);
            for (std::size_t i = 0; i != sizeof(float); ++i)
            {
                sendingBuffer[1 + i] = p2[i];
            }
        }

        sendingBuffer[0] = RESPONSE_OK;
        sendingLength = 1 + sizeof(float);
        isResponseReady = true;
        return;
        break;
    case PIN_INTERUPT_FLOW_3:
        {
            unsigned char const * p3 = reinterpret_cast<unsigned char const *>(&flowRate3);
            for (std::size_t i = 0; i != sizeof(float); ++i)
            {
                sendingBuffer[1 + i] = p3[i];
            }
        }

        sendingBuffer[0] = RESPONSE_OK;
        sendingLength = 1 + sizeof(float);
        isResponseReady = true;
        return;
        break;
    case PIN_INTERUPT_FLOW_4:
        {
            unsigned char const * p4 = reinterpret_cast<unsigned char const *>(&flowRate4);
            for (std::size_t i = 0; i != sizeof(float); ++i)
            {
                sendingBuffer[1 + i] = p4[i];
            }
        }

        sendingBuffer[0] = RESPONSE_OK;
        sendingLength = 1 + sizeof(float);
        isResponseReady = true;
        return;       
        break;
    case PIN_INTERUPT_FLOW_5:
        {
            unsigned char const * p5 = reinterpret_cast<unsigned char const *>(&flowRate5);
            for (std::size_t i = 0; i != sizeof(float); ++i)
            {
                sendingBuffer[1 + i] = p5[i];
            }
        }

        sendingBuffer[0] = RESPONSE_OK;
        sendingLength = 1 + sizeof(float);
        isResponseReady = true;
        return;          
        break;
    case PIN_INTERUPT_FLOW_6:
        {
            unsigned char const * p6 = reinterpret_cast<unsigned char const *>(&flowRate6);
            for (std::size_t i = 0; i != sizeof(float); ++i)
            {
                sendingBuffer[1 + i] = p6[i];
            }
        }

        sendingBuffer[0] = RESPONSE_OK;
        sendingLength = 1 + sizeof(float);
        isResponseReady = true;
        return;
        return;         
        break;
    case PIN_INTERUPT_FLOW_7:
        {
            unsigned char const * p7 = reinterpret_cast<unsigned char const *>(&flowRate7);
            for (std::size_t i = 0; i != sizeof(float); ++i)
            {
                sendingBuffer[1 + i] = p7[i];
            }
        }

        sendingBuffer[0] = RESPONSE_OK;
        sendingLength = 1 + sizeof(float);
        isResponseReady = true;
        return;      
        break;
    case PIN_INTERUPT_FLOW_8:
        {
            unsigned char const * p8 = reinterpret_cast<unsigned char const *>(&flowRate8);
            for (std::size_t i = 0; i != sizeof(float); ++i)
            {
                sendingBuffer[1 + i] = p8[i];
            }
        }

        sendingBuffer[0] = RESPONSE_OK;
        sendingLength = 1 + sizeof(float);
        isResponseReady = true;
        return;    
        break;
    case PIN_INTERUPT_FLOW_9:
        {
            unsigned char const * p9 = reinterpret_cast<unsigned char const *>(&flowRate9);
            for (std::size_t i = 0; i != sizeof(float); ++i)
            {
                sendingBuffer[1 + i] = p9[i];
            }
        }

        sendingBuffer[0] = RESPONSE_OK;
        sendingLength = 1 + sizeof(float);
        isResponseReady = true;
        return;     
        break;
    case PIN_INTERUPT_FLOW_10:
        {
            unsigned char const * p10 = reinterpret_cast<unsigned char const *>(&flowRate10);
            for (std::size_t i = 0; i != sizeof(float); ++i)
            {
                sendingBuffer[1 + i] = p10[i];
            }
        }
        sendingBuffer[0] = RESPONSE_OK;
        sendingLength = 1 + sizeof(float);
        isResponseReady = true;
        return;   
        break;
    case PIN_INTERUPT_FLOW_11:
        {
            unsigned char const * p11 = reinterpret_cast<unsigned char const *>(&flowRate11);
            for (std::size_t i = 0; i != sizeof(float); ++i)
            {
                sendingBuffer[1 + i] = p11[i];
            }
        }

        sendingBuffer[0] = RESPONSE_OK;
        sendingLength = 1 + sizeof(float);
        isResponseReady = true;
        return;        
        break;
    case PIN_INTERUPT_FLOW_12:
        {
            unsigned char const * p12 = reinterpret_cast<unsigned char const *>(&flowRate12);
            for (std::size_t i = 0; i != sizeof(float); ++i)
            {
                sendingBuffer[1 + i] = p12[i];
            }
        }

        sendingBuffer[0] = RESPONSE_OK;
        sendingLength = 1 + sizeof(float);
        isResponseReady = true;
        return;        
        break;
    
    default:  // invalid pin.
        sendingBuffer[0] = RESPONSE_FAIL;
        sendingLength = 1;
        isResponseReady = true;
        return;
        break;
    }
}

void get_flow_status()
{
    if (receivingLength != 2) {  // check if request length is valid
        sendingBuffer[0] = RESPONSE_BAD_REQUEST;
        sendingLength = 1;
        isResponseReady = true;
        return;
    }

    byte pin = receivingBuffer[1];
    // check pin is valid
    switch (pin)
    {
    case PIN_INTERUPT_FLOW_1:
        sendingBuffer[0] = RESPONSE_OK;
        sendingBuffer[1] = isEnableFlow1;
        sendingLength = 2;
        isResponseReady = true;
        return;
        break;
    case PIN_INTERUPT_FLOW_2:
        sendingBuffer[0] = RESPONSE_OK;
        sendingBuffer[1] = isEnableFlow2;
        sendingLength = 2;
        isResponseReady = true;
        return;
        break;
    case PIN_INTERUPT_FLOW_3:
        sendingBuffer[0] = RESPONSE_OK;
        sendingBuffer[1] = isEnableFlow3;
        sendingLength = 2;
        isResponseReady = true;
        return;
    case PIN_INTERUPT_FLOW_4:
        sendingBuffer[0] = RESPONSE_OK;
        sendingBuffer[1] = isEnableFlow4;
        sendingLength = 2;
        isResponseReady = true;
        return;      
        break;
    case PIN_INTERUPT_FLOW_5:
        sendingBuffer[0] = RESPONSE_OK;
        sendingBuffer[1] = isEnableFlow5;
        sendingLength = 2;
        isResponseReady = true;
        return;       
        break;
    case PIN_INTERUPT_FLOW_6:
        sendingBuffer[0] = RESPONSE_OK;
        sendingBuffer[1] = isEnableFlow6;
        sendingLength = 2;
        isResponseReady = true;
        return;         
        break;
    case PIN_INTERUPT_FLOW_7:
        sendingBuffer[0] = RESPONSE_OK;
        sendingBuffer[1] = isEnableFlow7;
        sendingLength = 2;
        isResponseReady = true;
        return;     
        break;
    case PIN_INTERUPT_FLOW_8:
        sendingBuffer[0] = RESPONSE_OK;
        sendingBuffer[1] = isEnableFlow8;
        sendingLength = 2;
        isResponseReady = true;
        return;    
        break;
    case PIN_INTERUPT_FLOW_9:
        sendingBuffer[0] = RESPONSE_OK;
        sendingBuffer[1] = isEnableFlow9;
        sendingLength = 2;
        isResponseReady = true;
        return;   
        break;
    case PIN_INTERUPT_FLOW_10:
        sendingBuffer[0] = RESPONSE_OK;
        sendingBuffer[1] = isEnableFlow10;
        sendingLength = 2;
        isResponseReady = true;
        return;  
        break;
    case PIN_INTERUPT_FLOW_11:
        sendingBuffer[0] = RESPONSE_OK;
        sendingBuffer[1] = isEnableFlow11;
        sendingLength = 2;
        isResponseReady = true;
        return;       
        break;
    case PIN_INTERUPT_FLOW_12:
        sendingBuffer[0] = RESPONSE_OK;
        sendingBuffer[1] = isEnableFlow12;
        sendingLength = 2;
        isResponseReady = true;
        return;       
        break;
    
    default:  // invalid pin.
        sendingBuffer[0] = RESPONSE_FAIL;
        sendingLength = 1;
        isResponseReady = true;
        return;
        break;
    }
}

void handle_disable_all_flow(){
    if (receivingLength != 1) {  // check if request length is valid
        sendingBuffer[0] = RESPONSE_BAD_REQUEST;
        sendingLength = 1;
        isResponseReady = true;
        return;
    }
    disable_all_flow_interupt();
    sendingBuffer[0] = RESPONSE_OK;
    sendingLength = 1;
    isResponseReady = true;

}

void handle_enable_all_flow(){
    if (receivingLength != 1) {  // check if request length is valid
        sendingBuffer[0] = RESPONSE_BAD_REQUEST;
        sendingLength = 1;
        isResponseReady = true;
        return;
    }
    
    sendingBuffer[0] = RESPONSE_OK;
    sendingLength = 1;
    isResponseReady = true;
    enable_all_flow_interupts();

}


void get_all_pin_values(){
    if (receivingLength != 1) {  // check if request length is valid
        sendingBuffer[0] = RESPONSE_BAD_REQUEST;
        sendingLength = 1;
        isResponseReady = true;
        return;
    }

    sendingBuffer[0] = RESPONSE_OK;
    int offset = 0;
    unsigned char const * p1 = reinterpret_cast<unsigned char const *>(&flowRate1);
    for (std::size_t i = 0; i != sizeof(float); ++i)
    {
        sendingBuffer[1 + offset + i] = p1[i];
    }
    offset += sizeof(float);
    
    unsigned char const * p2 = reinterpret_cast<unsigned char const *>(&flowRate2);
    for (std::size_t i = 0; i != sizeof(float); ++i)
    {
        sendingBuffer[1 + offset + i] = p2[i];
    }
    offset += sizeof(float);
    unsigned char const * p3 = reinterpret_cast<unsigned char const *>(&flowRate3);
    for (std::size_t i = 0; i != sizeof(float); ++i)
    {
        sendingBuffer[1 + offset + i] = p3[i];
    }
    offset += sizeof(float);
    unsigned char const * p4 = reinterpret_cast<unsigned char const *>(&flowRate4);
    for (std::size_t i = 0; i != sizeof(float); ++i)
    {
        sendingBuffer[1 + offset + i] = p4[i];
    }
    offset += sizeof(float);
    unsigned char const * p5 = reinterpret_cast<unsigned char const *>(&flowRate5);
    for (std::size_t i = 0; i != sizeof(float); ++i)
    {
        sendingBuffer[1 + offset + i] = p5[i];
    }
    offset += sizeof(float);
    unsigned char const * p6 = reinterpret_cast<unsigned char const *>(&flowRate6);
    for (std::size_t i = 0; i != sizeof(float); ++i)
    {
        sendingBuffer[1 + offset + i] = p6[i];
    }
    offset += sizeof(float);
    unsigned char const * p7 = reinterpret_cast<unsigned char const *>(&flowRate7);
    for (std::size_t i = 0; i != sizeof(float); ++i)
    {
        sendingBuffer[1 + offset + i] = p7[i];
    }
    offset += sizeof(float);
    unsigned char const * p8 = reinterpret_cast<unsigned char const *>(&flowRate8);
    for (std::size_t i = 0; i != sizeof(float); ++i)
    {
        sendingBuffer[1 + offset + i] = p8[i];
    }
    offset += sizeof(float);
    unsigned char const * p9 = reinterpret_cast<unsigned char const *>(&flowRate9);
    for (std::size_t i = 0; i != sizeof(float); ++i)
    {
        sendingBuffer[1 + offset + i] = p9[i];
    }
    offset += sizeof(float);
    unsigned char const * p10 = reinterpret_cast<unsigned char const *>(&flowRate10);
    for (std::size_t i = 0; i != sizeof(float); ++i)
    {
        sendingBuffer[1 + offset + i] = p10[i];
    }
    offset += sizeof(float);
    unsigned char const * p11 = reinterpret_cast<unsigned char const *>(&flowRate11);
    for (std::size_t i = 0; i != sizeof(float); ++i)
    {
        sendingBuffer[1 + offset + i] = p11[i];
    }
    offset += sizeof(float);
    unsigned char const * p12 = reinterpret_cast<unsigned char const *>(&flowRate12);
    for (std::size_t i = 0; i != sizeof(float); ++i)
    {
        sendingBuffer[1 + offset + i] = p12[i];
    }
    offset += sizeof(float);


    sendingLength = 1 + 12 * sizeof(float);
    isResponseReady = true;

}

void handleFlowCommand(unsigned char command_code){
    switch (command_code)
    {
    case CM_FLOW_ENABLE_PIN:
        enable_flow_pin();
        break;
    case CM_FLOW_DISABLE_PIN:
        disable_flow_pin();
        break;
    case CM_FLOW_GET_PIN_VALUE:
        get_flow_value();
        break;
    case CM_FLOW_GET_PIN_STATUS:
        get_flow_status();
        break;
    case CM_FLOW_DISABLE_ALL:
        handle_disable_all_flow();
        break;
    case CM_FLOW_ENABLE_ALL:
        handle_enable_all_flow();
        break;
    case CM_FLOW_GET_ALL_PIN_VALUE:
        get_all_pin_values();
        break;
    
    default:
        sendingBuffer[0] = RESPONSE_UNKNOW_CM;
        sendingLength = 1;
        isResponseReady = true;
        break;
    }

}


void set_flow_pinmode() {
    pinMode(PIN_INTERUPT_FLOW_1, INPUT);
    pinMode(PIN_INTERUPT_FLOW_2, INPUT);
    pinMode(PIN_INTERUPT_FLOW_3, INPUT);
    pinMode(PIN_INTERUPT_FLOW_4, INPUT);
    pinMode(PIN_INTERUPT_FLOW_5, INPUT);
    pinMode(PIN_INTERUPT_FLOW_6, INPUT);
    pinMode(PIN_INTERUPT_FLOW_7, INPUT);
    pinMode(PIN_INTERUPT_FLOW_8, INPUT);
    pinMode(PIN_INTERUPT_FLOW_9, INPUT);
    pinMode(PIN_INTERUPT_FLOW_10, INPUT);
    pinMode(PIN_INTERUPT_FLOW_11, INPUT);
    pinMode(PIN_INTERUPT_FLOW_12, INPUT);
}

void update_flow_1() {
    if (isEnableFlow1) {
        if( (millis() - oldTime1) > 1000)    // Only process counters once per second
        { 
            // Disable the interrupt while calculating flow rate and sending the value to
            // the host
            detachInterrupt(PIN_INTERUPT_FLOW_1);
                
            // Because this loop may not complete in exactly 1 second intervals we calculate
            // the number of milliseconds that have passed since the last execution and use
            // that to scale the output. We also apply the calibrationFactor to scale the output
            // based on the number of pulses per second per units of measure (litres/minute in
            // this case) coming from the sensor.


            flowRate1 = ((1000.0 / ( millis() - oldTime1)) * pulseCount1) / calibrationFactor;

            
            // Note the time this processing pass was executed. Note that because we've
            // disabled interrupts the millis() function won't actually be incrementing right
            // at this point, but it will still return the value it was set to just before
            // interrupts went away.

            oldTime1 = millis();
            
            // Reset the pulse counter so we can start incrementing again
            pulseCount1 = 0;
            
            // Enable the interrupt again now that we've finished sending output
            attachInterrupt(PIN_INTERUPT_FLOW_1, pulseCounter1, FLOW_INTERUPT_CHANGE_TYPE);

            #ifdef SERIAL_DEBUG
            // Initialize a serial connection for reporting values to the host
            Serial.print("Flow rate 1 ");
            Serial.println(flowRate1);
            #endif

        }
    }else {
        flowRate1 = 0;
    }
}

void update_flow_2() {
    if (isEnableFlow2) {
        if( (millis() - oldTime2) > 1000)    // Only process counters once per second
        { 
            detachInterrupt(PIN_INTERUPT_FLOW_2);
                
            flowRate2 = ((1000.0 / ( millis() - oldTime2)) * pulseCount2) / calibrationFactor;

            oldTime2 = millis();
            
            pulseCount2 = 0;
            
            attachInterrupt(PIN_INTERUPT_FLOW_2, pulseCounter2, FLOW_INTERUPT_CHANGE_TYPE);

            #ifdef SERIAL_DEBUG
            // Initialize a serial connection for reporting values to the host
            Serial.print("Flow rate 2 ");
            Serial.println(flowRate2);
            #endif

        }
    }else {
        flowRate2 = 0;
    }
}

void update_flow_3() {
    if (isEnableFlow3) {
        if( (millis() - oldTime3) > 1000)    // Only process counters once per second
        { 
            detachInterrupt(PIN_INTERUPT_FLOW_3);
                
            flowRate3 = ((1000.0 / ( millis() - oldTime3)) * pulseCount3) / calibrationFactor;

            oldTime3 = millis();
            
            pulseCount3 = 0;
            
            attachInterrupt(PIN_INTERUPT_FLOW_3, pulseCounter3, FLOW_INTERUPT_CHANGE_TYPE);

            #ifdef SERIAL_DEBUG
            // Initialize a serial connection for reporting values to the host
            Serial.print("Flow rate 3 ");
            Serial.println(flowRate3);
            #endif

        }
    }else {
        flowRate3 = 0;
    }
}

void update_flow_4() {
    if (isEnableFlow4) {
        if( (millis() - oldTime4) > 1000)    // Only process counters once per second
        { 
            detachInterrupt(PIN_INTERUPT_FLOW_4);
                
            flowRate4 = ((1000.0 / ( millis() - oldTime4)) * pulseCount4) / calibrationFactor;

            oldTime4 = millis();
            
            pulseCount4 = 0;
            
            attachInterrupt(PIN_INTERUPT_FLOW_4, pulseCounter4, FLOW_INTERUPT_CHANGE_TYPE);

            #ifdef SERIAL_DEBUG
            // Initialize a serial connection for reporting values to the host
            Serial.print("Flow rate 4 ");
            Serial.println(flowRate4);
            #endif

        }
    }else {
        flowRate4 = 0;
    }
}

void update_flow_5() {
    if (isEnableFlow5) {
        if( (millis() - oldTime5) > 1000)    // Only process counters once per second
        { 
            detachInterrupt(PIN_INTERUPT_FLOW_5);
                
            flowRate5 = ((1000.0 / ( millis() - oldTime5)) * pulseCount5) / calibrationFactor;

            oldTime5 = millis();
            
            pulseCount5 = 0;
            
            attachInterrupt(PIN_INTERUPT_FLOW_5, pulseCounter5, FLOW_INTERUPT_CHANGE_TYPE);

            #ifdef SERIAL_DEBUG
            // Initialize a serial connection for reporting values to the host
            Serial.print("Flow rate 5 ");
            Serial.println(flowRate5);
            #endif

        }
    }else {
        flowRate5 = 0;
    }
}

void update_flow_6() {
    if (isEnableFlow6) {
        if( (millis() - oldTime6) > 1000)    // Only process counters once per second
        { 
            detachInterrupt(PIN_INTERUPT_FLOW_6);
                
            flowRate6 = ((1000.0 / ( millis() - oldTime6)) * pulseCount6) / calibrationFactor;

            oldTime6 = millis();
            
            pulseCount6 = 0;
            
            attachInterrupt(PIN_INTERUPT_FLOW_6, pulseCounter6, FLOW_INTERUPT_CHANGE_TYPE);

            #ifdef SERIAL_DEBUG
            // Initialize a serial connection for reporting values to the host
            Serial.print("Flow rate 6 ");
            Serial.println(flowRate6);
            #endif

        }
    }else {
        flowRate6 = 0;
    }
}

void update_flow_7() {
    if (isEnableFlow7) {
        if( (millis() - oldTime7) > 1000)    // Only process counters once per second
        { 
            detachInterrupt(PIN_INTERUPT_FLOW_7);
                
            flowRate7 = ((1000.0 / ( millis() - oldTime7)) * pulseCount7) / calibrationFactor;

            oldTime7 = millis();
            
            pulseCount7 = 0;
            
            attachInterrupt(PIN_INTERUPT_FLOW_7, pulseCounter7, FLOW_INTERUPT_CHANGE_TYPE);

            #ifdef SERIAL_DEBUG
            // Initialize a serial connection for reporting values to the host
            Serial.print("Flow rate 7 ");
            Serial.println(flowRate7);
            #endif

        }
    }else {
        flowRate7 = 0;
    }
}

void update_flow_8() {
    if (isEnableFlow8) {
        if( (millis() - oldTime8) > 1000)    // Only process counters once per second
        { 
            detachInterrupt(PIN_INTERUPT_FLOW_8);
                
            flowRate8 = ((1000.0 / ( millis() - oldTime8)) * pulseCount8) / calibrationFactor;

            oldTime8 = millis();
            
            pulseCount8 = 0;
            
            attachInterrupt(PIN_INTERUPT_FLOW_8, pulseCounter8, FLOW_INTERUPT_CHANGE_TYPE);

            #ifdef SERIAL_DEBUG
            // Initialize a serial connection for reporting values to the host
            Serial.print("Flow rate 8 ");
            Serial.println(flowRate8);
            #endif

        }
    }else {
        flowRate8 = 0;
    }
}


void update_flow_9() {
    if (isEnableFlow9) {
        if( (millis() - oldTime9) > 1000)    // Only process counters once per second
        { 
            detachInterrupt(PIN_INTERUPT_FLOW_9);
                
            flowRate9 = ((1000.0 / ( millis() - oldTime9)) * pulseCount9) / calibrationFactor;

            oldTime9 = millis();
            
            pulseCount9 = 0;
            
            attachInterrupt(PIN_INTERUPT_FLOW_9, pulseCounter9, FLOW_INTERUPT_CHANGE_TYPE);

            #ifdef SERIAL_DEBUG
            // Initialize a serial connection for reporting values to the host
            Serial.print("Flow rate 9 ");
            Serial.println(flowRate9);
            #endif

        }
    }else {
        flowRate9 = 0;
    }
}

void update_flow_10() {
    if (isEnableFlow10) {
        if( (millis() - oldTime10) > 1000)    // Only process counters once per second
        { 
            detachInterrupt(PIN_INTERUPT_FLOW_10);
                
            flowRate10 = ((1000.0 / ( millis() - oldTime10)) * pulseCount10) / calibrationFactor;

            oldTime10 = millis();
            
            pulseCount10 = 0;
            
            attachInterrupt(PIN_INTERUPT_FLOW_10, pulseCounter10, FLOW_INTERUPT_CHANGE_TYPE);

            #ifdef SERIAL_DEBUG
            // Initialize a serial connection for reporting values to the host
            Serial.print("Flow rate 10 ");
            Serial.println(flowRate10);
            #endif

        }
    }else {
        flowRate10 = 0;
    }
}

void update_flow_11() {
    if (isEnableFlow11) {
        if( (millis() - oldTime11) > 1000)    // Only process counters once per second
        { 
            detachInterrupt(PIN_INTERUPT_FLOW_11);
                
            flowRate11 = ((1000.0 / ( millis() - oldTime11)) * pulseCount11) / calibrationFactor;

            oldTime11 = millis();
            
            pulseCount11 = 0;
            
            attachInterrupt(PIN_INTERUPT_FLOW_11, pulseCounter11, FLOW_INTERUPT_CHANGE_TYPE);

            #ifdef SERIAL_DEBUG
            // Initialize a serial connection for reporting values to the host
            Serial.print("Flow rate 11 ");
            Serial.println(flowRate11);
            #endif

        }
    }else {
        flowRate11 = 0;
    }
}

void update_flow_12() {
    if (isEnableFlow12) {
        if( (millis() - oldTime12) > 1000)    // Only process counters once per second
        { 
            detachInterrupt(PIN_INTERUPT_FLOW_12);
                
            flowRate12 = ((1000.0 / ( millis() - oldTime12)) * pulseCount12) / calibrationFactor;

            oldTime12 = millis();
            
            pulseCount12 = 0;
            
            attachInterrupt(PIN_INTERUPT_FLOW_12, pulseCounter12, FLOW_INTERUPT_CHANGE_TYPE);

            #ifdef SERIAL_DEBUG
            // Initialize a serial connection for reporting values to the host
            Serial.print("Flow rate 12 ");
            Serial.println(flowRate12);
            #endif

        }
    }else {
        flowRate12 = 0;
    }
}
/*
Interrupt Service Routine
 */
void pulseCounter1(){
  pulseCount1 ++;
}

void pulseCounter2(){
  pulseCount2 ++;
}

void pulseCounter3(){
  pulseCount3 ++;
}

void pulseCounter4(){
  pulseCount4 ++;
}

void pulseCounter5(){
  pulseCount5 ++;
}

void pulseCounter6(){
  pulseCount6 ++;
}

void pulseCounter7(){
  pulseCount7 ++;
}

void pulseCounter8(){
  pulseCount8 ++;
}

void pulseCounter9(){
  pulseCount9 ++;
}

void pulseCounter10(){
  pulseCount10 ++;
}

void pulseCounter11(){
  pulseCount11 ++;
}

void pulseCounter12(){
  pulseCount12 ++;
}

void enable_all_flow_interupts(){
  // Configured to trigger on a FALLING state change (transition from HIGH
  // state to LOW state)
  if (isEnableFlow1 == false){
    isEnableFlow1 = true;
    attachInterrupt(PIN_INTERUPT_FLOW_1, pulseCounter1, FLOW_INTERUPT_CHANGE_TYPE);
  }
  if (isEnableFlow2 == false){
    isEnableFlow2 = true;
    attachInterrupt(PIN_INTERUPT_FLOW_2, pulseCounter2, FLOW_INTERUPT_CHANGE_TYPE);
  }
  if (isEnableFlow3 == false){
    isEnableFlow3 = true;
    attachInterrupt(PIN_INTERUPT_FLOW_3, pulseCounter3, FLOW_INTERUPT_CHANGE_TYPE);
  }
  if (isEnableFlow4 == false){
    isEnableFlow4 = true;
    attachInterrupt(PIN_INTERUPT_FLOW_4, pulseCounter4, FLOW_INTERUPT_CHANGE_TYPE);
  }
  if (isEnableFlow5 == false){
    isEnableFlow5 = true;
    attachInterrupt(PIN_INTERUPT_FLOW_5, pulseCounter5, FLOW_INTERUPT_CHANGE_TYPE);
  }
  if (isEnableFlow6 == false){
    isEnableFlow6 = true;
    attachInterrupt(PIN_INTERUPT_FLOW_6, pulseCounter6, FLOW_INTERUPT_CHANGE_TYPE);
  }
  if (isEnableFlow7 == false){
    isEnableFlow7 = true;
    attachInterrupt(PIN_INTERUPT_FLOW_7, pulseCounter7, FLOW_INTERUPT_CHANGE_TYPE);
  }
  if (isEnableFlow8 == false){
    isEnableFlow8 = true;
    attachInterrupt(PIN_INTERUPT_FLOW_8, pulseCounter8, FLOW_INTERUPT_CHANGE_TYPE);
  }
  if (isEnableFlow9 == false){
    isEnableFlow9 = true;
    attachInterrupt(PIN_INTERUPT_FLOW_9, pulseCounter9, FLOW_INTERUPT_CHANGE_TYPE);
  }
  if (isEnableFlow10 == false){
    isEnableFlow10 = true;
    attachInterrupt(PIN_INTERUPT_FLOW_10, pulseCounter10, FLOW_INTERUPT_CHANGE_TYPE);
  }
  if (isEnableFlow11 == false){
    isEnableFlow11 = true;
    attachInterrupt(PIN_INTERUPT_FLOW_11, pulseCounter11, FLOW_INTERUPT_CHANGE_TYPE);
  }
  if (isEnableFlow12 == false){
    isEnableFlow12 = true;
    attachInterrupt(PIN_INTERUPT_FLOW_12, pulseCounter12, FLOW_INTERUPT_CHANGE_TYPE);
  }

}

void disable_all_flow_interupt(){
  if (isEnableFlow1){
    detachInterrupt(PIN_INTERUPT_FLOW_1);
    isEnableFlow1 = false;
  }
  if (isEnableFlow2){
    detachInterrupt(PIN_INTERUPT_FLOW_2);
    isEnableFlow2 = false;
  }
  if (isEnableFlow3){
    detachInterrupt(PIN_INTERUPT_FLOW_3);
    isEnableFlow3 = false;
  }
  if (isEnableFlow4){
    detachInterrupt(PIN_INTERUPT_FLOW_4);
    isEnableFlow4 = false;
  }
  if (isEnableFlow5){
    detachInterrupt(PIN_INTERUPT_FLOW_5);
    isEnableFlow5 = false;
  }
  if (isEnableFlow6){
    detachInterrupt(PIN_INTERUPT_FLOW_6);
    isEnableFlow6 = false;
  }
  if (isEnableFlow7){
    detachInterrupt(PIN_INTERUPT_FLOW_7);
    isEnableFlow7 = false;
  }
  if (isEnableFlow8){
    detachInterrupt(PIN_INTERUPT_FLOW_8);
    isEnableFlow8 = false;
  }
  if (isEnableFlow9){
    detachInterrupt(PIN_INTERUPT_FLOW_9);
    isEnableFlow9 = false;
  }
  if (isEnableFlow10){
    detachInterrupt(PIN_INTERUPT_FLOW_10);
    isEnableFlow10 = false;
  }
  if (isEnableFlow11){
    detachInterrupt(PIN_INTERUPT_FLOW_11);
    isEnableFlow11 = false;
  }
  if (isEnableFlow12){
    detachInterrupt(PIN_INTERUPT_FLOW_12);
    isEnableFlow12 = false;
  }

}

#endif