#include <Arduino.h>
#include "pins_define.h"
#include "defines.h"
#include <Wire.h>
#include "handle_analog_input_command.h"
#include "handle_device_query_command.h"
#include "handle_flow_command.h"
#include "handle_pwm_command.h"
#include "handle_digital_output_command.h"
#include "ultility.h"
#include <WireSlave.h>
#include "safety.h"
// define pulse counter 
volatile uint16_t pulseCount1, pulseCount2, pulseCount3, pulseCount4, pulseCount5, pulseCount6;
volatile uint16_t pulseCount7, pulseCount8, pulseCount9, pulseCount10, pulseCount11, pulseCount12;


bool led_at_high = false;

float flowRate1, flowRate2, flowRate3, flowRate4, flowRate5, flowRate6;
float flowRate7, flowRate8, flowRate9, flowRate10, flowRate11, flowRate12;

bool isEnableFlow1, isEnableFlow2,isEnableFlow3,isEnableFlow4,isEnableFlow5,isEnableFlow6;
bool isEnableFlow7, isEnableFlow8,isEnableFlow9,isEnableFlow10,isEnableFlow11,isEnableFlow12;

unsigned long oldTime1, oldTime2, oldTime3, oldTime4, oldTime5, oldTime6;
unsigned long oldTime7, oldTime8, oldTime9, oldTime10, oldTime11, oldTime12; 


unsigned long latestIncomingCommandTime;

byte pwmValue1, pwmValue2, pwmValue3, pwmValue4, pwmValue5, pwmValue6, pwmValue7, pwmValue8, pwmValue9;

int addressI2C;

// This flag indicate that device need a acknowledment from master to operate properly (aka handshakes)
bool isRequiredAck;

bool isPlaningReset;
unsigned long planingResetTime;
// 
unsigned char receivingBuffer[128];
unsigned char sendingBuffer[128];

byte receivingLength;
byte sendingLength;

bool isResponseReady;




void reset_all_pusle_count(){
  pulseCount1 = 0;
  pulseCount2 = 0;
  pulseCount3 = 0;
  pulseCount4 = 0;
  pulseCount5 = 0;
  pulseCount6 = 0;
  pulseCount7 = 0;
  pulseCount8 = 0;
  pulseCount9 = 0;
  pulseCount10 = 0;
  pulseCount11 = 0;
  pulseCount12 = 0;
}

void reset_all_flow_rate(){
  flowRate1 = 0;
  flowRate2 = 0;
  flowRate3 = 0;
  flowRate4 = 0;
  flowRate5 = 0;
  flowRate6 = 0;
  flowRate7 = 0;
  flowRate8 = 0;
  flowRate9 = 0;
  flowRate10 = 0;
  flowRate11 = 0;
  flowRate12 = 0;
}



void handleAnalogInput(char command_code){

}

void handleDigitalOutput(char command_code){

}



