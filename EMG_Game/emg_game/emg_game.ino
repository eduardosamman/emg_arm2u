#include <Servo.h>
#include <Filters.h>
#include <AH/Timing/MillisMicrosTimer.hpp>
#include <Filters/Butterworth.hpp>

// Define pin numbers for the MyoWare sensors
const int MYOWARE_PIN_1 = A5;
const int MYOWARE_PIN_2 = A0;

// Define pin numbers for the LEDs
const int LED1_PIN_1 = 2;
const int LED2_PIN_1 = 3;
const int LED3_PIN_1 = 4;
const int LED1_PIN_2 = 7;
const int LED2_PIN_2 = 6;
const int LED3_PIN_2 = 5;

// Define pin number for the servo motor
const int SERVO_PIN = 11;

// Sampling frequency
const double f_s = 1000; // Hz

// Cut-off frequency (-3 dB)
const double f_c = 0.02; // Hz

// Sample timer
Timer<micros> timer = std::round(1e6 / f_s);

// Sixth-order Butterworth filter
auto filter1 = butter<4>(f_c);
auto filter2 = butter<4>(f_c);

// Create a servo object
Servo servo_game;

void setup() {
  Serial.begin(9600); // Initialize the serial port

  // Set LED pins as outputs
  pinMode(LED1_PIN_1, OUTPUT);
  pinMode(LED2_PIN_1, OUTPUT);
  pinMode(LED3_PIN_1, OUTPUT);
  pinMode(LED1_PIN_2, OUTPUT);
  pinMode(LED2_PIN_2, OUTPUT);
  pinMode(LED3_PIN_2, OUTPUT);

  // Attach the servo to the corresponding pin
  servo_game.attach(SERVO_PIN);
}

void loop() {
  // Read the muscle signals from the MyoWare sensors
  int sensor1 = analogRead(MYOWARE_PIN_1);
  int sensor2 = analogRead(MYOWARE_PIN_2);

  // Filter the signals
  double filtered1 = filter1(sensor1);
  double filtered2 = filter2(sensor2);

  // Compute the difference between the filtered signals
  double difference = filtered1 - filtered2;

  // Map the difference to a servo angle
  int angle = map(difference, -150, 150, 0, 180);

  // Move the servo to the computed angle
  servo_game.write(angle);

  // Print the sensor values and difference to the serial port
  Serial.print(filtered1);
  Serial.print(",");
  Serial.print(filtered2);
  Serial.print(",");
  Serial.println(difference);

  // Map the sensor values to LED brightness levels
  int brightness_1 = map(filtered1, 0, 1023, 0, 255);
  int brightness_2 = map(filtered2, 0, 1023, 0, 255);

  // Control the LEDs based on the sensor values
  if (brightness_1 < 120) {
    digitalWrite(LED1_PIN_1, HIGH);
    digitalWrite(LED2_PIN_1, LOW);
    digitalWrite(LED3_PIN_1, LOW);
  } else if (brightness_1 < 200) {
    digitalWrite(LED1_PIN_1, LOW);
    digitalWrite(LED2_PIN_1, HIGH);
    digitalWrite(LED3_PIN_1, LOW);
  } else {
    digitalWrite(LED1_PIN_1, LOW);
    digitalWrite(LED2_PIN_1, LOW);
    digitalWrite(LED3_PIN_1, HIGH);
  }
  if (brightness_2 < 120) {
    digitalWrite(LED1_PIN_1, HIGH);
    digitalWrite(LED2_PIN_1, LOW);
    digitalWrite(LED3_PIN_1, LOW);
  } else if (brightness_2 < 200) {
    digitalWrite(LED1_PIN_1, LOW);
    digitalWrite(LED2_PIN_1, HIGH);
    digitalWrite(LED3_PIN_1, LOW);
  } else {
    digitalWrite(LED1_PIN_1, LOW);
    digitalWrite(LED2_PIN_1, LOW);
    digitalWrite(LED3_PIN_1, HIGH);
  }

  delay(10);  // Delay for a specified time
}

// https://github.com/careyi3/MovingAverage