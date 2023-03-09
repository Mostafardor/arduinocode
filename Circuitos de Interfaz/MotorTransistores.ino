/*
	@author: Josep Juda
	
	Este programa hace uso de los transistores 
	TIP122
	TIP31C 
	
	Notas: Recordad que no se está usando el PULL_UP interno, 
	hacer el arreglo para el push button.

**/


int potenciometro;
int base = 10;
int boton = 2;


void setup() {
  Serial.begin(9600);
  pinMode(boton, INPUT);
  pinMode(base, OUTPUT);
}


void loop() {

  Serial.print(" Boton -> ");
  Serial.println( digitalRead(boton));
  delay( 1000 );


  if( digitalRead( boton ) == HIGH ){
    digitalWrite( base, LOW);
  } 
  if ( digitalRead( boton ) == LOW ){
    digitalWrite( base, HIGH);
  }
 
}
