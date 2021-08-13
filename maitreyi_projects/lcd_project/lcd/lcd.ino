#include<LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7);
byte arrow[8]={B00100,B01110,B11111,B00100,B00100,B00100,B00100,B00100};
void setup() {
  lcd.createChar(7,arrow);
  lcd.begin(20,4);
  //lcd.setCursor(8,1);
  //lcd.write(byte(7));
  

}

void loop() {
  for(int i=15; i>=0;i--){
    lcd.setCursor(i,0);
    lcd.write(byte(7));
    delay(500);
    lcd.clear();
  }

}
