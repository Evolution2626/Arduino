#include <DHT.h>



dht DHT;

int RELAY;


// initialisation variables:

double humidite; // Cette variable contient le resultat de la sonde dhumitdite
double temperature;

int toursparjour;

int waithumidite;

int tempspompe;

int humidepompe;

int tempsexecution;

int nombreexecloop;

int waittourne;


void setup() {    

Serial.begin(9600);  
  
  waithumidite = 30; // temps en minutes entre chaque exécution de la sonde d'humidité
  
  tempspompe = 5; // temps d'exécution de la pompe en seconde lorsque trop humide
  
  toursparjour = 8; // Tours par jour SVP mettre un nombre pair
  
  humidepompe = 40; // pourcentage d'humidité pour déclencher la pompe. La pompe se déclencheras quand l'humidité seras moins élevé que se nombre
  
  waittourne = 24; // nombre dheures entre chaque execution des tours
  
  
  RELAY = 4; //Defini la pin que le relais est connecte
  
  pinMode(RELAY1, OUTPUT);
  
  nombreexecloop = 0;
}


void loop() {
  // cette boucle execute les actions et attend le nombre de minutes voulu par la suite
  
  int chk = DHT.read11(7); // lit la sonde de temperature et humidite dans la pin 7
  
  double humid = DHT.humidity;
  double temp = DHT.temperature;
  
  Serial.println("Humidite  " + humid);
  Serial.println("Temperature " + temp);
  
  
  nombreexecloop++;
  
  tempsexecution = 0; //remet le temps d'exécution a zéro
  
  humidite = humid; 
  temperature = temp;
  
  
  
  // active la pompe si besoin
  if humidite < humidepompe {
    
    digitalWrite(RELAY,1);
    
    delay(tempspompe * 1000); // temps d'activation de la pompe
    
    digitalWrite(RELAY,0);
    tempsexecution = tempsexecution + tempspompe; // ajoute le temps d’activation au temps d’execution
  }
  
  // rotation
  if nombreexecloop >= (waittourne * 2) {
    for (int i=0; i >= (toursparjour/2); i++){
      
        
    
     } 
     
     tempsexecution = tempsexecution + 0; // a changer en chronométrant le temps que ça prend
     
     nombreexecloop = 0;
   }
   
   
   delay((waithumidite*60000)+(tempsexecution*1000));
  

}


