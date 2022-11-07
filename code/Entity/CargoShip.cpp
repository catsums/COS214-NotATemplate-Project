#include <string>
#include <iostream>
#include "CargoShip.h"

using namespace std;

	CargoShip::CargoShip():Transport()// default constuctor 
	{
		
		//cout<<"CargoShip’s Constructor was Called"<<endl;
		
		setHp(22);
		setDamage(5);
		setCountry("SA");
		setXpos(0);
		setYpos(0);
		
		types.push_back("CargoShip");
		land = false; sea = true;
	} 


	CargoShip::CargoShip(int h,string c, int d, int x , int y ):Transport(h,c,d,x,y)// param constuctor 
	{
		setHp(h);
		setDamage(d);
		setCountry(c);
		setXpos(x);
		setYpos(y);

		types.push_back("CargoShip");
		land = false; sea = true;
	}
	
	
	CargoShip::~CargoShip() //destructor
	{
		//cout<<"CargoShip’s Destructor was Called"<<endl;
	}

	void CargoShip::decreaseFeul(Transport* a,int f)
	{
		int temp = a->getFeul();

		temp = temp - f;

		a->setFeul(temp);
	}


	

	
	
	

