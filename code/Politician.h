#ifndef POLITICIAN_H
#define POLITICIAN_H



#include <string>
#include "Citizen.h"

using namespace std; 

class Politician : public Citizen
{

protected:

	
	string influence; // low,moderate,high


public: 

	Politician();// default constuctor 
	Politician(int,string,string);// param constuctor 
	
	virtual ~Politician(); //destructor


	//setter
	
	void setInfluence(string);
	


	//getters
		
	string getInfluence();
	


		
	
	
};

#endif