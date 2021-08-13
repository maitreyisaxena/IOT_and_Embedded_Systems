void setup() {
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  

}


void loop() {
analogWrite(7,HIGH);
analogWrite(8,LOW);
digitalWrite(7,1);
digitalWrite(8,0);
delay(1000);

analogWrite(7,LOW);
analogWrite(8,HIGH);
digitalWrite(7,0);
digitalWrite(8,1);
delay(1000);

}
