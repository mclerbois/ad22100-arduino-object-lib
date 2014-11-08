/*
  Header File for the AD22100 Object lib 
  
  REV 1.0 8/11/2014
  
  M. Clerbois
*/

#ifndef _AD22100_H_ 
#define _AD22100_H_

// déclaration d'un type d'objet ad22100

class ad22100 {
  private:
    int temperaturMin;    // valeur de la température minimale en dixième de dégré
    int temperaturMax;    // valeur de la température maximale en dixième de dégré
    int capteurPin;       // n°de la borne du convertisseur analogique digital utilisé
    char _str[6];
	char _decimalSeparator;
  public:
    ad22100(int adPin, int tmin, int tmax);  // constructeur de l'objet, reçoit le numéro de borne et les valeurs min max de la température 
    ad22100(int adPin);                      // autre constructeur on ne définit que la borne utilisés tmin et tmax seront fixé à -611 et 1611 pour une tension d'alimentation de 5V
    int read();                              // méthode réalisant la lecture de la température
	char * toString();
	char * toString(int temp);
	int reads(int nSamples,int delay);
	void commaSeparator() {
		_decimalSeparator=',';
		};
	void dotSeparator(){
		_decimalSeparator='.';
		};
  };

#endif

