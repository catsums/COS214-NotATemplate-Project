#include <string>
#include <iostream>
#include "Submarine.h"


using namespace std;

	Submarine::Submarine()// default constuctor 
	{
		cout<<"Submarine’s Constructor was Called"<<endl;
	} 

	
	Submarine::~Submarine() //destructor
	{
		cout<<"Submarine’s Destructor was Called"<<endl;
	}

	
	
	void Submarine::moveVehicle(int)
	{
		//TODO:decrease Submarine's fuel here 
	}

	
