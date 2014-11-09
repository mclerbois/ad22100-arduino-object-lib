/*
  Source File for the AD22100 Object lib 
  
  REV 1.0  8/11/2014
  REV 1.01 9/11/2014   change toString pour avoir toujours 5 caractères, ajout d'espace devant le nombre.
  REV 1.02 9/11/2014   change toString, add celsius fahrenheit kelvin conversion
  
  M. Clerbois
*/

#include <stdio.h>
#include <avr/pgmspace.h>
#include <Arduino.h>

#include "ad22100.h"

/* déclaration privée non accessible en dehors de ce fichier */
#define  Tmin  	 -611   // nombre entier représente la température en 1/10 de degré
#define  Tmax  	 1611   // nombre entier représente la température en 1/10 de degré
#define  ADCMIN  0
#define  ADCMAX  1023

/*****************************************************************************************/

// constructeur
ad22100::ad22100(int adPin, int tmin, int tmax) // constructeur de l'objet, reçoit le numéro de borne et les valeurs min max de la température 
{
  temperaturMin=tmin;
  temperaturMax=tmax;
  option.capteurPin=adPin;
  option.unit=0;
}
/*****************************************************************************************/

// constructeur
ad22100::ad22100(int adPin) // autre constructeur on ne définit que la borne utilisés tmin et tmax seront fixé à -611 et 1611 pour une tension d'alimentation de 5V
{
  temperaturMin=Tmin;
  temperaturMax=Tmax;
  option.capteurPin=adPin;
  option.unit=0;
}
/*****************************************************************************************/

//méthode de lecture
int ad22100::read()  // méthode réalisant la lecture de la température
{
  int mesure=map(analogRead(option.capteurPin), ADCMIN, ADCMAX, temperaturMin, temperaturMax);
  switch (option.unit) { // REV 1.02 9/11/2014
	case 1: //fahrenheit
		mesure=(mesure*18+3200)/10;
		break;
	case 2: // kelvin
		mesure= mesure+2732;
		break;
	}
   return mesure;
}

/*****************************************************************************************/

//méthode de lecture
char * ad22100::toString()  // méthode réalisant la lecture de la température
{
  return toString(read());
}

/*****************************************************************************************/
static  char _ad22100_str[6]="  0,0";

/*****************************************************************************************/

void ad22100::commaSeparator() { // REV 1.02 9/11/2014
		_ad22100_str[3]=',';
		};
/*****************************************************************************************/

void ad22100::dotSeparator(){ // REV 1.02 9/11/2014
		_ad22100_str[3]='.';
		};
		
/*****************************************************************************************/

//méthode de lecture
// REV 1.02 9/11/2014
char *ad22100::toString(int temp)  // méthode réalisant la lecture de la température
{
  char *p=&_ad22100_str[1];
  if (temp<0) {
	_ad22100_str[0]='-';
	_ad22100_str[1]='-';
	temp=-temp;
	}
  else {
	_ad22100_str[0]=' ';
	_ad22100_str[1]=' ';
	}
	
  _ad22100_str[4]=temp%10+'0';
  temp=temp/10;
  
  _ad22100_str[2]=temp%10+'0'; //unité
  temp=temp/10;
  
  while (temp) {
	*p--=temp%10+'0'; //dizaine centaine
	temp=temp/10;
	}
  if ( _ad22100_str[1]=='-' )
	_ad22100_str[0]=' ';
  return _ad22100_str;
}

/*****************************************************************************************/

//méthode de lecture
int ad22100::reads(int nSamples,int delay)  // méthode réalisant la lecture de la température
{
  long mesures=0L;
  int n=constrain(nSamples,1,100);
  nSamples=n;
  delay=constrain(delay,1,10);
  while(n--) {
	mesures+=read();
	}
  return mesures / nSamples;
}
