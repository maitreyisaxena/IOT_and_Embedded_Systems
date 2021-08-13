#include<LiquidCrystal.h>
LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);
const byte upKey = 2, dwnKey = 3, rstKey = 4;
byte customChar1[] = {B00101, B11111, B10100, B00100, B01010, B10001, B10001, B00000};
byte customChar2[] = {B00100, B10100, B11111, B00101, B01010, B10001, B10001, B00000};
byte customChar3[] = {B11111, B11111, B11111, B11111, B11111, B11111, B11111, B11111};
int timer = 0;
long start_time = 0;
int hurdles[2][16] = {
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};
void setup() {
  Serial.begin(9600);
  pinMode(upKey, INPUT_PULLUP);
  pinMode(dwnKey, INPUT_PULLUP);
  pinMode(rstKey, INPUT_PULLUP);
  lcd.begin(16, 2);
  lcd.createChar(0, customChar1);
  lcd.createChar(1, customChar2);
  lcd.createChar(2, customChar3);
  start_time = millis();
  pinMode(13, 1);
  Serial.println("Hurdle Positions");
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 16; j++) {
      Serial.print(hurdles[i][j]);
      Serial.print(',');
    }
    Serial.println();
  }
  Serial.println();
}

int h_cur = 15;
bool start_game = 0;

unsigned long score = 0;
int pos = -1;
int p, p_last = -1;
bool end_game = 0;
void loop() {
  if (!digitalRead(dwnKey)) {
    pos = 0;
  } else if (!digitalRead(upKey)) {
    pos = 1;
  } else if (!digitalRead(rstKey)) {
    lcd.clear();
    pos = -1;
    lcd.print("START GAME");
    delay(50);
  }

  if (pos != -1) {
    if (millis() - start_time >= 500) {
      score ++;
      start_time = millis();
      // Shift Left values
      for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 15; j++) {
          hurdles[i][j] = hurdles[i][j + 1];
        }
      }
      int p = random(2);
      if (p != p_last) {
        hurdles[0][15] = 0;
        hurdles[1][15] = 0;
      } else {
        hurdles[p][15] = 1;
        hurdles[1 - p][15] = 0;
      }
      p_last = p;
      // print Hurdles
      Serial.println("Hurdle Positions");
      for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 16; j++) {
          Serial.print(hurdles[i][j]);
          Serial.print(',');
          lcd.setCursor(j, i);
          if (hurdles[i][j]) {
            lcd.write(byte(2));
          } else {
            lcd.print(" ");
          }
        }
        Serial.println();
      }
      Serial.println();
      // Hero Position
      if (pos == 0) {
        lcd.setCursor(0, 0);
        if (hurdles[0][0]) {
          lcd.write(byte(2));
          end_game = 1;
        } else {
          lcd.write(byte(0));
        }
      } else if (pos == 1) {
        lcd.setCursor(0, 1);
        if (hurdles[1][0]) {
          lcd.write(byte(2));
          end_game = 1;
        } else {
          lcd.write(byte(1));
        }
      }
      Serial.print("Hero Pos:");
      Serial.println(pos);
      if (end_game) {
        delay(1000);
        lcd.clear();
        lcd.print("GAME OVER");
        lcd.setCursor(0, 1);
        lcd.print("Score-");
        lcd.print(score);
        score = 0;
        pos = -1;
        end_game = 0;
        delay(1000);
        // clear hurdles
        for (int i = 0; i < 2; i++) {
          for (int j = 0; j < 16; j++) {
            hurdles[j][i] = 0;
          }
        }
      }
    }
  }
}
