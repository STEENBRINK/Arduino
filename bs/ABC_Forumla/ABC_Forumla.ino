int A = 15;
int B = 4;
int C = 13; 
int D;
float results[2];

void setup() {
}
D = B*B-4*A*C;
if(D < 0){
  print("D <0! Error!")
}else{
  results = CalculateFormula({A, B, C, D});
  if (results[0] == results[1]){
    print("1 resultaat namelijk: " + String(math.round(results[0], 2)));
  }else{
    print("Je 2 x waarden zijn: ")
    print("x1 = " + String(math.round(results[0], 2)));
    print("x2 = " + String(math.round(results[1], 2)));
  }
}
void loop() {
  delay(1000);
}

float CalculateFormula(int variables[]){
  float x0 = (-variables[1] + math.root(variables[4]))/(2*varables[0]);
  float x1 = (-variables[1] - math.root(variables[4]))/(2*varables[0]);
  return {x0, x1};
}

