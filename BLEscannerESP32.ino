/*
   Based on Neil Kolban example for IDF: https://github.com/nkolban/esp32-snippets/blob/master/cpp_utils/tests/BLE%20Tests/SampleScan.cpp
   Ported to Arduino ESP32 by Evandro Copercini
*/

#include <Arduino.h>

#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEScan.h>
#include <BLEAdvertisedDevice.h>

//#define LED_BUILTIN 22    // should have been defined for the ESP32, but alas it's not.
#define LED_BUILTIN  2    // used on DOIT ESP32 dev board V1.
#define LOOP_DELAY  2000  // in mS
#define scanTime    5     // BLE scan duration/timeout in seconds

BLEScan* pBLEScan;

class MyAdvertisedDeviceCallbacks: public BLEAdvertisedDeviceCallbacks 
{
    void onResult(BLEAdvertisedDevice advertisedDevice) 
    {
      Serial.printf("   ---> Device: %s.\r\n", advertisedDevice.toString().c_str());
    }
};

void setup() 
{
  delay(2500);
  Serial.begin(115200);
  Serial.println("Scanning...");

  // initialize digital pin LED as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)

  BLEDevice::init("");
  pBLEScan = BLEDevice::getScan(); //create new scan
  pBLEScan->setAdvertisedDeviceCallbacks(new MyAdvertisedDeviceCallbacks());
  pBLEScan->setActiveScan(true); //active scan uses more power, but get results faster
  pBLEScan->setInterval(100);
  pBLEScan->setWindow(99);  // less or equal setInterval value
}

void loop() 
{
  static int  scanCount = 0;

//  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));     // toggle the LED;
  digitalWrite(LED_BUILTIN, LOW);   // off while scanning

  BLEScanResults foundDevices = pBLEScan->start(scanTime, false);

  digitalWrite(LED_BUILTIN, HIGH);  // on while sleeping
  Serial.print("Devices found: ");
  Serial.print(foundDevices.getCount());
  Serial.print(". Scan # ");
  Serial.print(scanCount++);
  Serial.println(" done!");
  pBLEScan->clearResults();   // delete results fromBLEScan buffer to release memory

  delay(LOOP_DELAY);
}
