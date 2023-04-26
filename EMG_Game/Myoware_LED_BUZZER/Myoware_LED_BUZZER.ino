const int MYOWARE_PIN = A0;   // Pin number of the MyoWare sensor
const int LED1_PIN = 9;       // Pin number of the first LED
const int LED2_PIN = 10;      // Pin number of the second LED
const int LED3_PIN = 11;      // Pin number of the third LED
const int DELAY_TIME = 10;    // Delay time in milliseconds between sensor readings

const int BUZZER_PIN = 6;      // Pin number of the buzzer


void setup() {
  Serial.begin(9600);        // Initialize the serial port
  pinMode(LED1_PIN, OUTPUT); // Set the first LED pin as an output
  pinMode(LED2_PIN, OUTPUT); // Set the second LED pin as an output
  pinMode(LED3_PIN, OUTPUT); // Set the third LED pin as an output
  pinMode(BUZZER_PIN, OUTPUT); // Set buzzer pin as output
}

void loop() {
  int sensorValue = readMyoWare(MYOWARE_PIN);  // Read the muscle signal from the MyoWare sensor
  sendToSerial(sensorValue);                   // Send the data to the serial port
  int brightness = map(sensorValue, 0, 1023, 0, 255);  // Map the sensor value to a brightness level
  if (brightness < 85) {
    digitalWrite(LED1_PIN, HIGH);  // Turn on the first LED if the brightness is low
    digitalWrite(LED2_PIN, LOW);
    digitalWrite(LED3_PIN, LOW);
  } else if (brightness < 170) {
    digitalWrite(LED1_PIN, LOW);
    digitalWrite(LED2_PIN, HIGH);  // Turn on the second LED if the brightness is medium
    digitalWrite(LED3_PIN, LOW);
  } else {
    digitalWrite(LED1_PIN, LOW);
    digitalWrite(LED2_PIN, LOW);
    digitalWrite(LED3_PIN, HIGH);  // Turn on the third LED if the brightness is high
  }
  // Map the sensor value to buzzer frequency
  int buzzerFrequency = map(sensorValue, 0, 1023, 100, 2000);
  int buzzerDutyCycle = map(sensorValue, 0, 1023, 10, 90);
  tone(BUZZER_PIN, buzzerFrequency, buzzerDutyCycle);
  delay(DELAY_TIME);  // Delay for a specified time
}

int readMyoWare(int pin) {
/*
Reads the muscle signal from the MyoWare sensor and returns the sensor value.
*/
  int sensorValue = analogRead(pin);  // Read the analog value from the MyoWare sensor
  return sensorValue;                 // Return the sensor value
}

void sendToSerial(int data) {
/*
 Sends the data to the serial port, and initializes the serial port if it is not already initialized.
*/
  if (Serial) {
    Serial.println(data); // Send the data to the serial port
  } 
  else {
    Serial.begin(9600);   // Initialize the serial port if it is not already initialized
  }
}
