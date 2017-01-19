/*
  Serial Call and Response
 Language: Wiring/Arduino

 This program sends an ASCII A (byte of value 65) on startup
 and repeats that until it gets some data in.
 Then it waits for a byte in the serial port, and
 sends three sensor values whenever it gets a byte in.

 Thanks to Greg Shakar and Scott Fitzgerald for the improvements

   The circuit:
 * potentiometers attached to analog inputs 0 and 1
 * pushbutton attached to digital I/O 2

 Created 26 Sept. 2005
 by Tom Igoe
 modified 24 April 2012
 by Tom Igoe and Scott Fitzgerald

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/SerialCallResponse

 */

int firstSensor = 0;    // first analog sensor
int secondSensor = 0;   // second analog sensor
int thirdSensor = 0;    // digital sensor
char inByte = 0;         // incoming serial byte

int mainLed = 10;
int redLed = 8;
int smallButton = 9;
int defaultLed = 13;


void setup() {
  // start serial port at 9600 bps:
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  pinMode(smallButton, INPUT);   // digital sensor is on digital pin 2
  pinMode (defaultLed, OUTPUT);
  pinMode(mainLed, OUTPUT);   // digital light on board (13)
  digitalWrite(mainLed,LOW);
  pinMode(redLed, OUTPUT);   // digital red light
  digitalWrite(redLed,LOW);

  establishContact();  // send a byte to establish contact until receiver responds
}

void loop() {
  // if we get a valid byte, read analog ins:
  if (Serial.available() > 0) 
  {
    // get incoming byte:
    inByte = Serial.read();

    if (inByte == 'B')
       {
    // read  switch, map it to 0 or 255L
    thirdSensor = map(digitalRead(smallButton), 0, 1, 0, 255);
    // send sensor values:
    Serial.write(thirdSensor);
       }

    if (inByte == 'P')
       {
    // read  switch, map it to 0 or 255L
    thirdSensor = map(digitalRead(A0), 0, 1023, 0, 255);
    // send sensor values:
    Serial.write(thirdSensor);
       }

    if (inByte == 'L')
     digitalWrite(mainLed,LOW);

    if (inByte == 'l')
     digitalWrite(mainLed,HIGH);

    if (inByte == 'R')
     digitalWrite(redLed,LOW);

    if (inByte == 'r')
     digitalWrite(redLed,HIGH);

}
}

void establishContact() {
  while (Serial.available() <= 0) {
    Serial.print('A');   // send a capital A
    delay(300);
  }
}

