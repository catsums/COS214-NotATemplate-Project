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
#include "SoldierFactory.cpp"
#include "MedicFactory.cpp"
#include "PoliticianFactory.cpp"
#include "InformantFactory.cpp"
#include "VehicleFactory.cpp"
#include "ArtilleryFactory.cpp"
//#include "TankFactory.cpp"








using namespace std; 


int main()
{	
	/*
	Testing the Citizen Factories here
	*/

	// cout<<"This shows the Abstarct Factory Method application"<<endl;

	// cout<<endl;

	// cout<<"Creating an EntityFactory"<<endl;
	// cout<<endl;

	// EntityFactory * myFactory = new SoldierFactory();

	// cout<<"EntityFactory created"<<endl;
	// cout<<endl;

	// cout<<"Creating a CitizenFactory and SoldierFactory"<<endl;
	// cout<<endl;

	// Entity* mySoldier = myFactory->createCitizen();

	

	// mySoldier->infoSummary();
	// cout<<endl;

	
	// delete mySoldier;
	// delete myFactory;


	// cout<<"Creating an EntityFactory"<<endl;
	// cout<<endl;

	// EntityFactory * myFactory2 = new MedicFactory();

	// cout<<"EntityFactory created"<<endl;
	// cout<<endl;

	// cout<<"Creating a CitizenFactory and MedicFactory"<<endl;
	// cout<<endl;

	// Entity* myMedic = myFactory2->createCitizen();

	

	// myMedic->infoSummary();
	// cout<<endl;

	// delete myMedic;
	// delete myFactory2;


	// cout<<"Creating an EntityFactory"<<endl;
	// cout<<endl;

	// EntityFactory * myFactory3 = new InformantFactory();

	// cout<<"EntityFactory created"<<endl;
	// cout<<endl;

	// cout<<"Creating a CitizenFactory and MedicFactory"<<endl;
	// cout<<endl;

	// Entity* myInfo = myFactory3->createCitizen();

	

	// myMedic->infoSummary();
	// cout<<endl;

	// delete myInfo;
	// delete myFactory3;


	// cout<<"Creating an EntityFactory"<<endl;
	// cout<<endl;

	// EntityFactory * myFactory4 = new PoliticianFactory();

	// cout<<"EntityFactory created"<<endl;
	// cout<<endl;

	// cout<<"Creating a CitizenFactory and MedicFactory"<<endl;
	// cout<<endl;

	// Entity* myPoli = myFactory4->createCitizen();

	

	// myMedic->infoSummary();
	// cout<<endl;

	// delete myPoli;
	// delete myFactory4;


	/*
	Testing the Vehicle Factories here
	*/

	
	cout<<"Creating an EntityFactory"<<endl;
	cout<<endl;

	EntityFactory * myFactory5 = new ArtilleryFactory();

	cout<<"EntityFactory created"<<endl;
	cout<<endl;

	cout<<"Creating a ArtilleryFactory and TankFactory"<<endl;
	cout<<endl;

	Entity* myTank = myFactory5->createVehicle("land");

	

	myTank->infoSummary();
	cout<<endl;

	
	delete myTank;
	delete myFactory5;
}