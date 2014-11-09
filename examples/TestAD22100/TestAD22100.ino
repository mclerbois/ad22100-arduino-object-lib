/*
  Test file of the AD22100 Object lib 
  
  REV 1.0 8/11/2014
  REV 1.01 9/11/2014   change toString pour avoir toujours 5 caractères, ajout d'espace devant le nombre.
  REV 1.02 9/11/2014   change toString, add celsius fahrenheit kelvin conversion
  
  M. Clerbois
*/

#include <ad22100.h>

#define  THERMOMETER_PIN  A0

ad22100 thermometer(THERMOMETER_PIN);

char  celsius[]={176,'C',0}; 
char  fahren[]={176,'F',0};  
char  kelvin[]={"K"};        

void setup() {
  Serial.begin(9600);
}

void loop() {
  int temp=thermometer.read();

  Serial.print("Value read on ADC PIN = ");
  Serial.println(analogRead(THERMOMETER_PIN));
  
  Serial.print("Temp in 1/10 degree = ");
  Serial.println(temp);
  
  thermometer.dotSeparator();
  Serial.print("Temp  = ");
  Serial.print(thermometer.toString()); 
  Serial.print(celsius);
  Serial.println(" with dot separator");
  
  Serial.print("Temp  = ");
  thermometer.fahrenheit();
  Serial.print(thermometer.toString());
  Serial.print(fahren);
  Serial.println(" with dot separator");
  
  Serial.print("Temp  = ");
  thermometer.commaSeparator();
  thermometer.celsius();
  Serial.print(thermometer.toString());
  Serial.print(celsius);
  Serial.println(" with comma separator");
  
  Serial.print("Temp  = ");
  Serial.print( thermometer.toString( thermometer.reads(100,1) ) );
  Serial.print(celsius);
  Serial.println(" Mean of 100 samples delay=1mSec");
  
  Serial.print("Temp  = ");
  thermometer.dotSeparator();
  thermometer.kelvin();
  Serial.print(thermometer.toString());
  Serial.print(kelvin);
  Serial.println(" with dot separator\n");
  
  thermometer.celsius();
  delay(1000);
}