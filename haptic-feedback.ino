#include <Wire.h>
#include "Adafruit_DRV2605.h"

Adafruit_DRV2605 drv;

uint8_t effect = 118; //vibration pattern 1
//uint8_t effect = 16; //vibration pattern 2

unsigned long timer = 900000L; //minutes * 60 * 1000
unsigned long interval = 60000L; //15 minutes
unsigned long vibe = 5000L; //5 seconds


void setup() {
  Serial.begin(9600);
  drv.begin();
  
  drv.selectLibrary(1);
  
  // I2C trigger by sending 'go' command 
  // default, internal trigger when sending GO command
  drv.setMode(DRV2605_MODE_INTTRIG); 
   

  delay(timer); //app time limit 
}

void loop() {
  Serial.print("Effect #"); Serial.println(effect);

    drv.setWaveform(0, effect);  // play effect 
    drv.setWaveform(1, 0);       // end waveform
    drv.go();
    delay(vibe); //vibrate for 5 seconds 
    drv.stop(); 
  
  delay(interval);
}

