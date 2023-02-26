#ifndef Handle_Analog_Input_Command_h
#define Handle_Analog_Input_Command_h

#if (ACTIVE_BOARD == BOARD_ATMEGA2560)
void handleAnalogInputCommand(unsigned char command_code);
void setAnalogInputPinmode();

#endif

#endif