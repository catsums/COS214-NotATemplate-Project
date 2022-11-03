#ifndef Transport_H
#define Transport_H

#include <string>
#include "Vehicle.h"

using namespace std; 

class Transport: public Vehicle
{

private:

	int feul;


public: 

	Transport();// default constuctor 
	Transport(int,string,int,int,int);// param constuctor 
	
	virtual ~Transport(); //destructor

	
	virtual void decreaseFeul(Transport*,int)=0;

	
	
	//getters

	int getFeul();


	//setter 

	void setFeul(int);
	
	
	
};

#endif