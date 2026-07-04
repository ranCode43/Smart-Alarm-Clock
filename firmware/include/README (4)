#ifndef CLOCK_STATE_H
#define CLOCK_STATE_H

#include <Arduino.h>

enum ClockState { CLOCK_DISPLAY, MENU, SET_ALARM, ALARM_TRIGGERED };

extern ClockState currentState;

extern int alarmHour;
extern int alarmMin;
extern bool alarmEnabled;
extern bool alarmFiredToday;

extern volatile int encPos;
extern volatile bool encBtnPressed;

extern int menuIndex;

#endif
