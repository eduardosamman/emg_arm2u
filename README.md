 ▄▄       ▄▄  ▄         ▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄         ▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  
# Real-Time EMG Data Plotter

This project facilitates the real-time visualization of Electromyography (EMG) data obtained from an Arduino device. By reading signals directly from the Arduino, users can monitor muscle activity instantaneously, enabling rapid feedback and analysis.

## Instructions

1. **Connect Arduino:** Connect your Arduino board to your computer using a USB cable.

2. **Upload Sketch:** Upload the provided 'MyoWare_Code.ino' sketch to your Arduino board. This sketch enables the Arduino to read EMG signals from the connected sensor.

3. **Run MATLAB Script:** Execute the 'Myoware_Code.m' script in MATLAB. This script establishes communication with the Arduino, reads the incoming EMG data, and plots it in real-time.

## Usage

- Upon running the MATLAB script, a real-time plot of the EMG signal will be displayed. The plot updates continuously as new data is received from the Arduino, providing immediate feedback on muscle activity. Users can adjust visualization parameters or perform additional analysis as needed within the MATLAB environment.

## Requirements

- Arduino board with USB connectivity.
- 'MyoWare_Code.ino' sketch uploaded to the Arduino.
- MATLAB installed on your computer.
- MyoWare Muscle Sensor de SparkFun - SEN-13723.

## Notes

Ensure that the Arduino is properly connected and recognized by your computer before running the MATLAB script. Customize the script or extend its functionality to suit specific research or application requirements.

By following these instructions, users can quickly set up and utilize this project to monitor and analyze EMG data in real-time, facilitating various applications in biomechanics, rehabilitation, and physiological research.
