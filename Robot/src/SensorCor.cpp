#include<SensorCor.h>
#include<Arduino.h>

void SensorCor::init(int s2,int s3, double out,int s1, int s0){
   
} 
SensorCor::~SensorCor(){
    ~this->S2 ;
    ~this->S3 ;
    ~this->s1 ;
    ~this->s0 ;
}
SensorCor::SensorCor(int S2, int S3, double OUT, int s1, int s0){
    /* Explicação PINOS:
        pinos S2, S3 são pinos de seleção para ligar a matriz 
        correspondente de cada cor. pino OUT é a frequência que recebemos com aquela matriz
        que escolhemos.
        
        S2 LOW e S3 LOW == Vermelho
        S2 LOW e S3 HiGH == Azul
        S2 HIGH e S3 HIGH == Verde
    
    */
    this ->S2 = S2;
    this ->S3 = S3;
    this ->OUT = OUT;
    this ->s1 = s1;
    this ->s0 =s0;
    pinMode(this->OUT , INPUT);
    pinMode(this->S2, OUTPUT);
    pinMode(this->S3, OUTPUT);
    pinMode(this->s0, OUTPUT);
    pinMode(this->s1, OUTPUT);
    digitalWrite(this->s0, HIGH);
    digitalWrite(this->s1, LOW);
    int vermelho;
    int azul;
    int verde;

}

char SensorCor::ler_cor(){
    digitalWrite(this->S2, LOW);
    digitalWrite(this->S3, LOW);
    this->vermelho = pulseIn(this->OUT, HIGH);
    digitalWrite(this->S3, HIGH);
    this->azul = pulseIn(this->OUT, HIGH);
    digitalWrite(this->S2, HIGH);
    this->verde = pulseIn(this->OUT, HIGH);
    Serial.print("vermelho: ");
    Serial.println(this->vermelho);
    Serial.print("Azul: ");
    Serial.println(this->azul);
    Serial.print("verde: ");
    Serial.println(this->verde);
    delay(2000);
    
    }
