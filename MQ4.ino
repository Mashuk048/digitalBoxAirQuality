int gasPin = A0;

void setup() {
  Serial.begin(115200);
}

void loop() {
  int gas = analogRead(gasPin);
  Serial.print("CH4 : ");
  Serial.println(gas);

  delay(1000);

}
