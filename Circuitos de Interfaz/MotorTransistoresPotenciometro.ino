/*
	@author: Josep Juda
	
	Este programa hace uso de los transistores 
	TIP122
	TIP31C 
	
	Notas: Recordad que no se está usando el PULL_UP interno, 
	hacer el arreglo para el push button.

	Importante: calcular la beta, esta está disponible en los 
	Datasheet, de los respectivos datasheet.
	
	Este programa varia la velocidad del motor con la entrada analoga,
	del potenciometro.

**/

int poten = A0;
int potenciometro;
int base = 10;
int basePWD;
int boton = 2;


void setup() {
  Serial.begin(9600);
  pinMode(poten, INPUT);
  pinMode(base, OUTPUT);
}


void loop() {
  potenciometro = analogRead(A0);
  basePWD = map( potenciometro, 0, 1023, 0, 255);
  
  Serial.print( potenciometro );
  Serial.print(",");
  Serial.println( basePWD );
  delay(500);

  analogWrite(base, basePWD);
}
