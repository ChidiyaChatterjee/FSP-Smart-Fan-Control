#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "Wokwi-GUEST";
const char* password = "";
const char* apiKey = "API_KEY";

#define LDR_PIN 34
#define RELAY_PIN 25

void setup() {
  Serial.begin(115200);

  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);

  WiFi.begin(ssid, password, 6);

  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi Connected!");
}

void loop() {
  int light = analogRead(LDR_PIN);

  // Fan ON when the LDR reading is above 2000
  bool fan = (light > 2000);

  digitalWrite(RELAY_PIN, fan ? HIGH : LOW);

  Serial.print("LDR: ");
  Serial.print(light);
  Serial.print(" | Fan: ");
  Serial.println(fan ? "ON" : "OFF");

  // Upload data to ThingSpeak
  if (WiFi.status() == WL_CONNECTED) {
    WiFiClient client;
    HTTPClient http;

    String url = "http://api.thingspeak.com/update?api_key=";
    url += apiKey;
    url += "&field1=" + String(light);
    url += "&field2=" + String(fan ? 1 : 0);

    http.begin(client, url);
    int response = http.GET();

    if (response > 0) {
      String result = http.getString();
      Serial.print("ThingSpeak response: ");
      Serial.println(result);
    } else {
      Serial.println("Upload failed");
    }

    http.end();
  }

  delay(20000);
}