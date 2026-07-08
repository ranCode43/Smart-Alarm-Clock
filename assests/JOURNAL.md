Build Journal — Smart RGB Clock

June 3-5, 9 hrs

Planning

Picked this as my new A-tier project. Wanted something with a bunch of parts working together but not too crazy — no custom PCB, just off the shelf stuff.


Used an ESP32 instead of a Pico because it has WiFi built in, so it can just grab the time from the internet instead of needing a separate RTC chip
OLED and BME280 both use I2C so they share the same 2 wires instead of needing their own
The RGB ring only needs 1 wire for data which is cool
Alarm saves to flash memory so it doesn't forget when it loses power
Split the firmware into different files like I did on the LED Cube, so each file just does its own thing


Wiring

Figured out all the pins: I2C on 21/22, RGB on 4, encoder on 32/33/25, buzzer on 27.

Firmware

Made a state machine so the clock knows what screen it's on (normal clock, menu, setting the alarm, or alarm going off). Encoder uses interrupts so it doesn't feel laggy.

June 8




Modeled the actual parts instead of just plain boxes — ESP32 with the pin headers, BME280, and the OLED, all real sizes
Put the encoder through the side wall with the little knob and everything
Added a lid so the box actually closes now instead of being open on top
Modeled  M2 screw with actual threads and made mounting holes so the board is screwed in instead of just sitting there loose
Modeled the RGB ring using the real measurements from the listing so the hole actually fits it right
