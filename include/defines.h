

#ifndef __Define_h
#define __Define_h


#define SERIAL_DEBUG   // Comment out this line to disable serial print debug

#ifdef SERIAL_DEBUG
    #define BAUD_RATE 9600
#endif


#define BOARD_ESP32_DEVKIT_V1 100
#define BOARD_ATMEGA2560 200

#define ACTIVE_BOARD BOARD_ATMEGA2560    // IMPORTANT : Must select correct board



#define CM_FLOW_ENABLE_PIN 0x80
#define CM_FLOW_DISABLE_PIN 0x81
#define CM_FLOW_GET_PIN_VALUE 0x82
#define CM_FLOW_GET_PIN_STATUS 0x83
#define CM_FLOW_DISABLE_ALL 0x84
#define CM_FLOW_ENABLE_ALL 0x85
#define CM_FLOW_GET_ALL_PIN_VALUE 0x86

// 0xA0
#define CM_PWM_SET_PIN_VALUE B10100000
#define CM_PWM_GET_PIN_VALUE B10100001
#define CM_PWM_SET_ALL_PINS_VALUE B10100010
#define CM_PWM_GET_ALL_PINS_VALUE B10100011



// 0xC0
#define CM_DEVICE_RESET B11000000
#define CM_DEVICE_ALIVE_TIME B11000001
#define CM_DEVICE_ACKNOWLEDGEMENT B11000010



            // 200: RESPONSE_OK
            // 100: RESPONSE_FAIL
            // 101: UNKNOW_COMMAND

#define RESPONSE_OK 200
#define RESPONSE_FAIL 100
#define RESPONSE_UNKNOW_CM 101
#define RESPONSE_REQUIRED_ACK 102
#define RESPONSE_DATA_UNCOMPLETED 103
#define RESPONSE_BAD_REQUEST 104


// Maximum idle time which the device not receive any command from master. Then it will auto_reset for safety.
#define MAX_IDLE_TIME_IN_SEC (5*60)



#endif