// la posición de los led rojos en un vector 
int rojos[4] = { 2, 5, 8, 11};

void setup() {
  for( int i = 2; i < 13; ++i){
  	pinMode( i, OUTPUT);
  }
}

// funciones de energizardo y desenergizado de los LED
void encender(int luz){
  	digitalWrite( luz, HIGH);
}

void apagar(int luz){
	digitalWrite( luz, LOW);
}

void loop() {
  // prende cada semafor en la secuencia {verde, amarillo, rojo}
  // tomando en cuenta la luz roja de cada posición. 
	for(int i = 0; i < 4; ++i){
  		encender(rojos[i]+2);
      	for(int j = 0; j < 4; ++j){
      		encender((i == j)? rojos[i]+2 : rojos[j] );
      	}
      
  		// esto se supone debe pardadear.
      	delay(1500);
      	apagar(rojos[i]+2);
      	encender(rojos[i]+1);
  
      	delay(1500);
      	
      	for(int j = 0; j < 4; ++j){
      		apagar((i == j)? rojos[i]+1 : rojos[j] );
      	}
    }
}
