# Agriculture_Monitoring_and_irrigation_System

This repository contains the code for an agriculture monitoring and irrigation system using an ESP8266 microcontroller. The system monitors temperature, humidity, soil moisture, and rain detection, and it controls a water pump based on soil moisture levels and rain detection.

## Table of Contents

- [Features](#features)
- [Hardware Requirements](#hardware-requirements)
- [Installation](#installation)
- [Usage](#usage)
- [License](#license)

## Features

- Monitors temperature and humidity using a DHT11 sensor.
- Monitors soil moisture using a soil moisture sensor.
- Detects rain using a rain sensor.
- Controls a water pump based on soil moisture levels and rain detection.
- Sends data to the Blynk platform for remote monitoring.
- Provides notifications via Blynk when it is raining and when the water pump is on or off.

## Hardware Requirements

- ESP8266 microcontroller
- DHT11 temperature and humidity sensor
- Soil moisture sensor
- Rain sensor
- Relay module for water pump control
- Water pump
- Connecting wires and breadboard

## Installation

1. **Clone the repository:**
   ```bash
   git clone https://github.com/JankiMandviya/Agriculture_Monitoring_and_irrigation_System.git
   cd Agriculture_Monitoring_and_irrigation_System
   ```

2. **Open the Arduino IDE:**

3. **Install the required libraries:**
   - Go to `Sketch -> Include Library -> Manage Libraries...`
   - Search for and install `Blynk`, `DHT sensor library`, and `ESP8266WiFi`.

4. **Configure the Blynk settings:**
   - Copy your Blynk Template ID, Device Name, and Auth Token from the Blynk app.
   - Replace the placeholders in the code with your actual values.

5. **Upload the code:**
   - Connect your ESP8266 to your computer.
   - Select the correct board and port in the Arduino IDE.
   - Click the upload button to upload the code to the ESP8266.

## Usage

1. **Setup the sensors and relay module:**
   - Connect the DHT11 sensor to the ESP8266 (Data pin to D2).
   - Connect the soil moisture sensor to the ESP8266 (Analog pin to A0).
   - Connect the rain sensor to the ESP8266 (Output pin to D6).
   - Connect the relay module to the ESP8266 (Control pin to D1) and to the water pump.

2. **Power up the system:**
   - Provide power to the ESP8266 and ensure all sensors are properly connected.

3. **Monitor and control via Blynk:**
   - Open the Blynk app on your mobile device.
   - Monitor the temperature, humidity, soil moisture, and rain status.
   - Receive notifications when it is raining or when the water pump is activated/deactivated.

## License

This project is licensed under the MIT License - see the [LICENSE](https://github.com/JankiMandviya/Agriculture_Monitoring_and_irrigation_System/blob/main/LICENSE) file for details.

---