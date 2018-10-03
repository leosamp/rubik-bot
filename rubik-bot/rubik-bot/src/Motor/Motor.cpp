#include <Arduino.h>
#include <Motor/Motor.h>

Motor::Motor(int pin){
    _pinEnabled = pin;    
    pinMode(_pinEnabled, OUTPUT);
    _setHabilitado(false);
}

void Motor::_definirSentido(Sentido s){
  if (s == horario)
    digitalWrite(PIN_DIRECAO, LOW);
  else
    digitalWrite(PIN_DIRECAO, HIGH);
}

void Motor::_setHabilitado(bool value){
    if (value == true)
        digitalWrite(_pinEnabled, LOW);
    else
        digitalWrite(_pinEnabled, HIGH);
    _habilitado = value;
}

void Motor::girar(Sentido s, int voltas){        
    _definirSentido(s);
    _setHabilitado(true);    
    delay(500);
    //total de passos = 200 por rotacao
    int passos = voltas * 50;
    for (int x = 0; x < passos; x++){
      digitalWrite(PIN_PASSOS, HIGH);
    //   delay(1.25);
      delay(3.25);
      digitalWrite(PIN_PASSOS, LOW);
      delay(3.25);
    //   delay(1.25);
    }
    _setHabilitado(false);
}