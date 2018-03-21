#include <RFID.h>
#include <SPI.h>

//define pins for VMA405
//the amount of items in the array above
#define SS_PIN 10
#define RST_PIN 9

RFID rfid(SS_PIN,RST_PIN);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  //init libraries for reader
  SPI.begin();
  rfid.init();
}

void loop() {
  // put your main code here, to run repeatedly:
  if(!(rfid.isCard())){
        if(rfid.readCardSerial()){
            Serial.println("Card not registered");
        }
  }
}
