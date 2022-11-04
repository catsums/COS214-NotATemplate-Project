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
#include "TransportFactory.cpp"








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

	Entity* myTank = myFactory5->createLandVehicle();

	

	myTank->infoSummary();
	cout<<endl;

	
	delete myTank;
	delete myFactory5;


	cout<<"Creating an EntityFactory"<<endl;
	cout<<endl;

	EntityFactory * myFactory6 = new ArtilleryFactory();

	cout<<"EntityFactory created"<<endl;
	cout<<endl;

	cout<<"Creating an ArtilleryFactory and FighterJetFactory"<<endl;
	cout<<endl;

	Entity* myJet = myFactory6->createAirVehicle();

	

	myJet->infoSummary();
	cout<<endl;

	
	delete myJet;
	delete myFactory6;



	cout<<"Creating an EntityFactory"<<endl;
	cout<<endl;

	EntityFactory * myFactory7 = new ArtilleryFactory();

	cout<<"EntityFactory created"<<endl;
	cout<<endl;

	cout<<"Creating a ArtilleryFactory and SubmarineFactory"<<endl;
	cout<<endl;

	Entity* mySubmarine = myFactory7->createSeaVehicle();

	

	mySubmarine->infoSummary();
	cout<<endl;

	
	delete mySubmarine;
	delete myFactory7;


	cout<<"Creating an EntityFactory"<<endl;
	cout<<endl;

	EntityFactory * myFactory8 = new TransportFactory();

	cout<<"EntityFactory created"<<endl;
	cout<<endl;

	cout<<"Creating a TransportFactory and TruckFactory"<<endl;
	cout<<endl;

	Entity* myTruck = myFactory8->createLandVehicle();

	

	myTruck->infoSummary();
	cout<<endl;

	
	delete myTruck;
	delete myFactory8;


	cout<<"Creating an EntityFactory"<<endl;
	cout<<endl;

	EntityFactory * myFactory9 = new TransportFactory();

	cout<<"EntityFactory created"<<endl;
	cout<<endl;

	cout<<"Creating a TransportFactory and TruckFactory"<<endl;
	cout<<endl;

	Entity* myPlane = myFactory9->createAirVehicle();

	

	myPlane->infoSummary();
	cout<<endl;

	
	delete myPlane;
	delete myFactory9;


	cout<<"Creating an EntityFactory"<<endl;
	cout<<endl;

	EntityFactory * myFactory10 = new TransportFactory();

	cout<<"EntityFactory created"<<endl;
	cout<<endl;

	cout<<"Creating a TransportFactory and TruckFactory"<<endl;
	cout<<endl;

	Entity* myShip = myFactory10->createSeaVehicle();

	

	myShip->infoSummary();
	cout<<endl;

	
	delete myShip;
	delete myFactory10;
}