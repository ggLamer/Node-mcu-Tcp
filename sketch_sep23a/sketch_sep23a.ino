#include <testlib.h>
#include <ESP8266WiFi.h>
#define STASSID "Azamat"
#define STAPSK  "R00000000"

WiFiServer server(9090);

const char* ssid     = STASSID;
const char* password = STAPSK;

Motor mymotor(12,13,15);
void setup() {
  
  // put your setup code here, to run once:
  mymotor.begin();
  mymotor.setspeed(100);
  
  

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop() {
  
}
