# Hardware & Software Components

This document describes all components required to build and deploy the EcoMeter
system, along with their roles.

## Core Hardware Components

### ESP32 Development Board
Acts as the brain of the system. It reads sensor data, processes it, and sends
information to the cloud over Wi-Fi or mobile hotspot.

### ACS712 Current Sensor
Measures the current flowing through an electrical load. It converts current
into an analog voltage signal that the ESP32 can read.

### Power Supply
A 5V USB adapter or laptop USB port powers the ESP32 continuously.

### Electrical Load
Any device whose electricity usage needs to be monitored, such as a fridge,
TV, music system, conference equipment, or MSME machinery.

## Supporting Hardware

- Jumper wires for connections
- Screw terminals for safe wiring
- Breadboard for prototyping
- Enclosure box for safety and professional installation

## Connectivity Components

- Wi-Fi router OR mobile hotspot
- Internet access for cloud communication

## Software Components

- Arduino IDE for firmware development
- Cloud platform (Firebase / AWS / ThingsBoard)
- Dashboard platform (Web or Mobile)
