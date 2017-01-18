
#define BUTTON 9
#define RELAY1 7  
#define RELAY2 5 
#define BUTTON2 11    
#define RELAY3 3           

int buttonState = 0;
int buttonState2 = 0;
int timer = 0;

void setup (){    
Serial.begin(9600);
  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);
  pinMode(BUTTON, INPUT);
  pinMode(BUTTON2, INPUT);
  pinMode(RELAY3, OUTPUT);
}

  void loop(){
    
   buttonState = digitalRead(BUTTON);
   buttonState2 = digitalRead(BUTTON2);
   

  if(buttonState2 && buttonState== true){
   digitalWrite(RELAY1,1);
   digitalWrite(RELAY2,1);
   if(timer >= 0 && timer != 713){
    digitalWrite (RELAY3,1);
    
   }else if(timer == 713) {
   digitalWrite(RELAY3,0);
   delay (2000);
   timer = 0;
   }
   timer++;
  }
  else {
   digitalWrite(RELAY1, 0);
   digitalWrite(RELAY2, 0);
   digitalWrite(RELAY3, 0);
  }

  delay(1);
 }








