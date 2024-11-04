# Environmental Monitoring System with Arduino

## Overview

This project uses an Arduino to monitor environmental parameters such as temperature, humidity, and gas concentrations (CO2 and VOCs). The system utilizes a DHT22 sensor for temperature and humidity readings, and a CCS811 sensor to measure CO2 and total volatile organic compounds (TVOC). Additionally, it reads gas concentration values from an analog sensor.

## Features

- **Temperature and Humidity Monitoring**: Reads temperature and humidity using a DHT22 sensor.
- **Gas Concentration Measurement**: Measures CO2 and TVOC levels using the CCS811 sensor.
- **Analog Gas Sensor**: Reads gas concentration values from an analog pin.
- **Real-time Serial Output**: Outputs all sensor readings to the Serial Monitor for easy monitoring.

## Hardware Requirements

- Arduino board (e.g., Arduino Uno, Nano)
- DHT22 temperature and humidity sensor
- CCS811 air quality sensor
- Analog gas sensor (e.g., CJMCU1100)
- Jumper wires for connections
- Breadboard (optional)

## Wiring Diagram

1. **DHT22 Sensor**:
   - Connect VCC to 3.3V or 5V on the Arduino.
   - Connect GND to Ground.
   - Connect the data pin to digital pin D7 on the Arduino.

2. **CCS811 Sensor**:
   - Connect VCC to 3.3V on the Arduino.
   - Connect GND to Ground.
   - Connect the I2C pins: SDA to A4, SCL to A5 (for Arduino Uno).

3. **Analog Gas Sensor**:
   - Connect the sensor output to analog pin A0 on the Arduino.
   - Connect VCC to 5V and GND to Ground.

## Installation

1. **Set Up the Hardware**:
   - Connect all sensors to the Arduino as per the wiring diagram.

2. **Install Required Libraries**:
   - Ensure you have the following libraries installed in the Arduino IDE:
     - `DHT sensor library` by Adafruit
     - `Adafruit CCS811 Library`

3. **Upload the Code**:
   - Open the Arduino IDE, load the provided code, and upload it to your Arduino board.

## Code Explanation

### Key Functions

- `setup()`: Initializes the serial communication, sets up the sensors, and calibrates the CCS811 sensor.
- `loop()`: Continuously reads temperature, humidity, gas levels, and outputs the readings to the Serial Monitor.

### Sensor Readings

- **DHT22**: Reads temperature and humidity every second.
- **CCS811**: Reads CO2 and TVOC levels, calibrating for temperature.
- **Analog Gas Sensor**: Reads analog voltage and calculates formaldehyde and toluene levels based on the sensor output.

### Calculation of Gas Concentrations

The code uses polynomial equations to calculate the concentrations of formaldehyde and toluene based on the analog voltage readings.

## Usage

1. Once the Arduino is powered and the code is uploaded, open the Serial Monitor in the Arduino IDE.
2. The system will output temperature, humidity, CO2, TVOC, and gas concentrations every second.
3. Monitor the values in real-time through the Serial Monitor.

## Troubleshooting

- If you do not see any readings, ensure all connections are secure and the sensors are powered correctly.
- Check that the correct libraries are installed in the Arduino IDE.
- Ensure that the baud rate in the Serial Monitor matches the one set in the code (115200).

## Contributing

Contributions are welcome! Feel free to submit issues or pull requests for improvements or bug fixes.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
