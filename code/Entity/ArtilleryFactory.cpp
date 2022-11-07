#include <string>
#include <iostream>
#include "Submarine.h"
#include "FighterJet.h"
#include "Tank.h"
#include "ArtilleryFactory.h"

using namespace std;

	ArtilleryFactory::ArtilleryFactory()// default constuctor 
	{
		
		//cout<<"ArtilleryFactory’s Constructor was Called"<<endl;
		

	} 


	
	ArtilleryFactory::~ArtilleryFactory() //destructor
	{
		//cout<<"ArtilleryFactory’s Destructor was Called"<<endl;
	}

	Vehicle* ArtilleryFactory::createLandVehicle()
	{
		cout<<"Land Artillery created"<<endl;
		cout<<endl;

		Artillery* myArtillery;
		myArtillery = new Tank();
		myVehicle = myArtillery;
		cout<<"Tank created"<<endl;
		cout<<endl;
		return myVehicle;
	}


	Vehicle* ArtilleryFactory::createAirVehicle()
	{
		cout<<"Air Artillery created"<<endl;
		cout<<endl;

		Artillery* myArtillery;
		myArtillery = new FighterJet();
		myVehicle = myArtillery;
		cout<<"FighterJet created"<<endl;
		cout<<endl;
		return myVehicle;
	}

	Vehicle* ArtilleryFactory::createSeaVehicle()
	{
		cout<<"Sea Artillery created"<<endl;
		cout<<endl;

		Artillery* myArtillery;
		myArtillery = new Submarine();
		myVehicle = myArtillery;
		cout<<"Submarine created"<<endl;
		cout<<endl;
		return myVehicle;
	}


	
	
	
	

