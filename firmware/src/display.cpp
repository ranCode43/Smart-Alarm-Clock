#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_BME280.h>
#include "time.h"
#include "pins.h"
#include "config.h"
#include "clock_state.h"
#include "display.h"

static Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
static Adafruit_BME280 bme;

extern const char* menuItems[];
extern const int menuCount;

void displayInit() {
  Wire.begin(SDA_PIN, SCL_PIN);
  oled.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
  oled.clearDisplay();
  oled.setTextColor(SSD1306_WHITE);
  oled.display();
  bme.begin(BME280_ADDR);
}

float readTemperature() {
  return bme.readTemperature();
}

void renderClockScreen() {
  struct tm t;
  if (!getLocalTime(&t)) return;

  float temp = readTemperature();

  oled.clearDisplay();
  oled.setTextSize(2);
  oled.setCursor(10, 5);
  char timeStr[9];
  sprintf(timeStr, "%02d:%02d", t.tm_hour, t.tm_min);
  oled.println(timeStr);

  oled.setTextSize(1);
  oled.setCursor(10, 30);
  char dateStr[16];
  sprintf(dateStr, "%02d/%02d/%04d", t.tm_mon + 1, t.tm_mday, t.tm_year + 1900);
  oled.println(dateStr);

  oled.setCursor(10, 45);
  oled.print(temp, 1);
  oled.println(" C");

  if (alarmEnabled) {
    oled.setCursor(80, 45);
    char aStr[8];
    sprintf(aStr, "%02d:%02d", alarmHour, alarmMin);
    oled.print(aStr);
  }

  oled.display();
}

void renderMenuScreen() {
  oled.clearDisplay();
  oled.setTextSize(1);
  oled.setCursor(0, 0);
  oled.println("-- MENU --");
  for (int i = 0; i < menuCount; i++) {
    oled.setCursor(5, 15 + i * 12);
    oled.print(i == menuIndex ? "> " : "  ");
    oled.println(menuItems[i]);
  }
  oled.display();
}

void renderSetAlarmScreen() {
  oled.clearDisplay();
  oled.setTextSize(1);
  oled.setCursor(0, 0);
  oled.println("Set Alarm (rotate)");
  oled.setTextSize(2);
  oled.setCursor(20, 25);
  char aStr[8];
  sprintf(aStr, "%02d:%02d", alarmHour, alarmMin);
  oled.println(aStr);
  oled.display();
}

void renderAlarmScreen() {
  oled.clearDisplay();
  oled.setTextSize(2);
  oled.setCursor(10, 25);
  oled.println("ALARM!");
  oled.display();
}
