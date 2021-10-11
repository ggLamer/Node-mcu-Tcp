#include <testlib.h> 


Motor::Motor(uint8_t en, uint8_t dir, uint8_t pul) {
    _en = en;
    _dir = dir;
    _pul = pul;
}
void Motor::begin(){
    Serial.begin(115200);
    pinMode(_en, OUTPUT);
    pinMode(_dir, OUTPUT);
    pinMode(_pul, OUTPUT);
    _workState = true;
    digitalWrite( _en, 1 );
}

void Motor::stop(){_workState = false;}
void Motor::go(float x, int speed = 100){
    
    _x = x;
    _speed = speed;
    if (_x > r){
        dir = _x - r;
        _direc = 0;
        Serial.println(dir);
    }
    if(r > _x){
        dir = r - _x;
        _direc = 1;
        Serial.println(dir);
    }

    digitalWrite( _en, 0 );
    delayMicroseconds(5); 
    digitalWrite( _dir, _direc ); 

    delayMicroseconds(5);
    unsigned long myTime = millis();
    for (int i = 0; i < dir*3000; i++) { 
        if (!_workState){
            digitalWrite( _en, 1 );
            Serial.println("");
            Serial.println("STOP");
            break;
        }
        digitalWrite( _pul, 1 ); 
        delayMicroseconds(_speed); 
        digitalWrite( _pul, 0 ); 
        delayMicroseconds(_speed);
        if(_direc != 0){gr--;}
        else{gr++;}
        r = gr / 3000; 
        Serial.println(r);
    }
    time = millis() - myTime;
    Serial.print("Time: ");Serial.println(time);
    digitalWrite( _en, 1 );
    
}

void Motor::reset(){r = 0; gr = 0; digitalWrite( _en, 1 );}
float Motor::getrps(){return r;}
unsigned long Motor::gettime(){return time;}
float Motor::getspeed(){return r / time * 100;}
