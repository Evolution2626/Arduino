
#define RELAY3 8            

int buttonState = 0;

void setup (){    
Serial.begin(9600);
  pinMode(RELAY3, OUTPUT);
}

  void loop(){
   
   digitalWrite(RELAY3,1);
   delay(714);
   digitalWrite(RELAY3,0);
   delay(1000);
}

