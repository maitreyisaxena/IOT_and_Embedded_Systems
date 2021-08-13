const byte mPins[2]  = {7, 8};//  uint8_t and byte
void setup() {
  for (int i = 0; i < 2; i++) {
    pinMode(mPins[i], OUTPUT);
  }

}

void loop() {
  // Stop
  digitalWrite(mPins[0], 0);
  digitalWrite(mPins[1], 0);
  delay(1000);
  // 
  digitalWrite(mPins[0], 0);
  digitalWrite(mPins[1], 1);
  delay(1000);
  //
  digitalWrite(mPins[0], 1);
  digitalWrite(mPins[1], 0);
  delay(1000);
  // Stop
  digitalWrite(mPins[0], 1);
  digitalWrite(mPins[1], 1);
  delay(1000);
}
