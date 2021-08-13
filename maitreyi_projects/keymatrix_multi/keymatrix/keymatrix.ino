const int rows = 2;
const int cols = 2;
const int keyLen = 4;
const byte keyPins[rows][cols] = {
  {4, 5}, // Cols
  {3, 2}
};

char keys[rows][cols][keyLen] = {
  {{'a', 'b', 'c', 'd'}, {'e', 'f', 'g', 'h'}},
  {{'i', 'j', 'k', 'l'}, {'m', 'n', 'o', 'p'}},
};
unsigned long start_time;
void setup() {
  Serial.begin(9600);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (i < 1) {
        pinMode(keyPins[i][j], OUTPUT);
      } else {
        pinMode(keyPins[i][j], INPUT_PULLUP);
      }
    }
  }
  start_time = millis();
}
char last_key, curr_key, key;
int index = 0;
bool new_key = false, firstKey = true, keypress = false;

int i = 0, k = 0;
int r = -1, c = -1;
bool show_key = false;
char myKey;
void loop() {
  for (i = 0; i < cols; i++) { // loop for cols pin
    // Write 0 for a pins and 1 for reminaing pins
    for (int j = 0; j < cols; j++) {
      if (i == j) {
        digitalWrite(keyPins[0][j], 0);
      } else {
        digitalWrite(keyPins[0][j], 1);
      }
    }
    // check for any pressed key
    for (k = 0; k < rows; k++) {
      if (digitalRead(keyPins[1][k]) == 0) {
        while (digitalRead(keyPins[1][k]) == 0);
        // Dtetect Pressed Key
        if (millis() - start_time < 1000) {
          if (r == k && c == i) {
            index ++;
            if (index == 4) {
              index = 0;
            }
          } else {
            start_time = millis();
            index = 0;
          }
        } else {
          start_time = millis();
          last_key = curr_key;
          index = 0;
        }
        curr_key = keys[k][i][index];
        last_key = curr_key;
        r = k; c = i;
      }
    }
  }

  if (millis() - start_time >= 1000) {
    start_time = millis();
    if (last_key) {
      Serial.print(last_key);
      last_key = '\0';
      curr_key = '\0';
      r = -1; c = -1;
    }
  }
}
