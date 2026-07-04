# Build Journal — Smart RGB Clock

## Planning
Picked this as the new A-tier project because it uses multiple components (display, RGB, sensor, input) but keeps a manageable scope — no custom PCB, all off-the-shelf modules, design-only submission (schematic + firmware + enclosure, no physical build required for this round).

## Architecture decisions
- ESP32 over Pico: built-in WiFi means NTP time sync instead of a separate RTC module — fewer parts, more accurate time.
- OLED + BME280 share the I2C bus (different addresses) — only 2 signal pins used for both.
- WS2812B ring driven off a single data pin, individually addressable, no per-LED resistors needed.
- Alarm settings stored in flash (Preferences) so they survive power loss without a battery-backed RTC.
- Firmware split into modules (display, rgb_effects, encoder, alarm, clock_state) same pattern as the LED Cube firmware — each file owns one subsystem.

## Wiring
Pinout finalized: I2C on 21/22, RGB data on 4, encoder on 32/33/25, buzzer on 27. See assests/Wiring_diagram.svg.

## Firmware
State machine: CLOCK_DISPLAY, MENU, SET_ALARM, ALARM_TRIGGERED. Encoder rotation handled via interrupt so it stays responsive independent of display refresh rate. RGB animation updates every 30ms regardless of display state.

## Enclosure
Desk-wedge form factor planned in Fusion 360 — angled front face, OLED window, recessed diffuser ring around it, side cutout for the encoder shaft, rear USB-C channel. Modeling in progress — see cad/README.md.

## Known limitations
- No battery backup — clock re-syncs over WiFi/NTP on power loss, a few seconds delay before accurate.
- Buzzer is optional — RGB alarm pulse alone works for a silent alarm.
