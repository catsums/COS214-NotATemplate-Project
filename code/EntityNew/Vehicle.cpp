#include <string>
#include <iostream>
#include "Vehicle.h"

using namespace std;

	Vehicle::Vehicle()// default constuctor 
	{
		
		cout<<"Vehicle’s Constructor was Called"<<endl;
		setHp(10);
		setDamage(10);
		setCountry("SA");
		setXpos(2);
		setYpos(2);

	} 
	
	
	Vehicle::~Vehicle() //destructor
	{
		cout<<"Vehicle’s Destructor was Called"<<endl;
	}


	

	void Vehicle::takeDamage(int d)
	{
		
		hp=hp-d;
		
	}
	

	

	void Vehicle::dealDamage()
	{
		
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

	
	
	

