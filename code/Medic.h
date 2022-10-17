#ifndef MEDIC_H
#define MEDIC_H



#include <string>
#include "Citizen.h"

using namespace std; 

class Medic : public Citizen
{

protected:

	string status;
	string theatre;


public: 

	Medic();// default constuctor 
	Medic(int,string,string,string);// param constuctor 
	
	virtual ~Medic(); //destructor


	//setter
	void setStatus(string);

	void setThreatre(string);
	


	//getters
	string getStatus();
	
	string getTheatre();
	


		
	
	
};

#endif