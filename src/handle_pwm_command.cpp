#include "handle_pwm_command.h"
#include <Arduino.h>
#include "pins_define.h"

extern unsigned char receivingBuffer[128];
extern unsigned char sendingBuffer[128];

extern byte receivingLength;
extern byte sendingLength;

extern bool isResponseReady;

extern byte pwmValue1, pwmValue2, pwmValue3, pwmValue4, pwmValue5, pwmValue6, pwmValue7, pwmValue8, pwmValue9;

#if (ACTIVE_BOARD == BOARD_ATMEGA2560)

void handlePWMCommand(unsigned char command_code){
    switch (command_code)
    {
    case CM_PWM_SET_PIN_VALUE:
        set_pwm_value();
        break;
    case CM_PWM_GET_PIN_VALUE:
        get_pwm_value();
        break;
    case CM_PWM_SET_ALL_PINS_VALUE:
        set_all_pwm_values();
        break;
    case CM_PWM_GET_ALL_PINS_VALUE:
        get_all_pwm_values();
        break;

    default:
        sendingBuffer[0] = RESPONSE_UNKNOW_CM;
        sendingLength = 1;
        isResponseReady = true;
        break;
    }
}
void set_all_pwm_values(){
    if (receivingLength != 10) {  // check if request length is valid
        sendingBuffer[0] = RESPONSE_BAD_REQUEST;
        sendingLength = 1;
        isResponseReady = true;
        return;
    }

    byte setValue1 = receivingBuffer[1];
    byte setValue2 = receivingBuffer[2];
    byte setValue3 = receivingBuffer[3];
    byte setValue4 = receivingBuffer[4];
    byte setValue5 = receivingBuffer[5];
    byte setValue6 = receivingBuffer[6];
    byte setValue7 = receivingBuffer[7];
    byte setValue8 = receivingBuffer[8];
    byte setValue9 = receivingBuffer[9];


    analogWrite(PIN_PWM_1, setValue1); pwmValue1 = setValue1;
    analogWrite(PIN_PWM_2, setValue2); pwmValue2 = setValue2;
    analogWrite(PIN_PWM_3, setValue3); pwmValue3 = setValue3;
    analogWrite(PIN_PWM_4, setValue4); pwmValue4 = setValue4;
    analogWrite(PIN_PWM_5, setValue5); pwmValue5 = setValue5;
    analogWrite(PIN_PWM_6, setValue6); pwmValue6 = setValue6;
    analogWrite(PIN_PWM_7, setValue7); pwmValue7 = setValue7;
    analogWrite(PIN_PWM_8, setValue8); pwmValue8 = setValue8;
    analogWrite(PIN_PWM_9, setValue9); pwmValue9 = setValue9;

    sendingBuffer[0] = RESPONSE_OK;
    sendingLength = 1;
    isResponseReady = true;
    return;
}

void get_all_pwm_values(){
    if (receivingLength != 1) {  // check if request length is valid
        sendingBuffer[0] = RESPONSE_BAD_REQUEST;
        sendingLength = 1;
        isResponseReady = true;
        return;
    }

    sendingBuffer[0] = RESPONSE_OK;

    sendingBuffer[1] = pwmValue1;
    sendingBuffer[2] = pwmValue2;
    sendingBuffer[3] = pwmValue3;
    sendingBuffer[4] = pwmValue4;
    sendingBuffer[5] = pwmValue5;
    sendingBuffer[6] = pwmValue6;
    sendingBuffer[7] = pwmValue7;
    sendingBuffer[8] = pwmValue8;
    sendingBuffer[9] = pwmValue9;

    sendingLength = 10;
    isResponseReady = true;
}

