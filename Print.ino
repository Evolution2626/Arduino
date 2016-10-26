void setup(){
  Serial.begin(9600);
}

void loop(){
  for(int i = 4; i >= 0; i--){
    Serial.print(" ");
  }
  for(int i = 0; i <= 4; i++){
    Serial.print("*");
  }
}
