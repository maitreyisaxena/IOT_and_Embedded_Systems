#include<LiquidCrystal.h>
#include<Keypad.h>
LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);

const byte ROWS = 4; //four rows
const byte COLS = 3; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};
byte rowPins[ROWS] = {10, 9, 8, 7}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {13, 12, 11}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
const byte buzzer = 2;
void setup() {
  lcd.begin(16, 2);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}
String myPass = "0321";
String localPass = "";
int attempts = 0;
void loop() {
  char key = customKeypad.getKey();
  if (attempts < 4) {
    if (key) {
      if (key >= 48 && key <= 57) { //0-9
        localPass += (String)key;
        lcd.clear();
        for (int i = 0; i < localPass.length(); i++)
          lcd.print('*');
        Serial.println(localPass);
      } else if (key == '*') {
        lcd.clear();
        if (localPass == myPass) {
          lcd.print("Welcome");
          attempts = 0;
        } else {
          lcd.print("Invalid");
          attempts ++;
        }
        localPass = "";
      } else if (key == '#') {
        localPass = "";
        lcd.clear();
      }
    }
    lcd.setCursor(15,0);
    lcd.print(attempts);
  }else{
    lcd.setCursor(0, 0);  
    lcd.print("You are blocked ");
  }
  if (attempts == 3) {
    digitalWrite(buzzer, 1);
    delay(500);
    digitalWrite(buzzer, 0);
    attempts = 4;
  }
}
