# System Workloads

This document explains the responsibilities of each part of the EcoMeter system.

## ESP32 Workload
- Read analog values from current sensor
- Convert raw values into current (Amps)
- Attach timestamp and device ID
- Send data to cloud at regular intervals

## Cloud Backend Workload
- Receive data from multiple devices
- Validate and store data securely
- Organize data by location and time

## AI & Analytics Workload
- Aggregate daily usage
- Calculate monthly electricity usage
- Compare current usage with predefined limits
- Predict end-of-month consumption
- Identify abnormal usage patterns

## Dashboard Workload
- Fetch cloud data
- Display live values and graphs
- Show alerts and monthly summaries
