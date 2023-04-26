#include <Servo.h>

const int MYOWARE_PIN = A0;  // Pin number of the MyoWare sensor
const int DELAY_TIME = 10;   // Delay time in milliseconds between sensor readings
const int SERVO_PIN = 2;     // Pin number of the servo motor

Servo servo;                 // Create a servo object

void setup() {
  Serial.begin(9600);       // Initialize the serial port
  servo.attach(SERVO_PIN);  // Attach the servo to the corresponding pin
}

void loop() {
  int sensorValue = readMyoWare(MYOWARE_PIN);  // Read the muscle signal from the MyoWare sensor
  moveServo(sensorValue);                      // Move the servo based on the muscle contraction
  delay(DELAY_TIME);                           // Delay for a specified time
}

int readMyoWare(int pin) {
  int sensorValue = analogRead(pin);  // Read the analog value from the MyoWare sensor
  return sensorValue;                 // Return the sensor value
}

void moveServo(int sensorValue) {
  int angle = map(sensorValue, 0, 1023, 0, 300);  // Map the sensor value to an angle between 0 and 180 degrees
  if (sensorValue > 20) {                        // If the muscle is contracted (threshold value can be adjusted)
    servo.write(angle*2);                           // Move the servo to the mapped angle
  } else {
    servo.write(0);                               // Move the servo back to initial position
  }
}
