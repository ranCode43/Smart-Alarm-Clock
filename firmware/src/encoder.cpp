#include <Arduino.h>
#include "pins.h"
#include "clock_state.h"
#include "encoder.h"

static int lastClk = HIGH;

void encoderInit() {
  pinMode(ENC_CLK_PIN, INPUT_PULLUP);
  pinMode(ENC_DT_PIN, INPUT_PULLUP);
  pinMode(ENC_SW_PIN, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(ENC_CLK_PIN), onEncoderChange, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ENC_SW_PIN), onEncoderBtn, FALLING);
}

void IRAM_ATTR onEncoderChange() {
  int clk = digitalRead(ENC_CLK_PIN);
  if (clk != lastClk && clk == LOW) {
    encPos += (digitalRead(ENC_DT_PIN) != clk) ? 1 : -1;
  }
  lastClk = clk;
}

void IRAM_ATTR onEncoderBtn() {
  encBtnPressed = true;
}
