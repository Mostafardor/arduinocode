#include <Wire.h> 
#include "LiquidCrystal_I2C.h"

//Crear el objeto lcd  dirección  0x3F,  y 16 columnas x 2 filas
// en nuestro caso 0x27 fue la dirección.
LiquidCrystal_I2C lcd(0x27,16,2);  //

void setup() {
  // Inicializar el LCD
  lcd.init();
  
  //Encender la luz de fondo.
  lcd.backlight();
  
  // setCursor( x, y) del display
  lcd.setCursor(0, 0);
  lcd.print("Rojo Verde Azul");
}

int rojo = 0;
int verde = 0;
int azul = 0;

void mostrarPiezas(){
    lcd.setCursor(3, 1);
    lcd.print(rojo);  
    lcd.setCursor(7, 1);
    lcd.print(verde);
    lcd.setCursor(12, 1);
    lcd.print(azul);
}

void loop() {
  mostrarPiezas();
  //desplazamos una posición a la izquierda 
  rojo++;
  verde++;
  azul++;
  
  delay(500);
}