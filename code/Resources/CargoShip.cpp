#include <string>
#include <iostream>
#include "CargoShip.h"


using namespace std;

	CargoShip::CargoShip()// default constuctor 
	{
		cout<<"CargoShip’s Constructor was Called"<<endl;
	} 

	
	CargoShip::~CargoShip() //destructor
	{
		cout<<"CargoShip’s Destructor was Called"<<endl;
	}

	
	
	void CargoShip::moveVehicle(int)
	{
		//TODO:decrease CargoShip's fuel here 
	}

	
