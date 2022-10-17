#ifndef INFORMANT_H
#define INFORMANT_H



#include <string>
#include "Citizen.h"

using namespace std; 

class Informant : public Citizen
{

protected:

	string status;
	


public: 

	Informant();// default constuctor 
	Informant(int,string,string);// param constuctor 
	
	virtual ~Informant(); //destructor


	//setter
	void setStatus(string);

	
	


	//getters
	string getStatus();
	
	
	


		
	
	
};

#endif