#include <string>
#include <iostream>
#include "CargoTruck.h"

using namespace std;

	CargoTruck::CargoTruck()// default constuctor 
	{
		
		//cout<<"CargoTruck’s Constructor was Called"<<endl;
		
		setHp(22);
		setDamage(5);
		setCountry("SA");
		setXpos(0);
		setYpos(0);
		

	} 


	CargoTruck::CargoTruck(int h,string c, int d, int x , int y ):Transport(h,c,d,x,y)// param constuctor 
	{
		setHp(h);
		setDamage(d);
		setCountry(c);
		setXpos(x);
		setYpos(y);
	}
	
	
	CargoTruck::~CargoTruck() //destructor
	{
		//cout<<"CargoTruck’s Destructor was Called"<<endl;
	}

	void CargoTruck::decreaseFeul(Transport* a,int f)
	{
		int temp = a->getFeul();

		temp = temp - f;

		a->setFeul(temp);
	}


	

	
	
	

