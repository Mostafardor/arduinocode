#include <Wire.h> 
#include "LiquidCrystal_I2C.h"

// My display does not work with 0x3F, I use 0x27 instead.
LiquidCrystal_I2C lcd(0x27,16,2);  

void setup() {
	
  lcd.init();
  lcd.backlight();
  
}


void loop() { 
    int space = 2;
    int sep = 3;
	
    // katakana characters 
    char miki[6] = { 0xCE, 0xBC, 0xB2, 0x20, 0xD0, 0xB7};

    lcd.setCursor(space , 0);
    lcd.print(" Hoshii Miki ");
	
    for(int i = 0; i < 6; ++i){
        lcd.setCursor(space + sep + i , 1);
        lcd.print(miki[i]);      
    }


}