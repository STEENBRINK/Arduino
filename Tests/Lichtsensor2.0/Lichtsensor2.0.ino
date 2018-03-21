#include <Wire.h>  
#include <LiquidCrystal_I2C.h> // Using version 1.2.1
 
// The LCD constructor - address shown is 0x27 - may or may not be correct for yours
// Also based on YWRobot LCM1602 IIC V1
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  
 
int photocellPin = 0;     // the cell and 10K pulldown are connected to a0
int photocellReading;     // the analog reading from the sensor divider
int LEDpin = 11;          // connect Red LED to pin 11 (PWM pin)
int LEDbrightness;        // 
int readings[20];          // the analog reading from the sensor divider in an array
int n = 0;
int max_reading = 0;
int min_reading = 10000;
boolean paper = false;

void setup(void) {
  lcd.begin(16,2); // sixteen characters across - 2 lines
  lcd.backlight();
  
  // We'll send debugging information via the Serial monitor
  //Serial.begin(9600);   
}
 
void loop(void) {
  photocellReading = analogRead(photocellPin);  
  
  Remember(photocellReading);
 
  // LED gets brighter the darker it is at the sensor
  // that means we have to -invert- the reading from 0-1023 back to 1023-0
  photocellReading = 1023 - photocellReading;
  //now we have to map 0-1023 to 0-255 since thats the range analogWrite uses
  LEDbrightness = map(photocellReading, 0, 1023, 0, 255);
  analogWrite(LEDpin, LEDbrightness);
 
  delay(50);
}

void Remember(int reading) {
  //makes sure the array keeps looping
  n++;
  if(n == 20) { n=0; }
  readings[n] = reading;

  if( reading > max_reading){
    max_reading = reading;
    //Serial.println(String(max_reading));
    }
  if( reading < min_reading){
    min_reading = reading;
    //Serial.println(String(min_reading));
    }

  if (max_reading - min_reading >= 50) {
    // switch text
    //Serial.println("Clear lcd");
    lcd.clear();
    if (paper) {
      lcd.setCursor(0,0);
      lcd.print("| Wood Here!  |");
      lcd.setCursor(0,1);
      lcd.print("V Paper Here! V");
      paper = !paper;
    } else {
      lcd.setCursor(0,0);
      lcd.print("| Paper Here! |");
      lcd.setCursor(0,1);
      lcd.print("V Wood Here!  V");
      paper = !paper;
    }
    
    max_reading = 0;
    min_reading = 10000;
    for( int i = 0; i < 20; i++){
      readings[i]=0;
      }
    delay(1000);
    }
    
}

