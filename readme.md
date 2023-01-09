Simple BLE scanner using clone of WeMos LOLIN32 Lite (Retired)

All output is dumped to the serial port, so it should work on any ESP32 dev board.

Based on https://github.com/espressif/arduino-esp32/tree/master/libraries/BLE/examples/BLE_scan

To configure the Arduino IDE to build and program ESP32 devices see https://docs.espressif.com/projects/arduino-esp32/en/latest/getting_started.html
or follow the link from https://github.com/espressif/arduino-esp32
Board manager:  https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json

Arduino board:  "WEMOS LOLIN32-Lite" All other settings at default. Should work with "ESP32 Dev Module" but need to change the LED pin to 2.
Board info:
BN:   Unknown board
VID:  1A86
PID:  7523
SN:   Upload any sketch to obtain it

WeMos has dropped the LOLIN32-Lite from their website. (Probably because of all the clones.)
Internet Archive: https://web.archive.org/web/20191002041532/https://wiki.wemos.cc/products:lolin32:lolin32_lite

User LED is on I/O 22
no user button.

Microcontroller	    ESP32-DOWDQ6 (single core)
Operating Voltage	  3.3V
Digital I/O Pins	  19
Analog Input Pins	  6
Clock Speed(Max)	  240Mhz
Flash	              4M bytes (T25S32)
Length	            5mm
Width	              2.54mm
Weight	            4g
All of the IO pins run at 3.3V.

Battery Connector: PH-2 2.0mm
Lithium battery interface:
TP4054 or LT
 500mA Max charging current

some of the clones have bad LiON charger chips. Video showing its replacement https://www.youtube.com/watch?v=a9f9vHjQSfQ

may have AMS1117 or low power ME6211