#include <string>
#include <iostream>
#include "CargoPlane.h"


using namespace std;

	CargoPlane::CargoPlane()// default constuctor 
	{
		cout<<"CargoPlane’s Constructor was Called"<<endl;
	} 

	
	CargoPlane::~CargoPlane() //destructor
	{
		cout<<"CargoPlane’s Destructor was Called"<<endl;
	}

	
	
	void CargoPlane::moveVehicle(int)
	{
		//TODO:decrease CargoPlane's fuel here 
	}

	
