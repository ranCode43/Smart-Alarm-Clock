#include <Adafruit_NeoPixel.h>
#include "pins.h"
#include "config.h"
#include "clock_state.h"
#include "rgb_effects.h"

static Adafruit_NeoPixel ring(RGB_COUNT, RGB_PIN, NEO_GRB + NEO_KHZ800);
static unsigned long lastStep = 0;
static uint16_t hue = 0;

void rgbInit() {
  ring.begin();
  ring.setBrightness(RGB_BRIGHTNESS);
  ring.show();
}

void rgbUpdate() {
  if (millis() - lastStep < 30) return;
  lastStep = millis();

  if (currentState == ALARM_TRIGGERED) {
    uint8_t b = (millis() / 100 % 2 == 0) ? 255 : 0;
    for (int i = 0; i < RGB_COUNT; i++) ring.setPixelColor(i, ring.Color(b, 0, 0));
  } else {
    hue += 100;
    for (int i = 0; i < RGB_COUNT; i++) {
      ring.setPixelColor(i, ring.gamma32(ring.ColorHSV(hue + i * 4000)));
    }
  }
  ring.show();
}
