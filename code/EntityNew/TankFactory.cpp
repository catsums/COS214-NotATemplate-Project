#include <string>
#include <iostream>
#include "Tank.h"
#include "TankFactory.h"

using namespace std;

	TankFactory::TankFactory()// default constuctor 
	{
		
		//cout<<"TankFactory’s Constructor was Called"<<endl;
		

	} 


	
	TankFactory::~TankFactory() //destructor
	{
		//cout<<"TankFactory’s Destructor was Called"<<endl;
	}


	
	Vehicle* TankFactory::createVehicle()
	{
		myVehicle = new Tank();

		
		cout<<"Tank created"<<endl;
		cout<<endl;
		return myVehicle;
	}
	
	
	

