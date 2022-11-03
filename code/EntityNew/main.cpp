#include <iostream>

#include "Entity.cpp"
#include "Citizen.cpp"
#include "Soldier.cpp"
#include "Medic.cpp"
#include "Informant.cpp"
#include "Politician.cpp"

#include "Vehicle.cpp"
#include "Artillery.cpp"
#include "Tank.cpp"
#include "FighterJet.cpp"
#include "Submarine.cpp"
#include "Transport.cpp"
#include "CargoTruck.cpp"
#include "CargoPlane.cpp"
#include "CargoShip.cpp"

#include "EntityFactory.cpp"
#include "CitizenFactory.cpp"
#include "VehicleFactory.cpp"
#include "SoldierFactory.cpp"






using namespace std; 


int main()
{
	cout<<"This shows the Abstarct Factory Method application"<<endl;

	cout<<endl;

	cout<<"Creating an EntityFactory"<<endl;
	cout<<endl;

	EntityFactory * myFactory = new SoldierFactory();

	cout<<"EntityFactory created"<<endl;
	cout<<endl;

	cout<<"Creating a CitizenFactory and SoldierFactory"<<endl;
	cout<<endl;

	Entity* mySoldier = myFactory->createCitizen();

	

	mySoldier->infoSummary();

	
	


	


	delete mySoldier;
	delete myFactory;

}