#include <stdio.h>
#include <math.h>

class Nivel {
  public:
    float distancia;
    int tiempo;
    int trig;
    int eccho;
    int led;
  public:
    Nivel(int trig,int eccho,int led){
      this->trig  = trig;
      this->eccho = eccho; 
      this->led   = led;
    }
    Nivel(int distancia, int tiempo){
      this->distancia = distancia;
      this->tiempo = tiempo;
    }    
    Nivel(){  }
    ~Nivel();
  void calculaDistancia(){
    digitalWrite( trig, HIGH);
    delay( 1 );
    digitalWrite( trig, LOW);
    tiempo = pulseIn( eccho, HIGH);
    distancia = tiempo / 58.2;
  }
};

Nivel *particula = new Nivel( 4, 3, 2);

void setup() {
  Serial.begin(9600);
  pinMode( particula->trig,   OUTPUT);
  pinMode( particula->eccho,  INPUT );
  pinMode( particula->led,    OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  particula->calculaDistancia();

  Serial.println("\tDistancia");
  Serial.println(particula->distancia);
  Serial.println(" cm");
  delay(500);

  if ( particula->distancia < 20 && particula->distancia > 0 ){
    digitalWrite( particula->led, HIGH);
    delay( particula->distancia * 10); 
    
  } else {
    digitalWrite( particula->led, LOW);    
  }
  
  
}
