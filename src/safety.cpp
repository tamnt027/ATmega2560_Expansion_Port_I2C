#include "safety.h"
#include <Arduino.h>
#include "defines.h"
#include "ultility.h"

extern unsigned long latestIncomingCommandTime;
#ifdef SERIAL_DEBUG
unsigned long latestPrintIdleTime = 0;
#endif

void safety_idle_time_reach_limit(){
    unsigned long idleTime = millis() - latestIncomingCommandTime;

#ifdef SERIAL_DEBUG
    if ((idleTime / 1000) % 10 == 0 && 
    (millis() - latestPrintIdleTime > 1000))  {  // This prevent print multiple line within 1 second.
        
        Serial.print("Idle time in sec ");
        Serial.println(idleTime / 1000);
        latestPrintIdleTime = millis();
    }

#endif

    if ((idleTime / 1000) >  MAX_IDLE_TIME_IN_SEC) {   // If reach the limit, then reset device
        hard_reset_device();
    }
}


extern bool isPlaningReset;
extern unsigned long planingResetTime;

void safety_planning_reset(){   // planing reset from master.
    if (isPlaningReset && millis() > planingResetTime){
        hard_reset_device();
    }
}