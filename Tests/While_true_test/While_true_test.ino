int i = 0;
void setup() {
  Serial.begin(9600);

}

void loop() {
  while(true){
    i++;
    Serial.println(i);
  }

}
