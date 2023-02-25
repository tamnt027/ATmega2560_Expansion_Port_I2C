#ifndef Handle_PWM_Command_h
#define Handle_PWM_Command_h

void handlePWMCommand(unsigned char command_code);

void setPWMPinMode();

void set_pwm_value();
void get_pwm_value();

void set_all_pwm_values();
void get_all_pwm_values();
#endif