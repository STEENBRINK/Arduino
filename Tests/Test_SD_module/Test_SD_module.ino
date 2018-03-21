//Henry's Bench
// LC Studio SD Card Initializing Tutorial
//Connections:  MOSI - pin 11, MISO - pin 12, CLK - pin 13, CS - pin 10

 
#include <SD.h>
#include <SPI.h>
 
int cs = 10; // Set Chip Select to pin ten
 
void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    
  }
  Serial.println("Initializing SD card...");
  Serial.println();
  
  pinMode(cs, OUTPUT);
  
  // Documentation says you're supposed to do this
  // even if you don't use it:
  pinMode(SS, OUTPUT);
   
  // see if the card is present and can be initialized:
  if (!SD.begin(cs)) {
    Serial.println("SD did not initiliaze");   
    while (1) ;
  }
  Serial.println("SD initialized.");
}
 

void loop()
{

}
