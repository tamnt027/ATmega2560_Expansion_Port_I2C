#include "handle_device_query_command.h"
#include "Arduino.h"
#include "defines.h"
#include <Wire.h>

extern bool isRequiredAck;


extern unsigned char receivingBuffer[128];
extern unsigned char sendingBuffer[128];

extern byte receivingLength;
extern byte sendingLength;

extern bool isResponseReady;


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
    sendingBuffer[0] = RESPONSE_OK;
    sendingLength = 1;
    isResponseReady = true;
    break;   
  default:
    break;
  }
}

void(* resetFunc) (void) = 0;  // declare reset fuction at address 0

extern bool isPlaningReset;
extern unsigned long planingResetTime;

void reset_device() {
    isPlaningReset = true;
    planingResetTime = millis() + 1000;
    sendingBuffer[0] = RESPONSE_OK;
    sendingLength = 1;
    isResponseReady = true;
   
}

void get_device_alive_time(){
    unsigned long alive_time = millis();
    unsigned char const * p = reinterpret_cast<unsigned char const *>(&alive_time);
    sendingBuffer[0] = RESPONSE_OK;
    for (int i = 0; i != sizeof(unsigned long); ++i)
    {
        sendingBuffer[1 + i] = p[i];
    }
    sendingLength = 1 + sizeof(unsigned long);
    isResponseReady = true;
}