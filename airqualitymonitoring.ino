#include "DHT.h"
#include "Adafruit_CCS811.h"
#define DHTTYPE DHT22   // there are multiple kinds of DHT sensors

Adafruit_CCS811 ccs;

uint8_t DHTPin = D7;

DHT dht(DHTPin, DHTTYPE);

float Temperature;
float Humidity;

int analogPin = A0;
int gasPin = A0;

void setup() {
  Serial.begin(115200);
  delay(100);
  pinMode(DHTPin, INPUT);
  dht.begin();

  //cjmcu1100
  //Serial.begin(115200);
  pinMode(analogPin, INPUT);

  //ccs811
  Serial.println("CCS811 Reading CO2 and VOC");
  if (!ccs.begin()) {
    Serial.println("Failed to start sensor! Please check your wiring.");
    while (1);
  }
  //calibrate temperature sensor
  while (!ccs.available());
  float temp = ccs.calculateTemperature();
  ccs.setTempOffset(temp - 25.0);

}

void loop() {
  Temperature = dht.readTemperature();
  Humidity = dht.readHumidity();
  int sensorValue = analogRead(analogPin);
  float voltage = sensorValue * (5.0/1023.0);

  int gas = analogRead(gasPin);

  //dht22
  Serial.print("DHT Humidity: ");
  Serial.print(Humidity);
  Serial.print(" %\t");
  Serial.print("DHT Temperature: ");
  Serial.print(Temperature);
  Serial.print(" °C\n\n");
  delay(1000);

  //ccs811
  if(ccs.available()){
    float temp = ccs.calculateTemperature();
    if(!ccs.readData()){
      Serial.println("CO2: "+String(ccs.geteCO2())+"ppm, TVOC: "+String(ccs.getTVOC())+"ppb   CCS_Temp:"+String(temp));
      //Serial.println("CO2: "+String(ccs.geteCO2())+"ppm, TVOC: "+String(ccs.getTVOC())+"ppb");
    }
    else{
      Serial.println("Sensor read ERROR!");
      ccs.readData();
    }
  }
  delay(500);

  //CJMCU1100
  Serial.print("MS1100 Value: ");
  Serial.println(sensorValue);
  Serial.print("Vout: ");
  Serial.println(voltage);
  Serial.print("\n");

  float formaldehyde2 = pow(10, ((-2.631) + 1.528 * voltage + (-0.125) * (voltage*voltage)));
  float toluene1 = pow(10, ((-7.071) + 2.852 * voltage + (-0.210) * (voltage * voltage)));

  Serial.print("Formaldehyde : ");
  Serial.println(formaldehyde2);
  Serial.print("Toluene : ");
  Serial.println(toluene1);
  Serial.print("\n");

  //MQ4
  Serial.print("CH4 : ");
  Serial.println(gas);
  Serial.print("\n");
  
  delay(1000);

}
