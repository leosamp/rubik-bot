//Instancia e contra os 6 motores do rubik bot
#include <Arduino.h>
#include <Motor/Motor.h>
#include <Motor/ControladorMotores.h>
#include <constantes.h>

using namespace std;
using namespace constantes;

Motor mFrente(PIN_ENABLED_MF);
Motor mDireita(PIN_ENABLED_MD);
Motor mCosta(PIN_ENABLED_MC);
Motor mEsquerda(PIN_ENABLED_ME);
Motor mSuperior(PIN_ENABLED_MS);
Motor mInferior(PIN_ENABLED_MI);

ControladorMotor::ControladorMotor(){    
    pinMode(PIN_DIRECAO, OUTPUT);
    pinMode(PIN_PASSOS, OUTPUT);
}

void ControladorMotor::executarMovimentos(char sequencia){
    switch (sequencia){
        case '1':
            mFrente.girar(horario, 1);
            break;
        case '2':
            mDireita.girar(horario, 1);
            break;
        case '3':
            mCosta.girar(horario, 1);
            break;
        case '4':
            mEsquerda.girar(horario, 1);
            break;   
        case '5':
            mSuperior.girar(horario, 1);
            break;     
        case '6':
            mInferior.girar(horario, 1);
            break;                                             
        default:
            Serial.println("Opcao invalida");
    }
}