const byte mPins[2]  = {7, 8};//  uint8_t and byte
void setup() {
  for (int i = 0; i < 2; i++) {
    pinMode(mPins[i], OUTPUT);
  }
pinMode(3,1);
}


void loop() {
analogWrite(3,50);
delay(1000);

analogWrite(3,225);
delay(1000);



}
