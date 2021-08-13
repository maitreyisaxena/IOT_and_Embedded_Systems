#include<EEPROM.h>
byte pass[6]="EXA314";
void setup() {
  Serial.begin(9600);
  while(!Serial.find('w'));
  Serial.println();
  for (int i=0; i<6;i++){
  EEPROM.write(i,pass[i]);}
  
  while(!Serial.find('r'));
  Serial.println();
  for(int i=0;i<6;i++){
    char ch=EEPROM.read(i);
    Serial.print(ch);
  }Serial.println();

}

void loop() {
  // put your main code here, to run repeatedly:

}
