#include <ESP8266WiFi.h>
#include <GParser.h>
#include <FIFO.h>
#include <GStypes.h>
#include <GyverPlanner.h>
#include <GyverPlanner2.h>
#include <GyverStepper.h>
#include <StepperCore.h>

#define STASSID "Azamat"
#define STAPSK  "R00000000"

WiFiServer server(9090);

const char* ssid     = STASSID;
const char* password = STAPSK;

GStepper< STEPPER2WIRE> stepper(2300, D8, D7, D6);

void setup() {
  Serial.begin(115200);

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

  //SETTINGS MOTOR
  stepper.setRunMode(FOLLOW_POS);
  stepper.setMaxSpeed(2300);
  stepper.setAcceleration(700);
  stepper.autoPower(true);
  stepper.enable();
}
void loop() {
  logic();
}
/*
0 -- target
1 -- servo
2 -- stop
3 -- reset

"mode; coord(gradus)"
"0; 1000, 100; true(false)" -- target
"1; 90" -- servo
"2" -- stop
*/



void logic(){
  stepper.tick();
  WiFiClient client = server.available();
 if (client) {
    if (client.connected()) Serial.println("Client Connected");
    //stepper.tick();
    while (client.connected()) {
      while (client.available() > 0) {
        char str[1500];
        //String line = client.readString();
        int amount = client.readBytesUntil('.', str, 150);
        Serial.println(amount);   
        //Serial.println(line);
        //line.toCharArray(str, 150);
        /*
        GParser data(str, ';');

        int am = data.split();
        //Serial.println(am);
        
        int ints[5];
        int f = data.parseInts(ints);
        switch  (ints[0]) {
          case 0: Serial.print("Task created "); Serial.println(data.getInt(1)); stepper.setTarget(data.getInt(1), ABSOLUTE); Serial.println(stepper.getTarget()); break;
          case 1: Serial.print("Rotate "); Serial.println(data.getInt(1)); stepper.setTarget(data.getInt(1), ABSOLUTE); break;
          case 2: Serial.println("STOP"); stepper.brake();  break;
          case 3: stepper.reset(); Serial.println(stepper.getTarget()); break;
        }
        */
    }
  }
 }
}

