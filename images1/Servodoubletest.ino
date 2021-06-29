 
#include <Servo.h>

Servo servo_1; // servo controller (multiple can exist)
Servo servo_2;
int servo_pin = 5; // PWM pin for servo control
int servo_pin2 = 9;
int pos = 0;    // servo starting position

void setup() {
  servo_1.attach(servo_pin); // start servo control
  servo_2.attach(servo_pin2); // start servo control
  Serial.begin(9600); // start serial monitor
  servo_1.write(pos); // move servo to 0 degrees
  servo_2.write(pos);
  Serial.println("Positioned at 0 Degrees");
  Serial.println("Input Desired Angle and Press Enter");
}

void loop() {
  while (Serial.available()){
    String in_char = Serial.readStringUntil('\n'); // read until the newline
    Serial.print("Moving to: ");
    Serial.print(in_char);
    Serial.println(" Degrees");
    servo_1.write(in_char.toInt()); // convert angle and write servo
    servo_2.write(in_char.toInt());
    delay(in_char.toFloat()*(10.0/6.0)); // delay for maximum speed
  }
}
