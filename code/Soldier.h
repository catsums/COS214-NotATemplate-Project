#ifndef SOLDIER_H
#define SOLDIER_H



#include <string>
#include "Citizen.h"

using namespace std; 

class Soldier : public Citizen
{

protected:

	string status;
	string theatre;


public: 

	Soldier();// default constuctor 
	Soldier(int,string,string,string);// param constuctor 
	
	virtual ~Soldier(); //destructor


	//setter
	void setStatus(string);

	void setThreatre(string);
	


	//getters
	string getStatus();
	
	string getTheatre();
	


		
	
	
};

#endif