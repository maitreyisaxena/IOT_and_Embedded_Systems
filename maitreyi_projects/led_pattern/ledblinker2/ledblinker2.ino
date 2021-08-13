void setup() {
  for (int i=5;i<=7;i++){
    pinMode(i,1);
  }

}

void loop() {
for(int i=5; i<=7;i++){
  digitalWrite(i,1);
  delay(500);
  digitalWrite(i,0);
  
}

}
