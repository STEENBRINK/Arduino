int kaas[] = {1, 2, 3, 4, 5, 6 , 7};
int kaasplank[][2] = { {2, 3}, {2, 3}, {2, 3} };

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println(sizeof(kaas));
  Serial.println(sizeof(kaasplank));
  Serial.println(sizeof(kaasplank[1]));

  for (int i = 0; i < sizeof(kaasplank);i++){
    Serial.println(kaasplank[i][1]);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
