void setup(){
  Serial.begin(9600);
}

void loop(){
  int k = 4;
  int h = 0;
  for(int g = 0; g <= 2; g++){
    for(int i = 4; i >= h; i--){
      Serial.print(" ");
    }
    for(int i = 0; i <= k; i++){
      Serial.print("*");
    }
    k--;
    h++;
  }
}
