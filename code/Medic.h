#ifndef MEDIC_H
#define MEDIC_H



#include <string>
#include "Citizen.h"

using namespace std; 

class Medic : public Citizen
{

protected:

<<<<<<< Updated upstream
=======
	string status;
	//string theatre;
>>>>>>> Stashed changes


public: 

	Medic();// default constuctor 
	Medic(int,string,string);// param constuctor 
	
	virtual ~Medic(); //destructor


<<<<<<< Updated upstream

=======
	
>>>>>>> Stashed changes


		
	
	
};

#endif