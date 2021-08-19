

#include <ESP8266WiFi.h>
#include <Adafruit_INA219.h>

#ifndef STASSID
#define STASSID "Azamat"
#define STAPSK  "R00000000"
#endif

WiFiServer server(9090);

const char* ssid     = STASSID;
const char* password = STAPSK;

const char* host = "";


const uint8_t pin_ENA = D6;
const uint8_t pin_DIR = D7;
const uint8_t pin_PUL = D8;
Adafruit_INA219 ina219;

uint32_t f = 10000;

uint32_t t = 1000000 / f / 2; // Определяем длительность импульсов t3 и пауз t4 в мкс.

String getbusvoltage() {
  float busvoltage = 0;
  busvoltage = ina219.getBusVoltage_V();
  return String(busvoltage);
}
String getpower_mW() {
  float power_mW = 0;
  power_mW = ina219.getPower_mW();
  return String(power_mW);
}
String getcurrent_mA() {
  float current_mA = 0;
  current_mA = ina219.getCurrent_mA();
  return String(current_mA);
}


void setup() {
  Serial.begin(115200);

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
}

void loop() {
  WiFiClient client = server.available();

  if (client) {
    if (client.connected())
    {
      Serial.println("Client Connected");
    }

    while (client.connected()) {
      while (client.available() > 0) {
        char ch = static_cast<char>(client.read());
        Serial.print(ch);
        if ch == "right"
      {
        Serial.println("right");
          digitalWrite( pin_ENA, 0 ); // Разрешаем работу двигателя.
          delayMicroseconds(5); // Выполняем задержку t1 (см. график STEP/DIR).
          digitalWrite( pin_DIR, 0 ); // Выбираем направление вращения.

          delayMicroseconds(5);
          for (int i = 0; i < 800; i++) { // Выполняем 1600 проходов цикла (1 оборот = 800 тактов, 2 оборота = 1600).
            digitalWrite( pin_PUL, 1 ); // Устанавливаем на выводе PUL состояние логической «1».
            delayMicroseconds(t); // Выполняем задержку t3 (см. график STEP/DIR).
            digitalWrite( pin_PUL, 0 ); // Устанавливаем на выводе PUL состояние логического «0».
            delayMicroseconds(t); // Выполняем задержку t4 (см. график STEP/DIR).
          }
        }
        if ch == "left"
      {
        Serial.println("left");
          digitalWrite( pin_ENA, 0 ); // Разрешаем работу двигателя.
          delayMicroseconds(5); // Выполняем задержку t1 (см. график STEP/DIR).
          digitalWrite( pin_DIR, 1 ); // Выбираем направление вращения.

          delayMicroseconds(5);
          for (int i = 0; i < 800; i++) { // Выполняем 1600 проходов цикла (1 оборот = 800 тактов, 2 оборота = 1600).
            digitalWrite( pin_PUL, 1 ); // Устанавливаем на выводе PUL состояние логической «1».
            delayMicroseconds(t); // Выполняем задержку t3 (см. график STEP/DIR).
            digitalWrite( pin_PUL, 0 ); // Устанавливаем на выводе PUL состояние логического «0».
            delayMicroseconds(t); // Выполняем задержку t4 (см. график STEP/DIR).
          }
        }
        if ch == "stop"
      {
        Serial.println("stop");
          digitalWrite( pin_ENA, 1 );
        }

        //INA219

        if ch == "getcurrent_mA"
      {
        Serial.println(getcurrent_mA());
          sendcurrent_mA()
        }
      }
    }
    client.stop();
    Serial.println("Client disconnected");
  }
}

void sendcurrent_mA() {
  WiFiClient client;

  Serial.printf("\n[Connecting to %s ... ", host);
  if (client.connect(host, 80))
  {
    Serial.println("connected");

    Serial.println("[Sending a request]");
    client.print(getcurrent_mA())
    
    client.stop();
    Serial.println("\n[Disconnected]");
  }
  else
  {
    Serial.println("connection failed!]");
    client.stop();
  }
}
