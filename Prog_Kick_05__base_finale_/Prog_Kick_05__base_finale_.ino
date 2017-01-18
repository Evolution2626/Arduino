
#define BUTTON 9
#define RELAY1 7  
#define RELAY2 5 
#define BUTTON2 11               

int buttonState = 0;
int buttonState2 = 0;

void setup (){    
Serial.begin(9600);
  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);
  pinMode(BUTTON, INPUT);
  pinMode(BUTTON2, INPUT);
}

  void loop(){
    
   buttonState = digitalRead(BUTTON);
   buttonState2 = digitalRead(BUTTON2);
   
if (buttonState && buttonState2 == 1){
   digitalWrite(RELAY1,1);
   digitalWrite(RELAY2,1);
}
else {
  digitalWrite(RELAY1, 0);
  digitalWrite(RELAY2, 0);
  }
 }




