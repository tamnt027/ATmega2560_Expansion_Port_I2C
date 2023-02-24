#include "ultility.h"
#include "pins_define.h"
#include <Arduino.h>

extern float flowRate1, flowRate2, flowRate3, flowRate4, flowRate5, flowRate6;
extern float flowRate7, flowRate8, flowRate9, flowRate10, flowRate11, flowRate12;

int getI2CAddress()
{
#if (ACTIVE_BOARD == BOARD_ATMEGA2560)
  // Set input mode for address pin D30; D31; D32; D33
  pinMode(PIN_ADDR_0, INPUT);
  pinMode(PIN_ADDR_1, INPUT);
  pinMode(PIN_ADDR_2, INPUT);
  pinMode(PIN_ADDR_3, INPUT);

  int input0 = digitalRead(PIN_ADDR_0);
  int input1 = digitalRead(PIN_ADDR_1);
  int input2 = digitalRead(PIN_ADDR_2);
  int input3 = digitalRead(PIN_ADDR_3);

  return IC2_ADDR_START_AT + input0 + (input1 << 1) + (input2 << 2) + (input3 << 3);
#else
  return IC2_ADDR_START_AT;
#endif
}

void(* hardresetFunc) (void) = 0;  // declare reset fuction at address 0

void hard_reset_device(){
#ifdef SERIAL_DEBUG
  Serial.println("Hard reset device is triggered!!!");
  hardresetFunc(); // TODO: remove this
#endif
}


void print_all_flow_values(){
    Serial.print("Flow rate 1 ");
    Serial.println(flowRate1);

    Serial.print("Flow rate 2 ");
    Serial.println(flowRate2);

    Serial.print("Flow rate 3 ");
    Serial.println(flowRate3);

    Serial.print("Flow rate 4 ");
    Serial.println(flowRate4);

    Serial.print("Flow rate 5 ");
    Serial.println(flowRate5);

    Serial.print("Flow rate 6 ");
    Serial.println(flowRate6);

    Serial.print("Flow rate 7 ");
    Serial.println(flowRate7);

    Serial.print("Flow rate 8 ");
    Serial.println(flowRate8);

    Serial.print("Flow rate 9 ");
    Serial.println(flowRate9);

    Serial.print("Flow rate 10 ");
    Serial.println(flowRate10);

    Serial.print("Flow rate 11 ");
    Serial.println(flowRate11);

    Serial.print("Flow rate 12 ");
    Serial.println(flowRate12);
}
