# Circuit Diagram Explanation

## Sensor Connections
- ACS712 VCC → ESP32 3.3V / 5V
- ACS712 GND → ESP32 GND
- ACS712 OUT → ESP32 GPIO 34

## Load Connections
- AC Live wire passes through ACS712
- AC Neutral wire directly to load

## Working
Current passing through the load is sensed by ACS712 and converted to a voltage
signal, which ESP32 reads and processes.
