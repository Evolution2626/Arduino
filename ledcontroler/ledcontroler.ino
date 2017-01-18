#include <IRremote.h>

IRsend irsend;
const int buttonPin = 2; // the number of the pushbutton pin
 const int ledPin = 3;
int buttonState = 0; // variable for reading the pushbutton status
void setup()
{
pinMode(ledPin, OUTPUT);
// initialize the pushbutton pin as an input:
Serial.begin(9600);
}

void loop() {
	
irsend.sendNEC(0xFF1AE5, 32);

	delay(5000); 

irsend.sendNEC(0xFF9A65, 32);

  delay(5000); 

 irsend.sendNEC(0xFFA25D, 32);

 delay(5000); 
 
 irsend.sendNEC(0xFF38C7, 32);

 delay(5000); 
 
 irsend.sendNEC(0xFF18E7, 32);

 delay(5000); 

 irsend.sendNEC(0xFF12ED, 32);

 delay(5000); 
}
