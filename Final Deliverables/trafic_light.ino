#include <WiFi.h>
#include <HTTPClient.h>

#include <ArduinoJson.h>

String serverName = "http://159.122.183.221:31764/light";

#define RED 2
#define YELLOW 15
#define GREEN 4

DynamicJsonDocument doc(1024);

void setup() {
  Serial.begin(115200);
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
  wificonnect();
}

int dr = 0, dy = 0, dg = 0;

void loop() {

   HTTPClient http;
  
  if(WiFi.status()== WL_CONNECTED){
    http.begin(serverName.c_str());
    int httpResponseCode = http.GET();
    if (httpResponseCode>0) {
        String payload = http.getString();
        Serial.println(payload);
        deserializeJson(doc, payload);
        dr = doc["r"]; dy = doc["y"]; dg = doc["g"];
        dr = dr * 1000;
        dy = dy * 1000;
        dg = dg * 1000;
    }
  }
  Serial.println(dr);
  Serial.println(dy);
  Serial.println(dg);
  digitalWrite(RED, HIGH);
  delay(dr);
  digitalWrite(RED, LOW);

  digitalWrite(YELLOW, HIGH);
  delay(dy);
  digitalWrite(YELLOW, LOW);

  digitalWrite(GREEN, HIGH);
  delay(dg);
  digitalWrite(GREEN, LOW);
}

void wificonnect() 
{
  Serial.println();
  Serial.print("Connecting to ");

  WiFi.begin("Wokwi-GUEST", "", 6);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}
