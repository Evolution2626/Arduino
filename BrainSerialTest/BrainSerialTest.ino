// Arduino Brain Library - Brain Serial Test

// Description: Grabs brain data from the serial RX pin and sends CSV out over the TX pin (Half duplex.)
// More info: https://github.com/kitschpatrol/Arduino-Brain-Library
// Author: Eric Mika, 2010 revised in 2014

#include <Brain.h>

// Set up the brain parser, pass it the hardware serial object you want to listen on.
Brain brain(Serial);
int Memory = 0;     
        String Giver = brain.readCSV(); 
        int x = 0;
        double Keeper = 0;
        int y = 0;        

        char Receiver = Giver.charAt(x);
        double Signalstrenght = 0;
        double Attention = 0;
        double Meditation = 0;
        double Delta = 0;
        double Theta = 0;
        double LowAlpha = 0;
        double HighAlpha = 0;
        double LowBeta = 0;
        double HighBeta = 0;
        double LowGamma = 0;
        double HighGamma = 0;

    int finSignalstenght = 0;
    int finAttention = 0;
    int finMeditation = 0;
    int finDelta = 0;
    int finTheta = 0;
    int finAttention = 0;
    int finLowAlpha = 0;
    int finHighAlpha = 0;
    int finLowBeta = 0;
    int finHighBeta = 0;
    int finLowGamma = 0;
    int finHighGamma = 0;

void setup() {
    // Start the hardware serial.
    Serial.begin(9600);
}

void loop() {
    // Expect packets about once per second.
    // The .readCSV() function returns a string (well, char*) listing the most recent brain data, in the following format:
    // "signal strength, attention, meditation, delta, theta, low alpha, high alpha, low beta, high beta, low gamma, high gamma"    
    if (brain.update()) {
       finSignalstenght = Giver.indexOf(',');
       String StringSignalstrenght = Giver.substring(0, finSignalstenght);
      Serial.println(StringSignalstrenght);
       finAttention = Giver.indexOf(',', finSignalstenght + 1);
       String StringAttention = Giver.substring(finSignalstenght + 1, finAttention);
      Serial.println(StringAttention);
    }  
}


