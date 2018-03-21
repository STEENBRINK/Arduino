int i = String(3).toInt();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  i = i + 5;
  delay(500);

  Serial.println(i);

}
