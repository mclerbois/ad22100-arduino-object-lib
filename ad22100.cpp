/*
  Source File for the AD22100 Object lib 
  
  REV 1.0 8/11/2014
  
  M. Clerbois
*/

#include <stdio.h>
#include <avr/pgmspace.h>
#include <Arduino.h>

#include "ad22100.h"

/* déclaration privée non accessible en dehors de ce fichier */
#define  Tmin  	 -611   // nombre entier représente la température en 1/10 de degré
#define  Tmax  	 1611  // nombre entier représente la température en 1/10 de degré
#define  ADCMIN  0
#define  ADCMAX  1023

/*****************************************************************************************/

// constructeur
ad22100::ad22100(int adPin, int tmin, int tmax) // constructeur de l'objet, reçoit le numéro de borne et les valeurs min max de la température 
{
  temperaturMin=tmin;
  temperaturMax=tmax;
  capteurPin=adPin;
  _decimalSeparator=',';
}
/*****************************************************************************************/

// constructeur
ad22100::ad22100(int adPin) // autre constructeur on ne définit que la borne utilisés tmin et tmax seront fixé à -611 et 1611 pour une tension d'alimentation de 5V
{
  temperaturMin=Tmin;
  temperaturMax=Tmax;
  capteurPin=adPin;
  _decimalSeparator=',';
}
/*****************************************************************************************/

//méthode de lecture
int ad22100::read()  // méthode réalisant la lecture de la température
{
  return map(analogRead(capteurPin), ADCMIN, ADCMAX, temperaturMin, temperaturMax);
}

/*****************************************************************************************/

//méthode de lecture
char *ad22100::toString()  // méthode réalisant la lecture de la température
{
  return toString(read());
}

/*****************************************************************************************/

//méthode de lecture
char *ad22100::toString(int temp)  // méthode réalisant la lecture de la température
{
  char *p=&_str[5];
  *p--=0;
  _str[0]=0;
  if (temp<0) {
	_str[0]='-';
	temp=-temp;
	}
  *p--=temp%10+'0';
  temp=temp/10;
  *p--=_decimalSeparator;
  *p--=temp%10+'0'; //unité
  temp=temp/10;
  while (temp) {
	*p--=temp%10+'0'; //unité
	temp=temp/10;
	}
  if (_str[0])
	*p--='-';
  return ++p;
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
