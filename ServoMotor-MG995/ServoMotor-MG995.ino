/* This example Arduino Sketch controls the complete rotation of
 *  SG995 Servo motor by using its PWM and Pulse width modulation technique
 */

#include <Servo.h> // include servo library to use its related functions
#define Servo_PWM 12 // A descriptive name for D6 pin of Arduino to provide PWM signal
Servo MG995_Servo;  // Define an instance of of Servo with the name of "MG995_Servo"
  

void setup() {
  Serial.begin(9600); // Initialize UART with 9600 Baud rate
  MG995_Servo.attach(Servo_PWM);  // Connect D6 of Arduino with PWM signal pin of servo motor
  pinMode(2, INPUT);
}

void accionarServo(){
  MG995_Servo.attach(Servo_PWM);//Always use attach function after detach to re-connect your servo with the board
  Serial.println(" 0 ");//Turn left high speed
  MG995_Servo.write(0);
  delay(1000);

  MG995_Servo.attach(Servo_PWM);//Always use attach function after detach to re-connect your servo with the board
  Serial.println(" 0 ");//Turn left high speed
  MG995_Servo.write(120);
  delay(1000);
  
  MG995_Servo.detach();//Stop. You can use deatch function or use write(x), as x is the middle of 0-180 which is 90, but some lack of precision may change this value
  delay( 1000 );
}

int i = 0;

void loop() {
  Serial.println(digitalRead(2));
  Serial.println(i);
  
  if(digitalRead(2)){
    Serial.println(digitalRead(2));
    accionarServo();
  } else {

  }
  i++;    
}