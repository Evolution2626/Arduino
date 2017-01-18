#define button 1
#define relay 5

int buttonState = 0;

void setup() {
  pinMode (relay,OUTPUT);
  pinMode (button,INPUT);
}

void loop() {
buttonState = digitalRead (button);

if (buttonState == 1) {
  digitalWrite (relay, HIGH);
  delay (4000); //A changer
  digitalWrite (relay, LOW);
  
}else {
  digitalWrite (relay, LOW);
}

}
