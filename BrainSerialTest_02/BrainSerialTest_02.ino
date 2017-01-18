// Arduino Brain Library - Brain Serial Test

// Description: Grabs brain data from the serial RX pin and sends CSV out over the TX pin (Half duplex.)
// More info: https://github.com/kitschpatrol/Arduino-Brain-Library
// Author: Eric Mika, 2010 revised in 2014

#include <Brain.h>

// Set up the brain parser, pass it the hardware serial object you want to listen on.
Brain brain(Serial);    

String Giver = brain.readCSV(); 
char Memory;

long Signalstrenght = 0;
long Attention = 0;
long Meditation = 0;
long Delta = 0;
long Theta = 0;
long LowAlpha = 0;
long HighAlpha = 0;
long LowBeta = 0;
long HighBeta = 0;
long LowGamma = 0;
long HighGamma = 0;
        
int finSignalstenght = 0;
int finAttention = 0;
int finMeditation = 0;
int finDelta = 0;
int finTheta = 0;
int finLowAlpha = 0;
int finHighAlpha = 0;
int finLowBeta = 0;
int finHighBeta = 0;
int finLowGamma = 0;
int finHighGamma = 0;

String StringSignalstrenght;
String StringAttention;
String StringMeditation;
String StringDelta;
String StringTheta;
String StringLowAlpha;
String StringHighAlpha;
String StringLowBeta;
String StringHighBeta;
String StringLowGamma ;
String StringHighGamma;

const int led = A1;

void setup() {
    // Start the hardware serial.
    Serial.begin(9600);
}

void loop() {
    // Expect packets about once per second.
    // The .readCSV() function returns a string (well, char*) listing the most recent brain data, in the following format:
    // "signal strength, attention, meditation, delta, theta, low alpha, high alpha, low beta, high beta, low gamma, high gamma"    
    if (brain.update()) {

      Giver = brain.readCSV();

      //signalstrenght
       finSignalstenght = Giver.indexOf(',');
       StringSignalstrenght = Giver.substring(0, finSignalstenght); 

       Signalstrenght = StringSignalstrenght.toInt();
        
      //attention
       finAttention = Giver.indexOf(',', finSignalstenght + 1);
       StringAttention = Giver.substring(finSignalstenght + 1, finAttention);

       Attention = StringAttention.toInt();

        analogWrite(led, (Attention * 10));

      //meditation
       finMeditation = Giver.indexOf(',', finAttention + 1);
       StringMeditation = Giver.substring(finAttention + 1, finMeditation); 

       Meditation = StringMeditation.toInt();
       
        //delta
       finDelta = Giver.indexOf(',', finMeditation + 1);
       StringDelta = Giver.substring(finMeditation + 1, finDelta);
      
       Delta = StringDelta.toInt(); 
       
        //thete
       finTheta = Giver.indexOf(',', finDelta + 1);
       StringTheta = Giver.substring(finDelta + 1, finTheta); 

       Theta = StringTheta.toInt();
       
        //LowAlpha
       finLowAlpha = Giver.indexOf(',', finTheta + 1);
       StringLowAlpha = Giver.substring(finTheta + 1, finLowAlpha); 

       LowAlpha = StringLowAlpha.toInt();
       
        //HighAlpha 
       finHighAlpha  = Giver.indexOf(',', finLowAlpha + 1);
       StringHighAlpha = Giver.substring(finLowAlpha + 1, finHighAlpha); 

       HighAlpha = StringHighAlpha.toInt();
       
        //LowBeta 
       finLowBeta  = Giver.indexOf(',', finHighAlpha + 1);
       StringLowBeta  = Giver.substring(finHighAlpha + 1, finLowBeta); 

       LowBeta = StringLowBeta.toInt();
       
        //HighBeta 
       finHighBeta  = Giver.indexOf(',', finLowBeta + 1);
       StringHighBeta  = Giver.substring(finLowBeta + 1, finHighBeta); 

       HighBeta = StringHighBeta.toInt(); 
       
        //LowGamma 
       finLowGamma  = Giver.indexOf(',', finHighBeta + 1);
       StringLowGamma  = Giver.substring(finHighBeta + 1, finLowGamma); 

       LowGamma = StringLowGamma.toInt();
       
        //HighGamma 
       finHighGamma  = Giver.indexOf(',', finLowGamma + 1);
       StringHighGamma  = Giver.substring(finLowGamma + 1, finHighGamma); 

       HighGamma = StringHighGamma.toInt();

       Serial.print(Signalstrenght);
       Serial.print(",");
       Serial.print(Attention );
       Serial.print(",");
       Serial.print(Meditation );
       Serial.print(",");
       Serial.print(Delta );
       Serial.print(",");
       Serial.print(Theta );
       Serial.print(",");
       Serial.print(LowAlpha );
       Serial.print(",");
       Serial.print(HighAlpha );
       Serial.print(",");
       Serial.print(LowBeta );
       Serial.print(",");
       Serial.print(HighBeta );
       Serial.print(",");
       Serial.print(LowGamma );
       Serial.print(",");
       Serial.println(HighGamma );
  }
}  


