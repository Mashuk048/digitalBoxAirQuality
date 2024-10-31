#include "DHT.h"
#define DHTTYPE DHT22   // there are multiple kinds of DHT sensors

uint8_t DHTPin = D2;
DHT dht(DHTPin, DHTTYPE);

float Temperature;
float Humidity;

void setup() {
  Serial.begin(115200);
  delay(100);
  pinMode(DHTPin, INPUT);
  dht.begin();
}

void loop() {
    Temperature = dht.readTemperature();
    Humidity = dht.readHumidity();
    Serial.print("Humidity: ");
    Serial.print(Humidity);
    Serial.print(" %\t");
    Serial.print("Temperature: ");
    Serial.print(Temperature);
    Serial.print(" °C\n");
    delay(1000); 
}