// This board receive command from master and send response back
void receiveEvent(int howMany)
{
  Serial.println("receiveEvent");
  latestIncomingCommandTime = millis();  // record latest incomming command time
  receivingLength = 0;

  #if (ACTIVE_BOARD == BOARD_ESP32_DEVKIT_V1)
  if (WireSlave.available()){

    while (WireSlave.available())
    {
      receivingBuffer[receivingLength] = WireSlave.read();
      receivingLength++;
    }
  #elif (ACTIVE_BOARD == BOARD_ATMEGA2560)
  if (Wire.available()){

    while (Wire.available())
    {
      receivingBuffer[receivingLength] = Wire.read();
      receivingLength++;
    }
  #endif 

    receivingBuffer[receivingLength] = '\0';

    isResponseReady = false; // 

    unsigned char command_code = receivingBuffer[0];
    unsigned char command_group = command_code & B11110000;
    #ifdef SERIAL_DEBUG
        // Initialize a serial connection for reporting values to the host
        Serial.print("Received command ");
        Serial.println((int)command_code);
    #endif


    if (isRequiredAck && (command_code != CM_DEVICE_ACKNOWLEDGEMENT)) {   //If not

        #ifdef SERIAL_DEBUG
          // Initialize a serial connection for reporting values to the host
        Serial.println("Received a command, but an acknowledment required!!!");
        #endif
        
        sendingBuffer[0] = RESPONSE_REQUIRED_ACK;
        sendingLength = 1;
        isResponseReady = true;
        return;
    }

    switch (command_group)
    {
  #if (ACTIVE_BOARD == BOARD_ESP32_DEVKIT_V1)
    case B10000000:  // Flow Group
      handleFlowCommand(command_code);
      break;
  #endif

#if (ACTIVE_BOARD == BOARD_ATMEGA2560)
    case B10010000:  // PWM Group
      handlePWMCommand(command_code);
      break;
#endif  
    case B10100000:  // Analog Input Group
      handleAnalogInput(command_code);
      break;
    case B10110000:  // Digital Output Group
      handleDigitalOutput(command_code);
      break;

    case B11000000:  // Device queries Group
      handleDeviceQuery(command_code);
      break;
    
    default:
      // Return UNKNOW COMMAND
        sendingBuffer[0] = RESPONSE_UNKNOW_CM;
        sendingLength = 1;
        isResponseReady = true;
        return;
      break;
    }
  }
}

void sendEvent(){
  #if (ACTIVE_BOARD == BOARD_ESP32_DEVKIT_V1)
    if (isResponseReady) {
        WireSlave.write(sendingBuffer, sendingLength);

    }else{
        uint8_t data_uncompleted_command = RESPONSE_DATA_UNCOMPLETED;
        WireSlave.write(data_uncompleted_command);
    }
  #elif (ACTIVE_BOARD == BOARD_ATMEGA2560)
    if (isResponseReady) {
        Wire.write(sendingBuffer, sendingLength);

    }else{
        uint8_t data_uncompleted_command = RESPONSE_DATA_UNCOMPLETED;
        Wire.write(data_uncompleted_command);
    }
  #endif

}

void setup()
{
#ifdef SERIAL_DEBUG
  // Initialize a serial connection for reporting values to the host
  Serial.begin(BAUD_RATE);
#endif
   
  // Get address I2C
  addressI2C = getI2CAddress();

  isRequiredAck = true;

  isPlaningReset = false;

#if (ACTIVE_BOARD == BOARD_ATMEGA2560)
  Wire.begin(addressI2C);
  // Register function when receive command from master
  Wire.onReceive(receiveEvent); 
#elif (ACTIVE_BOARD == BOARD_ESP32_DEVKIT_V1)

    bool success = WireSlave.begin(SDA_PIN, SCL_PIN, addressI2C);
    Serial.println(success);
    if (!success) {
        #ifdef SERIAL_DEBUG
          // Initialize a serial connection for reporting values to the host
          Serial.println("Init I2C failed.");
        #endif
        while(1) delay(100);
    }

    WireSlave.onReceive(receiveEvent);
    WireSlave.onRequest(sendEvent);
#endif

  latestIncomingCommandTime = 0;


#if (ACTIVE_BOARD == BOARD_ESP32_DEVKIT_V1)
  oldTime1 = oldTime2 = oldTime3 = oldTime4 = oldTime5 = oldTime6 = 0 ;
  oldTime7 = oldTime8 = oldTime9 = oldTime10 = oldTime11 = oldTime12 = 0; 
  set_flow_pinmode();
  reset_all_pusle_count();
  reset_all_flow_rate();
  enable_all_flow_interupts();
#endif

  setPWMPinMode();
  // Set up the status LED line as an output
  pinMode(PIN_LED_OPERATE, OUTPUT);

}


/**
 * Main program loop
 */
void loop()
{

#if (ACTIVE_BOARD == BOARD_ESP32_DEVKIT_V1)
  WireSlave.update();
  delay(1);
#endif

  safety_idle_time_reach_limit();
  safety_planning_reset();

#if (ACTIVE_BOARD == BOARD_ESP32_DEVKIT_V1)
  update_flow_1();
  update_flow_2();
  update_flow_3();
  update_flow_4();
  update_flow_5();
  update_flow_6();
  update_flow_7();
  update_flow_8();
  update_flow_9();
  update_flow_10();
  update_flow_11();
  update_flow_12();

#endif
   


}
