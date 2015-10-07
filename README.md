ad22100-arduino-object-lib
==========================

Librairie arduino permettant d'utiliser une capteur de température AD22100.

    /*
		AD22100 Object lib 
		REV 1.0 8/11/2014
  		REV 1.01 9/11/2014   change toString pour avoir toujours 5 caractères, ajout d'espace devant le nombre.
  		REV 1.02 9/11/2014   change toString, add celsius fahrenheit kelvin conversion
  
		M. Clerbois 2015
	*/

    CLASS	ad22100

    Constructors
		ad22100(int adPin).
		ad22100(int adPin, int tmin, int tmax).
    	
    Functions members
		int read()
		char * toString()
		char * toString(int temp)
		int reads(int nSamples,int delay)
		void commaSeparator() 
		void dotSeparator()

	Inline functions members
		void celsius()
		void fahrenheit()
		void kelvin()
