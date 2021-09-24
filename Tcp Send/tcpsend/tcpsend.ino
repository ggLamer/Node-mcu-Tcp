

#include <ESP8266WiFi.h>

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

uint32_t f = 1000;

uint32_t t = 100; // Определяем длительность импульсов t3 и пауз t4 в мкс.


void setup() {
  Serial.begin(115200);
  pinMode( pin_ENA, OUTPUT ); // Конфигурируем вывод Arduino как выход.
  pinMode( pin_DIR, OUTPUT ); // Конфигурируем вывод Arduino как выход.
  pinMode( pin_PUL, OUTPUT ); // Конфигурируем вывод Arduino как +выход.
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
  WiFiClient client = server.available();

  if (client) {
    if (client.connected())
    {
      Serial.println("Client Connected");
    }

    while (client.connected()) {
      while (client.available() > 0) {
        char ch = static_cast<char>(client.read());
       // Serial.print(ch);
        if (ch == 'r')
        {
          Serial.println("right");
          digitalWrite( pin_ENA, 0 ); // Разрешаем работу двигателя.
          delayMicroseconds(5); // Выполняем задержку t1 (см. график STEP/DIR).
          digitalWrite( pin_DIR, 0 ); // Выбираем направление вращения.

          delayMicroseconds(5);
          for (int i = 0; i < 80000; i++) { // Выполняем 1600 проходов цикла (1 оборот = 800 тактов, 2 оборота = 1600).
            digitalWrite( pin_PUL, 1 ); // Устанавливаем на выводе PUL состояние логической «1».
            delayMicroseconds(t); // Выполняем задержку t3 (см. график STEP/DIR).
            digitalWrite( pin_PUL, 0 ); // Устанавливаем на выводе PUL состояние логического «0».
            delayMicroseconds(t); // Выполняем задержку t4 (см. график STEP/DIR).
           
            char ch = static_cast<char>(client.read());
            if (ch == 's')
            {
              Serial.println("stop");
              digitalWrite( pin_ENA, 1 );
              break;
            }
            ch = '0';
          
          }
        }
        if (ch == 'l')
        {
          Serial.println("left");
          digitalWrite( pin_ENA, 0 ); // Разрешаем работу двигателя.
          delayMicroseconds(5); // Выполняем задержку t1 (см. график STEP/DIR).
          digitalWrite( pin_DIR, 1 ); // Выбираем направление вращения.

          delayMicroseconds(5);
          for (int i = 0; i < 80000; i++) {// Выполняем 1600 проходов цикла (1 оборот = 800 тактов, 2 оборота = 1600).
            digitalWrite( pin_PUL, 1 ); // Устанавливаем на выводе PUL состояние логической «1».
            delayMicroseconds(t); // Выполняем задержку t3 (см. график STEP/DIR).
            digitalWrite( pin_PUL, 0 ); // Устанавливаем на выводе PUL состояние логического «0».
            delayMicroseconds(t); // Выполняем задержку t4 (см. график STEP/DIR).
            
            char ch = static_cast<char>(client.read());
            if (ch == 's')
            {
              Serial.println("stop");
              digitalWrite( pin_ENA, 1 );
              break;
            }
            ch = '0';
          
          }
        }
        

      }
    }
    client.stop();
    Serial.println("Client disconnected");
  }
}
