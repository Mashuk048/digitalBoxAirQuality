#include "Adafruit_CCS811.h"

Adafruit_CCS811 ccs;

void setup() {
  Serial.begin(115200);
  
  Serial.println("CCS811 Reading CO2 and VOC");
  if(!ccs.begin()){
    Serial.println("Failed to start sensor! Please check your wiring.");
    while(1);
  }
  //calibrate temperature sensor
  while(!ccs.available());
  float temp = ccs.calculateTemperature();
  ccs.setTempOffset(temp - 25.0);
}

void loop() {
  if(ccs.available()){
    float temp = ccs.calculateTemperature();
    if(!ccs.readData()){
      Serial.println("CO2: "+String(ccs.geteCO2())+"ppm, TVOC: "+String(ccs.getTVOC())+"ppb   Temp:"+String(temp));
    }
    else{
      Serial.println("Sensor read ERROR!");
      ccs.readData();
    }
  }
  delay(500);
}

