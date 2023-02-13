//Programa : Controle 2 motores DC usando Ponte H L298N
//Autor : Renato QW
#include<Arduino.h>
#include<Wire.h>
//Definicoes pinos Arduino ligados a entrada da Ponte H
int IN1 = 4;
int IN2 = 5;
int IN3 = 6;
int IN4 = 7;
// Variables
int Power = 80; //Motor velocity between 0 and 255

void setup()
{
//Define os pinos como saida
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
}

void loop()
{
//girar os 2 juntos no sentido horario (anda pra frente)
    digitalWrite(IN1, HIGH);
    //digitalWrite(IN1, Power);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    delay(2000);

// para o robo
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, HIGH);
    delay(500);

// girar os 2 juntos antihorario (anda pra trás)
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    delay(2000);

// para o carro e repete o loop
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, HIGH);
    delay(500);
}
