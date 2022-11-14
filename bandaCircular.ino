#include <Servo.h>


Servo Servo1;			//Valores del Servo
const int servo=3;

const int motor=10;		//motor de la banda

int rojoLed = 7;		//Rojo
int verdeLed = 8;		//Verde
int azulLed = 9;		//Azul
int leds[3] = {0,0,0};

int pieza = 0;  // indica si se ha detectado una pieza.

const int pbRojo = 4; //Rojo
const int pbVerde = 5; //Verde
const int pbAzul = 6; //Azul

const int eccho = 11;
const int trig = 12;

int i;

// estas variables cuentan la piezas de colores
int r = 0; 
int v = 0; 
int a = 0;

/**
 * setup
 *
 */

void setup(){
	Serial.begin(9600);
  	pinMode( rojoLed, OUTPUT);
	pinMode( verdeLed, OUTPUT);
	pinMode( azulLed, OUTPUT);
	pinMode( motor, OUTPUT);						//motor banda

	pinMode( pbRojo, INPUT);						//Asignar PB
	pinMode( pbVerde, INPUT);
	pinMode( pbAzul, INPUT);
  	
  	// sensor HC-SR04
  	pinMode( eccho, INPUT);
  	pinMode( trig, OUTPUT);
  
	Servo1.attach(3);   						//Servomotor
}

/**
 *  Usa el sensor HC-SR04 
 * 	retorn a la distancia que sensa
 * 
 * */

int obtenerDistancia(){
	digitalWrite(trig,LOW);
  	delayMicroseconds(5);        
  	digitalWrite(trig,HIGH);  
  	delayMicroseconds(10);      
  	digitalWrite(trig,LOW); 
	return pulseIn(eccho,HIGH)/58;
}

/**
 *  TCS 3200 
 * 	detecta el color y cuenta el tipo 
 * de pieza según su color.
 * 
 * **/

void detectarColor(){
	if (digitalRead(pbRojo) == HIGH and digitalRead(pbVerde) == LOW and digitalRead(pbAzul) == LOW){
      	leds[0] = 1; leds[1] = 0; leds[2] = 0;
	   	pieza = 1;
      	r++;
      	return;
    
    } else if(digitalRead(pbRojo) == LOW and digitalRead(pbVerde) == HIGH and digitalRead(pbAzul)== LOW){
		leds[0] = 0; leds[1] = 1; leds[2] = 0; 
	   	pieza = 1;
      	v++;
      	return;
    
    } else if(digitalRead(pbRojo) == LOW and digitalRead(pbVerde) == LOW and digitalRead(pbAzul) == HIGH){
		leds[0] = 0; leds[1] = 0; leds[2] = 1;
		pieza = 1;
      	a++;
      	return;
      	
    } else if(digitalRead(pbRojo) == LOW and digitalRead(pbVerde) == LOW and digitalRead(pbAzul) == LOW){
		leds[0] = 0; leds[1] = 0; leds[2] = 0;
		pieza = 0;
  	}
}

/**
 *  Muestra las piezas
 *
 * */

void mostrarPiezas(){
	// muestra las piezas contadas y etiquetadas.
  	delay( (pieza)? 3000 : 0 );
  	Serial.print(" Rojas : ");
  	Serial.print(r);
  	Serial.print(" Verde : ");
  	Serial.print(v);
  	Serial.print(" Azul  : ");
  	Serial.println(a);
}

/* Enciende el led de acuerdo al color sensado.
 * 
 * */

void encenderLed(){
	digitalWrite( rojoLed,  (leds[0])? HIGH : LOW);
  	digitalWrite( verdeLed, (leds[1])? HIGH : LOW);
  	digitalWrite( azulLed,  (leds[2])? HIGH : LOW);
}


/* 
 * función principal donde todo se integra.
 * 
 * */

void inicio(){
  	analogWrite( motor, (pieza)? 0 : 1200 );	
  	Serial.print(" pieza distancia: ");
  	Serial.println( obtenerDistancia());
  	// mientras haya piezas
  	while( obtenerDistancia() < 10){
      	Serial.println(" Pieza detectada, sensando color ... ");	
      	detectarColor();
  		encenderLed();
      	Servo1.write( (pieza)? 150 : 0  );
      	delay( (pieza)? 150 : 0 );
    }
  	
  
  	// el motor avanza si no hay piezas, se detiene si hay una.
	
	
  	// el servo mueve una pieza, si hay una 
  	 
	delay((pieza)? 2000 : 0);
  	mostrarPiezas();
}


void loop(){
 	inicio();
}
