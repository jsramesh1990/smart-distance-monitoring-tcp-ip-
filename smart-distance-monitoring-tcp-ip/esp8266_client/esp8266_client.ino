#include <ESP8266WiFi.h>

const char* ssid = "YOUR_WIFI";           // find the network and collect all details then prceed
const char* password = "YOUR_PASSWORD";

const char* serverIP = "192.168.1.100";
const int serverPort = 8080;

WiFiClient client;

#define TRIG D1
#define ECHO D2

long duration;
int distance;

void setup() {
  Serial.begin(115200);

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  WiFi.begin(ssid, password);
  Serial.print("Connecting");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConnected!");
}

void loop() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  duration = pulseIn(ECHO, HIGH);
  distance = duration * 0.034 / 2;

  Serial.println(distance);

  if (!client.connected()) {
    client.connect(serverIP, serverPort);
  }

  client.println(distance);

  delay(1000);
}

