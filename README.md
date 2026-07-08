
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
<img width="957" height="673" alt="Screenshot 2026-07-08 163501" src="https://github.com/user-attachments/assets/7af9b1d3-aa54-4b5c-af99-76d354388231" />
<img width="623" height="634" alt="image" src="https://github.com/user-attachments/assets/eb893cca-eb9a-4378-8726-c715cc0cd1d0" />


#Wiring Diagram
<img width="4284" height="5712" alt="IMG_0008" src="https://github.com/user-attachments/assets/05c099f8-f572-4015-801a-c3f8b077c999" />


