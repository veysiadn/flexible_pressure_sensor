
#include <Wire.h>
#include <Adafruit_LPS2X.h>
#include <Adafruit_Sensor.h>
#include <Arduino.h>
// For SPI mode, we need a CS pins
#define LPS_CS1 10
#define LPS_CS2 9
#define LPS_CS3 8
#define LPS_CS4 7
// For software-SPI mode we need SCK/MOSI/MISO pins
#define LPS_SCK 13
#define LPS_MISO 12
#define LPS_MOSI 11

#define NUM_OF_SENSORS 4

Adafruit_LPS22 lps[NUM_OF_SENSORS];

void setup(){
  /*Initialize the serial port*/
  Serial.begin(9600);
  while (!Serial) delay(10);     // will pause Zero, Leonardo, etc until serial console opens

  Serial.println("Flexible PCB multiple pressure sensor LPS22 test!");

  //if (!lps.begin_SPI(LPS_CS, LPS_SCK, LPS_MISO, LPS_MOSI)) {}
  
  if (!lps[0].begin_SPI(LPS_CS1)) {
    Serial.println("Failed to find LPS22 1st chip retrying...");
    while (1) { 
      delay(10);
      if(!lps[0].begin_SPI(LPS_CS1))
        continue; 
        break;
      }
  }
  Serial.println("LPS22 1st  Found!");
 delay(10);

  if (!lps[1].begin_SPI(LPS_CS2)) {
    Serial.println("Failed to find LPS22 2nd chip retrying...");
    while (1) { 
      delay(10);
      if(!lps[1].begin_SPI(LPS_CS2)) 
      continue; 
      break;
      }
  }
  Serial.println("LPS22 2nd  Found!");
 delay(10);

  if (!lps[2].begin_SPI(LPS_CS3)) {
    Serial.println("Failed to find LPS22 3rd chip retrying...");
    while (1) {
      delay(10);
      if(!lps[2].begin_SPI(LPS_CS3)) 
      continue; 
      break;
      }
  }
  Serial.println("LPS22 3rd  Found!");
 delay(10);
  if (!lps[3].begin_SPI(LPS_CS4)) {
    Serial.println("Failed to find LPS22 4th chip retrying...");
    while (1) { 
      delay(10);
      if(!lps[3].begin_SPI(LPS_CS4)) 
      continue; 
      break;
      }
  }
  Serial.println("LPS22 4th  Found!");
 delay(10);
  for(int i = 0 ; i < NUM_OF_SENSORS;i++){
    lps[i].setDataRate(LPS22_RATE_50_HZ);
    delay(10);
    Serial.print("Data rate set to: ");
    switch (lps[i].getDataRate()) {
      delay(10);
      case LPS22_RATE_ONE_SHOT: Serial.println("One Shot / Power Down"); break;
      case LPS22_RATE_1_HZ: Serial.println("1 Hz"); break;
      case LPS22_RATE_10_HZ: Serial.println("10 Hz"); break;
      case LPS22_RATE_25_HZ: Serial.println("25 Hz"); break;
      case LPS22_RATE_50_HZ: Serial.println("50 Hz"); break;
      case LPS22_RATE_75_HZ: Serial.println("75 Hz"); break;
    }
 }
}

void loop(){
  /*Read the atmospheric pressure, print data via serial port*/
  sensors_event_t temp[NUM_OF_SENSORS];
  sensors_event_t pressure[NUM_OF_SENSORS];
  for(int i = 0 ; i < 4; i++){
    lps[i].getEvent(&pressure[i], &temp[i]);// get pressure
    //Serial.print("Temperature: ");Serial.print(temp.temperature);Serial.println(" degrees C");
    Serial.print("Pressure: ");Serial.print(i+1);Serial.print(" ");Serial.print(pressure[i].pressure);Serial.println(" hPa\n");
  }
  delay(500);
}
