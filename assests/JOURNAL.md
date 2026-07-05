# Build Journal — Smart RGB Clock

June 3-5, 9 hrs
## Planning
Picked this as the new A-tier project because it uses multiple components (display, RGB, sensor, input) but keeps a manageable scope — no custom PCB, all off-the-shelf modules, design-only submission

- ESP32 over Pico: built-in WiFi means NTP time sync instead of a separate RTC module — fewer parts, more accurate time.
- OLED + BME280 share the I2C bus (different addresses) — only 2 signal pins used for both.
- WS2812B ring driven off a single data pin, individually addressable, no per-LED resistors needed.
- Alarm settings stored in flash  so they survive power loss without a battery-backed RTC.
- Firmware split into modules  same pattern as the LED Cube firmware — each file owns one subsystem.

## Wiring
Pinout finalized: I2C on 21/22, RGB data on 4, encoder on 32/33/25, buzzer on 27. 

## Firmware
State machine: CLOCK_DISPLAY, MENU, SET_ALARM, ALARM_TRIGGERED. Encoder rotation handled via interrupt so it stays responsive independent of display refresh rate. RGB animation updates every 30ms 

