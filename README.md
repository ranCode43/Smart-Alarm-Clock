
# Smart RGB Clock

A WiFi-synced desk clock with ambient RGB animations, a rotary-encoder menu, temperature readout, and an alarm

> Built using Fusion 360, PlatformIO, an ESP32, WS2812B RGB ring, SSD1306 OLED, and a BME280 sensor.

## How it works

The ESP32 connects to WiFi on boot and syncs the time over NTP, so no RTC module is needed. An OLED display shows the time, date, and temperature, while a WS2812B ring runs ambient animations behind it. A rotary encoder lets you navigate a menu to set and toggle an alarm, which is saved to flash so it survives a reboot. When the alarm fires, the ring pulses red and the OLED flashes "ALARM!" until dismissed.

## Why I made it

I wanted a clock on my desk that actually felt like a finished product instead of a breadboard mess, looks professional, uses multiple sensors and a display together

## Features

🕐 Live Clock

NTP-synced time and date, no RTC chip

 Ambient RGB

Smooth breathing rainbow animation on the ring

 Temperature Readout

Live temp pulled from the BME280

 Alarm

Set and toggle via rotary encoder menu, persists across reboot

 Alarm Alert

Ring pulses red + OLED flashes when the alarm fires

## Components

- ESP32 DevKit
- SSD1306 OLED (I2C)
- BME280 (I2C)
- WS2812B RGB ring
- EC11 rotary encoder w/ push button
- Passive piezo buzzer 

## Firmware

The firmware is organized into independent modules so each subsystem has a single responsibility.

- display.cpp → OLED + BME280 rendering
- rgb_effects.cpp → WS2812B ring animations
- encoder.cpp → Rotary encoder input (ISR-driven)
- alarm.cpp → Alarm logic + flash persistence
- clock_state.cpp → Shared state across modules
- main.cpp → Main control loop

## Build Log

See assests/JOURNAL.md for project progress and development history.

## CAD Render
OLED RING isnt in cad or piezo buzzer
<img width="805" height="604" alt="Screenshot 2026-07-04 212627" src="https://github.com/user-attachments/assets/f72b6333-4b9f-412e-b547-e4afe28d34c7" />
<img width="680" height="433" alt="image" src="https://github.com/user-attachments/assets/310e5d0d-6846-405c-94d4-c9cee77faa2b" />

#Wiring Diagram
<img width="4284" height="5712" alt="IMG_0008" src="https://github.com/user-attachments/assets/05c099f8-f572-4015-801a-c3f8b077c999" />


