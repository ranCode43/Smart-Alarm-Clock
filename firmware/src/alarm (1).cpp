#include <Arduino.h>
#include <Preferences.h>
#include "time.h"
#include "pins.h"
#include "config.h"
#include "clock_state.h"
#include "alarm.h"

static Preferences prefs;

void alarmInit() {
  pinMode(BUZZER_PIN, OUTPUT);
  prefs.begin(PREFS_NAMESPACE, false);
  alarmHour = prefs.getInt("aHour", 7);
  alarmMin = prefs.getInt("aMin", 0);
  alarmEnabled = prefs.getBool("aOn", false);
}

void alarmSave() {
  prefs.putInt("aHour", alarmHour);
  prefs.putInt("aMin", alarmMin);
  prefs.putBool("aOn", alarmEnabled);
}

void alarmCheck(struct tm &t) {
  if (!alarmEnabled) return;
  if (t.tm_hour == alarmHour && t.tm_min == alarmMin) {
    if (!alarmFiredToday) {
      currentState = ALARM_TRIGGERED;
    }
  } else {
    alarmFiredToday = false;
  }
}

void alarmSound() {
  tone(BUZZER_PIN, 1000);
}

void alarmStop() {
  noTone(BUZZER_PIN);
  alarmFiredToday = true;
}
