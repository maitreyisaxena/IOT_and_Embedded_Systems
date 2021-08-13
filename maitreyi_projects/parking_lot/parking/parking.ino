#include<LiquidCrystal.h>
LiquidCrystal lcd(9, 8, 7, 6, 5, 4);
byte s0 = A0, s1 = A1;
int places = 3, count = 0;
void setup() {
  pinMode(s0, 0);
  pinMode(s1, 0);
  lcd.begin(16, 2);
}

void loop() {
  lcd.setCursor(0, 0);
  if (count == 3) {
    lcd.print("PARKING FULL");
  } else {
    lcd.print("Spcace:");
    lcd.print(places - count);
    lcd.print("        ");
  }
  // Entry
  if ((digitalRead(s0) == 1) && (digitalRead(s1) == 0)) {
    while ((digitalRead(s0) == 1) && (digitalRead(s1) == 0));
    if ((digitalRead(s0) == 1) && (digitalRead(s1) == 1)) {
      while ((digitalRead(s0) == 1) && (digitalRead(s1) == 1));
      if ((digitalRead(s0) == 0) && (digitalRead(s1) == 1)) {
        while ((digitalRead(s0) == 0) && (digitalRead(s1) == 1));
        if ((digitalRead(s0) == 0) && (digitalRead(s1) == 0)) {
          if (count < 3) {
            count++;
          }
        }
      }
    }
  }

  // Exit
   if ((digitalRead(s0) == 0) && (digitalRead(s1) == 1)) {
    while ((digitalRead(s0) == 0) && (digitalRead(s1) == 1));
    if ((digitalRead(s0) == 1) && (digitalRead(s1) == 1)) {
      while ((digitalRead(s0) == 1) && (digitalRead(s1) == 1));
      if ((digitalRead(s0) == 1) && (digitalRead(s1) == 0)) {
        while ((digitalRead(s0) == 1) && (digitalRead(s1) == 0));
        if ((digitalRead(s0) == 0) && (digitalRead(s1) == 0)) {
          if (count > 0) {
            count--;
          }
        }
      }
    }
  }
}
