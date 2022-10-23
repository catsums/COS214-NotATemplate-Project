#ifndef SOLDIER_H
#define SOLDIER_H



#include <string>
#include "Citizen.h"

using namespace std; 

class Soldier : public Citizen
{

protected:

<<<<<<< Updated upstream
	
=======
	string status = "NA";
	//string theatre = "NA";
>>>>>>> Stashed changes


public: 

	Soldier();// default constuctor 
	Soldier(int,string,string);// param constuctor 
	
	virtual ~Soldier(); //destructor


	


	
	


		
	
	
};

#endif