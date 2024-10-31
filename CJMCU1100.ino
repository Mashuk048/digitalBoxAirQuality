int analogPin = A0;

void setup() {
  Serial.begin(115200);
  pinMode(analogPin, INPUT);

}

void loop() {
  int sensorValue = analogRead(analogPin);
  float voltage = sensorValue * (5.0/1023.0);
  Serial.print("Analog Value: ");
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
  //Serial.print("\n");
  
  delay(250);

}
