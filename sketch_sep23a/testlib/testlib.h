#pragma once
#include <Arduino.h>
// описание класса
class Motor {   // класс Color
public:
 Motor(const uint8_t en , const uint8_t dir , const uint8_t pul) ;
 void begin();
 void setspeed(byte speed);
 void go(byte direc, byte rps);
private:
    const uint8_t _en;
    const uint8_t _dir;
    const uint8_t _pul;

    bool _direc;
    byte _rps;
    byte _speed;
    
};