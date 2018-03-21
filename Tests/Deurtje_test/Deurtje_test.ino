void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  digitalWrite(2, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(2, HIGH);
  Serial.println("HIGH");
  delay(2000);
  digitalWrite(2, LOW);
  Serial.println("LOW");
  delay(6000);
}
