#include <string>
#include <iostream>
#include "Transport.h"
#include "TransportFactory.h"

using namespace std;

	TransportFactory::TransportFactory()// default constuctor 
	{
		
		//cout<<"TransportFactory’s Constructor was Called"<<endl;
		

	} 


	
	TransportFactory::~TransportFactory() //destructor
	{
		//cout<<"TransportFactory’s Destructor was Called"<<endl;
	}


	
	Vehicle* TransportFactory::createVehicle(string t)
	{
		cout<<"Transport created"<<endl;
		cout<<endl;


		if(t=="land")
		{
			Transport* myTransport;
			myTransport = new CargoTruck();
			myVehicle = myTransport;
			cout<<"CargoTruck created"<<endl;
			cout<<endl;
			return myVehicle;
		}
		else if (t=="air")
		{
			Transport* myTransport;
			myTransport = new CargoPlane();
			myVehicle = myTransport;
			cout<<"CargoPlane created"<<endl;
			cout<<endl;
			return myVehicle;
		}
		else if (t=="sea")
		{
			Transport* myTransport;
			myTransport = new CargoShip();
			myVehicle = myTransport;
			cout<<"CargoShip created"<<endl;
			cout<<endl;
			return myVehicle;
		}
		
		return myVehicle;
	}
	
	
	

