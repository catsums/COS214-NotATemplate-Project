#ifndef CITIZEN_H
#define CITIZEN_H

#include <string>

using namespace std; 

class Citizen
{

protected:

	int HP; //health of citizen
	string country; //TODO: change to type country once it's been made
	


public: 

	Citizen();// default constuctor 
	Citizen(int,string);// param constuctor 
	
	virtual ~Citizen(); //destructor


	void setHP(int);
	void setCountry(string);


	int getHP();
	string getCountry();



		
	
	
};

#endif