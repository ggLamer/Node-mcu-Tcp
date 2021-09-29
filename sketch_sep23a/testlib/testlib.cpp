#include <testlib.h>  // подключаем заголовок обязательно

// реализация методов
Motor::Motor(const uint8_t en, const uint8_t dir, const uint8_t pul) { // конструктор
    _en = en;
    _dir = dir;
    _pul = pul;
}
void Motor::begin(){
    pinMode(_en, OUTPUT);
    pinMode(_dir, OUTPUT);
    pinMode(_pul, OUTPUT);
}
void Motor::setspeed(byte speed = 100){
    _speed = speed;
}
void Motor::go(byte direc = 0, byte rps= 2){

    digitalWrite( _en, 0 ); // Разрешаем работу двигателя.
    delayMicroseconds(5); // Выполняем задержку t1 (см. график STEP/DIR).
    digitalWrite( _dir, direc ); // Выбираем направление вращения.

    delayMicroseconds(5);
    for (int i = 0; i < rps * 800; i++) { // Выполняем 1600 проходов цикла (1 оборот = 800 тактов, 2 оборота = 1600).
    digitalWrite( _pul, 1 ); // Устанавливаем на выводе PUL состояние логической «1».
    delayMicroseconds(_speed); // Выполняем задержку t3 (см. график STEP/DIR).
    digitalWrite( _pul, 0 ); // Устанавливаем на выводе PUL состояние логического «0».
    delayMicroseconds(_speed); // Выполняем задержку t4 (см. график STEP/DIR).
    }
}