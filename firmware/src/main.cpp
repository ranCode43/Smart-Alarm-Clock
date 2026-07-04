#include <Arduino.h>
#include <WiFi.h>
#include "time.h"
#include "pins.h"
#include "config.h"
#include "clock_state.h"
#include "encoder.h"
#include "display.h"
#include "rgb_effects.h"
#include "alarm.h"

const char* menuItems[] = {"Set Alarm", "Toggle Alarm", "Back"};
const int menuCount = 3;

static void connectWiFiAndSyncTime() {
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  unsigned long start = millis();
  while (WiFi.status() != WL_CONNECTED && millis() - start < 15000) {
    delay(300);
  }
  if (WiFi.status() == WL_CONNECTED) {
    configTime(GMT_OFFSET_SEC, DST_OFFSET_SEC, NTP_SERVER);
  }
}

static void handleEncoderButton() {
  if (!encBtnPressed) return;
  encBtnPressed = false;

  switch (currentState) {
    case CLOCK_DISPLAY:
      currentState = MENU;
      menuIndex = 0;
      break;
    case MENU:
      if (menuIndex == 0) currentState = SET_ALARM;
      else if (menuIndex == 1) { alarmEnabled = !alarmEnabled; alarmSave(); }
      else currentState = CLOCK_DISPLAY;
      break;
    case SET_ALARM:
      alarmSave();
      currentState = MENU;
      break;
    case ALARM_TRIGGERED:
      alarmStop();
      currentState = CLOCK_DISPLAY;
      break;
  }
}

static void handleMenuNav() {
  static int lastPos = 0;
  int delta = encPos - lastPos;
  if (delta == 0) return;
  menuIndex = (menuIndex + (delta > 0 ? 1 : -1) + menuCount) % menuCount;
  lastPos = encPos;
}

static void handleAlarmSet() {
  static int lastPos = 0;
  int delta = encPos - lastPos;
  if (delta == 0) return;
  alarmMin += delta;
  if (alarmMin >= 60) { alarmMin = 0; alarmHour = (alarmHour + 1) % 24; }
  if (alarmMin < 0) { alarmMin = 59; alarmHour = (alarmHour + 23) % 24; }
  lastPos = encPos;
}

void setup() {
  Serial.begin(115200);

  encoderInit();
  displayInit();
  rgbInit();
  alarmInit();
  connectWiFiAndSyncTime();
}

void loop() {
  handleEncoderButton();

  struct tm t;
  bool haveTime = getLocalTime(&t);

  switch (currentState) {
    case CLOCK_DISPLAY:
      renderClockScreen();
      if (haveTime) alarmCheck(t);
      break;
    case MENU:
      handleMenuNav();
      renderMenuScreen();
      break;
    case SET_ALARM:
      handleAlarmSet();
      renderSetAlarmScreen();
      break;
    case ALARM_TRIGGERED:
      alarmSound();
      renderAlarmScreen();
      break;
  }

  rgbUpdate();
  delay(20);
}
