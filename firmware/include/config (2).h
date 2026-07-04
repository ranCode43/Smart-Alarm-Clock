#ifndef CONFIG_H
#define CONFIG_H

#define OLED_ADDR 0x3C
#define BME280_ADDR 0x76

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define RGB_COUNT 16
#define RGB_BRIGHTNESS 60

#define WIFI_SSID "YOUR_SSID"
#define WIFI_PASS "YOUR_PASSWORD"
#define NTP_SERVER "pool.ntp.org"
#define GMT_OFFSET_SEC -18000
#define DST_OFFSET_SEC 3600

#define PREFS_NAMESPACE "clock"

#endif
