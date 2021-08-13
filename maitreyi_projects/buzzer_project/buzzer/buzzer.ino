const byte buzPin=2;
void setup() {
  // put your setup code here, to run once:
pinMode(buzPin,1);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(buzPin,1);
delay(1000);
digitalWrite(buzPin,0);
delay(1000);
}
