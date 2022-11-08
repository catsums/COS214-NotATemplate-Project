#include <string>
#include <iostream>
#include "Vehicle.h"

using namespace std;

	Vehicle::Vehicle():Entity()// default constuctor 
	{
		
		//cout<<"Vehicle’s Constructor was Called"<<endl;
		setHp(10);
		setDamage(10);
		setCountry("SA");
		setXpos(2);
		setYpos(2);

		types.push_back("Vehicle");

	} 

	Vehicle::Vehicle(Vehicle& other):Entity(other)// default constuctor 
	{
		setFeul(other.feul);
		types.push_back("Vehicle");
	}



	Vehicle::Vehicle(int h,string c, int d, int x , int y ):Entity()// param constuctor 
	{
		setHp(h);
		setDamage(d);
		setCountry(c);
		setXpos(x);
		setYpos(y);

		types.push_back("Vehicle");
	}

	
	
	Vehicle::~Vehicle() //destructor
	{
		//cout<<"Vehicle’s Destructor was Called"<<endl;
	}


	

	void Vehicle::takeDamage(int d)
	{
		
		hp=hp-d;
		
	}
	

	

	int Vehicle::dealDamage()
	{
		return damage;
	}

	
	

	void Vehicle::move(int x,int y)
	{
		xpos=x;
		ypos=y;
	}


	
	void Vehicle::recieveHp(int h)
	{
		hp= hp + h;
	}

	void Vehicle::setFeul(int f)
	{
		feul=f;
	}

	int Vehicle::getFeul()
	{
		return feul;
	}

	
	void Vehicle::infoSummary()
	{
		cout<<"*Entity Details*:"<<endl;
		cout<<"Health: " <<hp<<endl;
		cout<<"Country: " <<country<<endl;
		cout<<"Damage: " <<damage<<endl;
		cout<<"Position: (" <<xpos<<","<<ypos<<")"<<endl;
	}
	

