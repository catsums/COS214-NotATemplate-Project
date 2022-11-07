#include <string>
#include <iostream>
#include "Citizen.h"

using namespace std;

	Citizen::Citizen():Entity()// default constuctor 
	{
		
		//cout<<"Citizen’s Constructor was Called"<<endl;
		setHp(10);
		setDamage(10);
		setCountry("SA");
		setXpos(2);
		setYpos(2);

		types.push_back("Citizen");

		land = true; sea = false;
	} 


	Citizen::Citizen(int h,string c, int d, int x , int y ):Entity()// param constuctor 
	{
		setHp(h);
		setDamage(d);
		setCountry(c);
		setXpos(x);
		setYpos(y);

		types.push_back("Citizen");

		land = true; sea = false;
	}
	
	
	Citizen::~Citizen() //destructor
	{
		//cout<<"Citizen’s Destructor was Called"<<endl;
	}


	

	void Citizen::takeDamage(int d)
	{
		
		hp=hp-d;
		
	}
	

	

	int Citizen::dealDamage()
	{
		return damage;
	}

	
	

	void Citizen::move(int x,int y)
	{
		xpos=x;
		ypos=y;
	}


	
	void Citizen::recieveHp(int h)
	{
		hp= hp + h;
	}

	
	int Citizen::getHeal()
	{
		return 0;
	}
	

