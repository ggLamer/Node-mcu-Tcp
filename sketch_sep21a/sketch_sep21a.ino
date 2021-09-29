#include <GParser.h>

void setup() {
  Serial.begin(115200);
  char str[] = "2,100";

  GParser data(str, ',');
  int am = data.split();
  Serial.println(am);
  int ints[5];
  int f = data.parseInts(ints);
  switch  (ints[0]) {
    case 1: Serial.println(data[1]); break;
    case 2: Serial.println(data[1]); break;
  }
 
}

// 1 = target

void loop() {

  
}
