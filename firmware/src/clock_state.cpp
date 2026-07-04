#include "clock_state.h"

ClockState currentState = CLOCK_DISPLAY;

int alarmHour = 7;
int alarmMin = 0;
bool alarmEnabled = false;
bool alarmFiredToday = false;

volatile int encPos = 0;
volatile bool encBtnPressed = false;

int menuIndex = 0;