void set_pwm_value(){
    if (receivingLength != 3) {  // check if request length is valid
        sendingBuffer[0] = RESPONSE_BAD_REQUEST;
        sendingLength = 1;
        isResponseReady = true;
        return;
    }

    byte pin = receivingBuffer[1];
    byte setValue = receivingBuffer[2];

    if (pin == PIN_PWM_1 || pin== PIN_PWM_2 || pin == PIN_PWM_3 ||
        pin == PIN_PWM_4 || pin== PIN_PWM_5 || pin == PIN_PWM_6 ||
        pin == PIN_PWM_7 || pin== PIN_PWM_8 || pin == PIN_PWM_9 ) {   //  Check valid pin
        
        if (pin == PIN_PWM_1) pwmValue1 = setValue;
        else if  (pin == PIN_PWM_2) pwmValue2 = setValue;
        else if  (pin == PIN_PWM_3) pwmValue3 = setValue;
        else if  (pin == PIN_PWM_4) pwmValue4 = setValue;
        else if  (pin == PIN_PWM_5) pwmValue5 = setValue;
        else if  (pin == PIN_PWM_6) pwmValue6 = setValue;
        else if  (pin == PIN_PWM_7) pwmValue7 = setValue;
        else if  (pin == PIN_PWM_8) pwmValue8 = setValue;
        else if  (pin == PIN_PWM_9) pwmValue9 = setValue;

        analogWrite(pin, setValue);
        sendingBuffer[0] = RESPONSE_OK;
        sendingLength = 1;
        isResponseReady = true;
        return;

    }else {   // Invalid pin
        sendingBuffer[0] = RESPONSE_FAIL;
        sendingLength = 1;
        isResponseReady = true;
        return;
    }
}

void get_pwm_value(){
    if (receivingLength != 2) {  // check if request length is valid
        sendingBuffer[0] = RESPONSE_BAD_REQUEST;
        sendingLength = 1;
        isResponseReady = true;
        return;
    }

    byte pin = receivingBuffer[1];

    if (pin == PIN_PWM_1 || pin== PIN_PWM_2 || pin == PIN_PWM_3 ||
        pin == PIN_PWM_4 || pin== PIN_PWM_5 || pin == PIN_PWM_6 ||
        pin == PIN_PWM_7 || pin== PIN_PWM_8 || pin == PIN_PWM_9 ) {   //  Check valid pin
        
        byte returnValue = 0;
        if (pin == PIN_PWM_1) returnValue = pwmValue1;
        else if  (pin == PIN_PWM_2) returnValue = pwmValue2;
        else if  (pin == PIN_PWM_3) returnValue = pwmValue3;
        else if  (pin == PIN_PWM_4) returnValue = pwmValue4;
        else if  (pin == PIN_PWM_5) returnValue = pwmValue5;
        else if  (pin == PIN_PWM_6) returnValue = pwmValue6;
        else if  (pin == PIN_PWM_7) returnValue = pwmValue7;
        else if  (pin == PIN_PWM_8) returnValue = pwmValue8;
        else if  (pin == PIN_PWM_9) returnValue = pwmValue9;


        sendingBuffer[0] = RESPONSE_OK;
        sendingBuffer[1] = returnValue;
        sendingLength = 2;
        isResponseReady = true;
        return;

    }else {   // Invalid pin
        sendingBuffer[0] = RESPONSE_FAIL;
        sendingLength = 1;
        isResponseReady = true;
        return;
    }
}

#endif

void setPWMPinMode(){

#if (ACTIVE_BOARD == BOARD_ATMEGA2560)
    pinMode(PIN_PWM_1, OUTPUT);
    pinMode(PIN_PWM_2, OUTPUT);
    pinMode(PIN_PWM_3, OUTPUT);
    pinMode(PIN_PWM_4, OUTPUT);
    pinMode(PIN_PWM_5, OUTPUT);
    pinMode(PIN_PWM_6, OUTPUT);
    pinMode(PIN_PWM_7, OUTPUT);
    pinMode(PIN_PWM_8, OUTPUT);
    pinMode(PIN_PWM_9, OUTPUT);

    pwmValue1= pwmValue2= pwmValue3= pwmValue4= pwmValue5= pwmValue6= pwmValue7= pwmValue8= pwmValue9= 0;

    analogWrite(PIN_PWM_1, 0);
    analogWrite(PIN_PWM_2, 0);
    analogWrite(PIN_PWM_3, 0);
    analogWrite(PIN_PWM_4, 0);
    analogWrite(PIN_PWM_5, 0);
    analogWrite(PIN_PWM_6, 0);
    analogWrite(PIN_PWM_7, 0);
    analogWrite(PIN_PWM_8, 0);
    analogWrite(PIN_PWM_9, 0);
#endif

}