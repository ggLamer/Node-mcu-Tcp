#include <testlib.h>
#include <ESP8266WiFi.h>
//#include <WiFi.h>

#include <GParser.h>

#define STASSID "Azamat"
#define STAPSK  "R00000000"

WiFiServer server(9090);
Motor mymotor(27,26,25);
const char* ssid     = STASSID;
const char* password = STAPSK;


void setup() {
  mymotor.begin();
  pinMode(02, OUTPUT);
  pinMode(14, OUTPUT);
  //WIFI settings
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
/*
"0; 100; dir" -- for coords
"1; 90" -- for incline
"2" -- stop motors

*/
void loop() {
  WiFiClient client = server.available();
  if (client) {
    if (client.connected()) Serial.println("Client Connected");
    //stepper.tick();
    while (client.connected()) {
      while (client.available() > 0) {
        char str[150];
        //String line = client.readString();
        int amount = client.readBytes(str, 150);
      
        int data[20]; //буфер интоoв
        int count = 0; //счётчик интов
        char* offset = str;
        while (true){
          data[count++] = atoi(offset);
          offset = strchr(offset, ';');
          if (offset) offset++;
          else break;
        }
        switch(data[0]){
          case 0: Serial.print("Task created ");Serial.println(data[1]); mymotor.go(data[1], data[2]); Serial.println(mymotor.getrps()); client.print(mymotor.getrps()); break;
          case 10: Serial.println("RESET"); mymotor.reset(); client.print(mymotor.getrps()); break;
          case 1: Serial.println("Rotate "); Serial.println(data[1]);digitalWrite(2, data[1]);
          case 2: Serial.println("2 Rotate "); Serial.println(data[1]);digitalWrite(14, data[1]);
        }
        
      }
    }
  }
}
