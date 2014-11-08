/*
  Test file of the AD22100 Object lib 
  
  REV 1.0 8/11/2014
  
  M. Clerbois
*/

#include <ad22100.h>

#define	CelsiusToFahrenheit(C)	(C*18+320)/10

#define  THERMOMETER_PIN  A0

ad22100 thermometer(THERMOMETER_PIN);

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
  Serial.print(thermometer.toString(temp));
  Serial.println(" degree Celsius with dot separator");
  
  Serial.print("Temp  = ");
  Serial.print(thermometer.toString(CelsiusToFahrenheit(temp)));
  Serial.println(" degree Fahrenheit with dot separator");
  
  Serial.print("Temp  = ");
  thermometer.commaSeparator();
  Serial.print(thermometer.toString(temp));
  Serial.println(" degree Celsius with comma separator");
  
  Serial.print("Temp  = ");
  Serial.print( thermometer.toString( thermometer.reads(100,1) ) );
  Serial.println(" degree Celsius with comma separator, Mean of 100 samples delay=1mSec\n");
  
  
  delay(1000);
}
