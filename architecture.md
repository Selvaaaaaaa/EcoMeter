# System Architecture

EcoMeter follows a layered architecture to ensure scalability, clarity, and
ease of integration.

## System Architecture & Data Flow

<p align="center">
  <img src="assets/ecometer_architecture.png" alt="EcoMeter Architecture Diagram" width="800">
</p>


## 1. Device Layer
Each location or space contains an EcoMeter device consisting of an ESP32 and
current sensor. Every device has a unique Device ID to distinguish data from
different locations.

## 2. Communication Layer
ESP32 sends data to the cloud using Wi-Fi or mobile hotspot via HTTP or MQTT
protocols.

## 3. Cloud Layer
The cloud stores incoming data in a structured database, organized by:
- User
- Location
- Device
- Timestamp

## 4. AI & Analytics Layer
This layer processes historical data to calculate daily and monthly usage,
compare consumption with limits, and generate predictions.

## 5. Presentation Layer
A web or mobile dashboard displays real-time data, graphs, alerts, and reports.
