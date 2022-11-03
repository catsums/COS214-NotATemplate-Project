#include <string>
#include <iostream>
#include "Vehicle.h"

using namespace std;

	Vehicle::Vehicle()// default constuctor 
	{
		
		//cout<<"Vehicle’s Constructor was Called"<<endl;
		setHp(10);
		setDamage(10);
		setCountry("SA");
		setXpos(2);
		setYpos(2);

	} 


	Vehicle::Vehicle(int h,string c, int d, int x , int y )// param constuctor 
	{
		setHp(h);
		setDamage(d);
		setCountry(c);
		setXpos(x);
		setYpos(y);
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

	
	void Vehicle::infoSummary()
	{
		cout<<"*Entity Details*:"<<endl;
		cout<<"Health: " <<hp<<endl;
		cout<<"Country: " <<country<<endl;
		cout<<"Damage: " <<damage<<endl;
		cout<<"Position: (" <<xpos<<","<<ypos<<")"<<endl;
	}
	

