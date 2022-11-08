#include <string>
#include <iostream>
#include "CargoTruck.h"

using namespace std;

	CargoTruck::CargoTruck():Transport()// default constuctor 
	{
		
		//cout<<"CargoTruck’s Constructor was Called"<<endl;
		
		setHp(22);
		setDamage(5);
		setCountry("SA");
		setXpos(0);
		setYpos(0);
		
		types.push_back("CargoTruck");
		land = true; sea = false;
	}
	CargoTruck::CargoTruck(Transport& v):Transport(v)// default constuctor 
	{
		
		types.push_back("CargoTruck");
		land = true; sea = false;
	} 


	CargoTruck::CargoTruck(int h,string c, int d, int x , int y ):Transport(h,c,d,x,y)// param constuctor 
	{
		setHp(h);
		setDamage(d);
		setCountry(c);
		setXpos(x);
		setYpos(y);

		types.push_back("CargoTruck");
		land = true; sea = false;
	}
	
	
	CargoTruck::~CargoTruck() //destructor
	{
		//cout<<"CargoTruck’s Destructor was Called"<<endl;
	}

	void CargoTruck::decreaseFeul(int f)
	{
		int temp = getFeul();

		temp = temp - f;

		setFeul(temp);
	}


	Vehicle* CargoTruck::clone(){
		return new CargoTruck(*this);
	}

	
	
	

