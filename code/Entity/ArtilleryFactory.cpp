#include <string>
#include <iostream>
#include "Artillery.h"
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


	
	Vehicle* ArtilleryFactory::createVehicle(string t)
	{
		cout<<"Artillery created"<<endl;
		cout<<endl;


		if(t=="land")
		{
			Artillery* myArtillery;
			myArtillery = new Tank();
			myVehicle = myArtillery;
			cout<<"Tank created"<<endl;
			cout<<endl;
			return myVehicle;
		}
		else if (t=="air")
		{
			Artillery* myArtillery;
			myArtillery = new FighterJet();
			myVehicle = myArtillery;
			cout<<"FighterJet created"<<endl;
			cout<<endl;
			return myVehicle;
		}
		else if (t=="sea")
		{
			Artillery* myArtillery;
			myArtillery = new Submarine();
			myVehicle = myArtillery;
			cout<<"Submarine created"<<endl;
			cout<<endl;
			return myVehicle;
		}
		
		return myVehicle;
	}
	
	
	

