
#define BUTTON 9
#define RELAY1 7  
#define RELAY2 5                     

int buttonState = 0;

void setup (){    
Serial.begin(9600);
  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);
  pinMode(BUTTON, INPUT);
}

  void loop(){
    
   buttonState = digitalRead(BUTTON);
   
if (buttonState == 1){
   digitalWrite(RELAY1,1);
   digitalWrite(RELAY2,1);
}
else {
  digitalWrite(RELAY1, 0);
  digitalWrite(RELAY2, 0);
  }
 }

