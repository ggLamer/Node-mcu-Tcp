#pragma once
#include <Arduino.h>

class Motor {  
public:
 Motor(uint8_t en , uint8_t dir , uint8_t pul);
 void begin();
 void go(float x, int speed);
 void reset();
 void stop();

 float getrps();
private:
    uint8_t _en;
    uint8_t _dir;
    uint8_t _pul;

    byte _direc;
    float _x;
    int _speed;
    float gr;
    bool _workState = true;
    float r;
    float dir;
};