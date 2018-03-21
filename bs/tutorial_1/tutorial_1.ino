int red = 5;
int yellow = 3;
int green = 7;

void setup() {
  // put your setup code here, to run once:
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(yellow, LOW);
  digitalWrite(green, LOW);
  digitalWrite(red, HIGH);
  delay(5000);
  digitalWrite(red, LOW);
  digitalWrite(green, HIGH);
  delay(2000);
  digitalWrite(green, LOW);
  digitalWrite(yellow, HIGH);
  delay(500);
  digitalWrite(yellow, LOW);
}
