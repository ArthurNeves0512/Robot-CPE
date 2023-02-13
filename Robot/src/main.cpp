#include<Arduino.h>
#include<Wire.h>
#include<Infravermelho.h>
#include<MotorDC.h>
#include<Move.h>

/*
    Setando os pinos do arduino
*/
#define mEsquerdo_IN1 52
#define mEsquerdo_IN2 53
#define mDireito_IN3 22
#define mDireito_IN4 24
#define PWME 13
#define PWMD 12
#define pin_sensorEsquerdo A8
#define pin_sensorDireito A10


MotorDC motor_esquerdo(mEsquerdo_IN1, mEsquerdo_IN2, PWME);
MotorDC motor_direito(mDireito_IN3, mDireito_IN4, PWMD);
Infravermelho sensor_esquerdo(pin_sensorEsquerdo);
Infravermelho sensor_direito(pin_sensorDireito);

//*******************************//
void setup(){
    pinMode(mEsquerdo_IN1, OUTPUT);
    pinMode(mEsquerdo_IN2, OUTPUT);
    pinMode(mDireito_IN3, OUTPUT);
    pinMode(mDireito_IN4, OUTPUT);
    pinMode(PWME, OUTPUT);
    pinMode(PWMD, OUTPUT);
    pinMode(pin_sensorEsquerdo, INPUT);
    pinMode(pin_sensorDireito,INPUT);
    Serial.begin(9600);
}
void loop(){
    Serial.print("esquerdo: ");
    Serial.println(sensor_esquerdo.lerCor());
    Serial.print("direito: ");
    Serial.println(sensor_direito.lerCor());
    delay(500);
    
    while(sensor_esquerdo.lerCor() > 400 && sensor_direito.lerCor() < 250){
        motor_esquerdo.andar_para_tras(140);
        motor_direito.andar_para_frente(140);
    }
    
    while(sensor_direito.lerCor() > 400 && sensor_esquerdo.lerCor() < 250){
        motor_direito.andar_para_tras(200);
        motor_esquerdo.andar_para_frente(140);
    
    }
    
    motor_direito.andar_para_tras(140);
    motor_esquerdo.andar_para_frente(140);
    
}


