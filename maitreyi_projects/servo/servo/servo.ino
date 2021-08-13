#include <Servo.h>
Servo servo;
void setup() {
 servo.attach(2);

}

void loop() {
 servo.write(60);
 delay(1000);
 servo.write(30);
 delay(1000);

}
