# Smart Fan Control System Using ESP32

## About the Project

This project is a simple IoT-based smart fan control system built using an ESP32, an LDR sensor, and a relay module. The system monitors light intensity and automatically switches the fan ON or OFF based on the sensor readings.

The project also uses ThingSpeak to upload and visualize sensor data and fan status. The circuit and code are tested using the Wokwi simulator.

## Features

- Automatic fan control based on light intensity.
- Real-time LDR readings through the Serial Monitor.
- Relay control using the ESP32.
- Cloud monitoring using ThingSpeak.
- Circuit simulation using Wokwi.

## Components

- ESP32
- LDR sensor module
- Relay module
- Wokwi simulator
- ThingSpeak account

## Circuit Connections

| Component | ESP32 Pin |
|---|---|
| LDR AO | GPIO 34 |
| LDR VCC | 3.3V |
| LDR GND | GND |
| Relay IN | GPIO 25 |

## How It Works

The LDR sensor measures the surrounding light intensity and sends an analog signal to the ESP32. The ESP32 compares the sensor reading with a threshold value of 2000.

- When the reading is greater than 2000, the fan turns ON.
- When the reading is 2000 or lower, the fan turns OFF.

The ESP32 also sends the sensor reading and fan status to ThingSpeak for online monitoring.

## ThingSpeak Data

- **Field 1:** LDR reading
- **Field 2:** Fan status (1 = ON, 0 = OFF)

Data is uploaded approximately every 20 seconds.

## Sample Output

```text
LDR: 577 | Fan: OFF
LDR: 3728 | Fan: ON
LDR: 1074 | Fan: OFF
```
ThingSpeak Dashboard

The following charts show the data uploaded by the ESP32 to ThingSpeak.

LDR Sensor Readings

ldr-readings.png

Fan Status

fan-status.png

## Getting Started

1. Open the circuit in Wokwi.
2. Connect the components according to the circuit connections.
3. Configure the Wi-Fi credentials and ThingSpeak Write API key in the code.
4. Start the simulation.
5. Check the Serial Monitor and ThingSpeak dashboard to view the results.

## Technologies Used

- Arduino C++
- ESP32
- Wokwi
- ThingSpeak
- Wi-Fi and HTTP

## Future Improvements

- Add a temperature sensor for temperature-based fan control.
- Implement remote control through a web or mobile interface.
- Test the system using physical hardware.

## Team Members

Nandini Mukherjee

Sijan Husein Seikh

Sourav Sha

Sreya Chatterjee

Sudesh kumar pandey

---


