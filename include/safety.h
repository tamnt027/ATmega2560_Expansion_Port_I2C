#ifndef __Safety_h
#define __Safety_h

// When device not receive any command from master for a defined period (example 5minutes)
// device will be reset for safety.

void safety_idle_time_reach_limit();

#endif