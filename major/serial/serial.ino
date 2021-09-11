#include<SoftwareSerial.h>
SoftwareSerial ser(12, 13);
const byte led = 9;
void setup() {
  ser.begin(9600);
  Serial.begin(9600);
  pinMode(led, 1);
}

void loop() {

  if (Serial.available()) {
    char ch = Serial.read();
    ser.println(ch);
    if (ch == '1'){
      digitalWrite(led, 1);
    }else if (ch == '0'){
      digitalWrite(led, 0);
    }
  }
}
