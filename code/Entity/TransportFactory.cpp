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


	
	Vehicle* TransportFactory::createLandVehicle()
	{
		cout<<"Land Transport created"<<endl;
		cout<<endl;

		Transport* myTransport;
		myTransport = new CargoTruck();
		myVehicle = myTransport;
		cout<<"CargoTruck created"<<endl;
		cout<<endl;
		return myVehicle;
	}


	Vehicle* TransportFactory::createAirVehicle()
	{
		cout<<"Air Transport created"<<endl;
		cout<<endl;

		Transport* myTransport;
		myTransport = new CargoPlane();
		myVehicle = myTransport;
		cout<<"CargoPlane created"<<endl;
		cout<<endl;
		return myVehicle;
	}

	Vehicle* TransportFactory::createSeaVehicle()
	{
		cout<<"Sea Transport created"<<endl;
		cout<<endl;

		Transport* myTransport;
		myTransport = new CargoShip();
		myVehicle = myTransport;
		cout<<"CargoShip created"<<endl;
		cout<<endl;
		return myVehicle;
	}
	
	
	

