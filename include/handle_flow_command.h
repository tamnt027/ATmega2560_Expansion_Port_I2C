#ifndef Handle_Flow_Command_h
#define Handle_Flow_Command_h

void pulseCounter1();
void pulseCounter2();
void pulseCounter3();
void pulseCounter4();
void pulseCounter5();
void pulseCounter6();
void pulseCounter7();
void pulseCounter8();
void pulseCounter9();
void pulseCounter10();
void pulseCounter11();
void pulseCounter12();

void update_flow_1();
void update_flow_2();
void update_flow_3();
void update_flow_4();
void update_flow_5();
void update_flow_6();
void update_flow_7();
void update_flow_8();
void update_flow_9();
void update_flow_10();
void update_flow_11();
void update_flow_12();

void set_flow_pinmode();

void handleFlowCommand(char command_code);
void enable_flow_pin();
void disable_flow_pin();
void get_flow_value();

void enable_all_flow_interupts();
void disable_all_flow_interupt();

#endif