#include "handle_device_query_command.h"
#include "Arduino.h"
#include "defines.h"
#include <Wire.h>

extern bool isRequiredAck;

void handleDeviceQuery(char command_code){

  switch (command_code)
  {
  case CM_DEVICE_RESET:  // Enable flow pin
    reset_device();
    break;
  case CM_DEVICE_ALIVE_TIME:
    get_device_alive_time();
    break;

   case CM_DEVICE_ACKNOWLEDGEMENT:
#ifdef SERIAL_DEBUG
  // Initialize a serial connection for reporting values to the host
    Serial.println("Device has an acknowledgement!!");
#endif

    isRequiredAck = false;
    break;   
  default:
    break;
  }
}

void(* resetFunc) (void) = 0;  // declare reset fuction at address 0

void reset_device() {
    resetFunc();
}

void get_device_alive_time(){
    unsigned long alive_time = millis();
    
}