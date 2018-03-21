#define LED 2

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED, LOW);
  delay(random(100, 500));
  Serial.println("uit");
  digitalWrite(LED, HIGH);
  delay(random(100, 500));
  Serial.println("aan");
}

