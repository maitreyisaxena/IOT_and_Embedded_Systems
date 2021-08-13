#include<LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

const byte menuPin = 2, incrPin = 3, decrPin = 4, alarmPin = 5;
long start_time = 0;


void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
  for (int i = 2; i <= 4; i++) {
    pinMode(i, INPUT_PULLUP);
  }
  pinMode(alarmPin, OUTPUT);
  start_time = millis();
}

uint8_t Time_values[3] = {20, 10, 0}; // hh, mm, ss
uint8_t Alarm_values[3] = {20, 10, 20}; // hh, mm, ss
uint8_t maxLimit[3] = {23, 59, 59}; //  Maximum limit of time
unsigned long alarm_time = 0; // variable to hold the alarm
int alarm_count = 0; // no of count to play alarm
bool alarm = false; // is it alarm time or not
int pointer = 0; // Pointer for alarm time change 0-Currnt time, 1-3 -> Alarm Time set (hour, min, sec)
// millis() function returns elapsed time (in unsigned long format) since start of arduino in milliseconds

void loop() {
  // Set time holding parameters' increament condition
  if ((millis() - start_time) >= 1000) {
    start_time = millis();   // Update start_time
    Time_values[2]++; // Second
    if (Time_values[2] == 60) {
      Time_values[2] = 0;
      Time_values[1]++; // minute
      if (Time_values[1] == 60) {
        Time_values[1] = 0;
        Time_values[0]++; // hour
        if (Time_values[1] == 24) {
          Time_values[1] = 0;
        }
      }
    }
  }



  // Display & Set alarm Parameters
  if (!alarm) {
    // Check for alarm Set button
    if (!digitalRead(menuPin)) {
      while (!digitalRead(menuPin));// Wait untill button release
      pointer += 1;
      if (pointer == 4) {
        pointer = 0;
      }
    }
    if (pointer == 0) {              // Display Time
      lcd.setCursor(0, 0);
      lcd.print("DIGITAL CLOCK  ");
      displayTime(Time_values);
    } else {                       // Set Alarm
      lcd.setCursor(0, 0);
      lcd.print("SET ALARM CLOCK");
      displayTime(Alarm_values);
      incr_decr(&Alarm_values[pointer - 1], pointer);
    }
  } else {
    //  Stop Alarm when MENU button is pressed
    if (!digitalRead(menuPin)) {
      while (!digitalRead(menuPin));
      digitalWrite(alarmPin, 0);
      alarm = 0;
    }
  }
  // Play Alarm for 1 seconds
  if (playAlarmTime()) {
    alarm = true;
    alarm_time = millis();
    digitalWrite(alarmPin, HIGH);
  }
  if (alarm) {
    if ((millis() - alarm_time) > 500) {
      digitalWrite(alarmPin, !digitalRead(alarmPin));
      alarm_time = millis();
      alarm_count++;
      if (alarm_count > 120) { // play for 0.5s * 120 = 1 min
        alarm = 0;
        alarm_count = 0;
        digitalWrite(alarmPin, 0);
      }
    }
  }
}


// Increament & decreament Alarm time parameters
void incr_decr(uint8_t *timeParameter, int point) {
  if (!digitalRead(incrPin)) {
    while (!digitalRead(incrPin));
    *timeParameter = *timeParameter + 1;
    if (*timeParameter > maxLimit[point - 1]) {
      *timeParameter = 0;
    }
  } else if (!digitalRead(decrPin)) {
    while (!digitalRead(decrPin));
    if (*timeParameter > 0) {
      *timeParameter = *timeParameter - 1;
    }
  }
  lcd.cursor();
  switch (point) {
    case 1:
      lcd.setCursor(1, 1);
      break;
    case 2:
      lcd.setCursor(4, 1);
      break;
    case 3:
      lcd.setCursor(7, 1);
      break;
  }
  delay(20);
  lcd.noCursor();
}


// Display time
void displayTime(uint8_t HMS[3]) {
  lcd.setCursor(0, 1);
  for (int i = 0 ; i < 3; i++) {
    if (HMS[i] < 10) {
      lcd.print('0');
    } lcd.print(HMS[i]);
    if (i < 2) {
      lcd.print(':');
    }
  }
}

bool playAlarmTime() {
  bool matched = true;
  for (int i = 0; i < 3; i++) {
    if (Alarm_values[i] != Time_values[i]) {
      matched = false;
      break;
    }
  }
  return matched;
}
