#ifndef Handle_PWM_Command_h
#define Handle_PWM_Command_h

void setPWMPinMode();

#if (ACTIVE_BOARD == BOARD_ATMEGA2560)
void handlePWMCommand(unsigned char command_code);


void set_pwm_value();
void get_pwm_value();

void set_all_pwm_values();
void get_all_pwm_values();
#endif


#endif