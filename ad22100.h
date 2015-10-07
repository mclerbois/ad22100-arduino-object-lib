/*
  Header File for the AD22100 Object lib 
  REV 1.0 8/11/2014
  REV 1.01 9/11/2014   change toString pour avoir toujours 5 caractères, ajout d'espace devant le nombre.
  REV 1.02 9/11/2014   change toString, add celsius fahrenheit kelvin conversion
  M. Clerbois
*/

#ifndef _AD22100_H_ 
#define _AD22100_H_

// déclaration d'un type d'objet ad22100

class ad22100 {
  private:
    int temperaturMin;    // valeur de la température minimale en dixième de dégré
    int temperaturMax;    // valeur de la température maximale en dixième de dégré
	struct {          // REV 1.02 9/11/2014
		int unit : 2;
		int capteurPin : 14;
		} option ;
  public:
    ad22100(int adPin, int tmin, int tmax);  // constructeur de l'objet, reçoit le numéro de borne et les valeurs min max de la température 
    ad22100(int adPin);                      // autre constructeur on ne définit que la borne utilisés tmin et tmax seront fixé à -611 et 1611 pour une tension d'alimentation de 5V
    int read();                              // méthode réalisant la lecture de la température
	char * toString();
	char * toString(int temp);
	int reads(int nSamples,int delay);
	void commaSeparator();
	void dotSeparator();
	void celsius() { option.unit=0; }; 	// REV 1.02 9/11/2014   
	void fahrenheit() { option.unit=1; };   // REV 1.02 9/11/2014
	void kelvin() { option.unit=2; };       // REV 1.02 9/11/2014
  };

#endif

