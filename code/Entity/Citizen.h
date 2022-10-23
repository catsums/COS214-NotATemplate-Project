#ifndef CITIZEN_H
#define CITIZEN_H

#include <string>

using namespace std; 

class Citizen
{

protected:

	int HP; //health of citizen
	string country;//TODO: change to type country once it's been made
	string type; // Soldier,Medic,Informant,Politician
	string theatre; //sea,land,air
	string influence; //high,moderate,low
	string status;
	


public: 

	Citizen();// default constuctor 
	Citizen(int,string);// param constuctor 
	
	virtual ~Citizen(); //destructor

	
	void printInfo();



	void setHP(int);
	void setCountry(string);
	void setType(string);
	void setThreatre(string);
	void setInfluence(string);
	void setStatus(string);


	int getHP();
	string getCountry();
	string getType();
	string getTheatre();
	string getInfluence();
	string getStatus();






		
	
	
};

#endif