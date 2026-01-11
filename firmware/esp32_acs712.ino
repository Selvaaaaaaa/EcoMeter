/****************************************************
 * EcoMeter – Smart Power Usage Tracker for MSMEs
 * Board      : ESP32
 * Sensor     : ACS712
 * Language   : C/C++ (Arduino)
 ****************************************************/

#include <WiFi.h>
#include <HTTPClient.h>

/* ------------ WiFi Credentials ------------ */
const char* ssid = "YOUR_WIFI_OR_HOTSPOT_NAME";
const char* password = "YOUR_WIFI_PASSWORD";

/* ------------ Cloud API (Example) ---------- */
/* You can replace this with Firebase, AWS, etc. */
const char* serverURL = "https://your-cloud-api-url.com/data";

/* ------------ Hardware Configuration ------- */
#define ACS712_PIN 34        // Analog pin connected to ACS712 OUT
#define ADC_RESOLUTION 4095  // ESP32 ADC resolution
#define VREF 3.3             // ESP32 reference voltage

/* ------------ Sensor Calibration ----------- */
float sensitivity = 0.185;  // 0.185 for ACS712-5A
float zeroCurrentVoltage = VREF / 2;

/* ------------ Variables -------------------- */
float currentValue = 0.0;

/* ------------ Setup Function --------------- */
void setup() {
  Serial.begin(115200);
  delay(1000);

  /* WiFi Connection */
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi Connected");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}

/* ------------ Read Current ----------------- */
float readCurrent() {
  int adcValue = analogRead(ACS712_PIN);
  float voltage = (adcValue * VREF) / ADC_RESOLUTION;
  float current = (voltage - zeroCurrentVoltage) / sensitivity;
  return abs(current);
}

/* ------------ Send Data to Cloud ----------- */
void sendDataToCloud(float current) {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(serverURL);
    http.addHeader("Content-Type", "application/json");

    String jsonPayload = "{";
    jsonPayload += "\"device_id\":\"ECOMETER_001\",";
    jsonPayload += "\"current\":" + String(current, 3) + ",";
    jsonPayload += "\"unit\":\"A\"";
    jsonPayload += "}";

    int httpResponseCode = http.POST(jsonPayload);

    Serial.print("HTTP Response: ");
    Serial.println(httpResponseCode);

    http.end();
  } else {
    Serial.println("WiFi Disconnected!");
  }
}

/* ------------ Loop Function ---------------- */
void loop() {
  currentValue = readCurrent();

  Serial.print("Current Usage: ");
  Serial.print(currentValue);
  Serial.println(" A");

  sendDataToCloud(currentValue);

  delay(5000); // Send data every 5 seconds
}
