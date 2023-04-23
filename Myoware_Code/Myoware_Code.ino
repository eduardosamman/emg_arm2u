/**
 * @file       MyoWare_Code.ino
 * @details /* Reads the muscle signal from the MyoWare sensor and sends the data to the serial port.
 * 
 * @authors     Eduardo Saman
 * 
 * @date       2023-23-04
 **/

const int MYOWARE_PIN = A0;  // Pin number of the MyoWare sensor
const int DELAY_TIME  = 10;  // Delay time in milliseconds between sensor readings

void setup() {
  Serial.begin(9600);  // Initialize the serial port
}

/*
Reads the muscle signal from the MyoWare sensor, sends the data to the serial port, and delays for a specified time.
*/
void loop() {
  int sensorValue = readMyoWare(MYOWARE_PIN);  // Read the muscle signal from the MyoWare sensor
  sendToSerial(sensorValue);                   // Send the data to the serial port
  delay(DELAY_TIME);                           // Delay for a specified time
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