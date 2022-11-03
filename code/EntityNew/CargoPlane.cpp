#include <string>
#include <iostream>
#include "CargoPlane.h"

using namespace std;

	CargoPlane::CargoPlane()// default constuctor 
	{
		
		//cout<<"CargoPlane’s Constructor was Called"<<endl;
		
		setHp(22);
		setDamage(5);
		setCountry("SA");
		setXpos(0);
		setYpos(0);
		

	} 


	CargoPlane::CargoPlane(int h,string c, int d, int x , int y ):Transport(h,c,d,x,y)// param constuctor 
	{
		setHp(h);
		setDamage(d);
		setCountry(c);
		setXpos(x);
		setYpos(y);
	}
	
	
	CargoPlane::~CargoPlane() //destructor
	{
		//cout<<"CargoPlane’s Destructor was Called"<<endl;
	}

	void CargoPlane::decreaseFeul(Transport* a,int f)
	{
		int temp = a->getFeul();

		temp = temp - f;

		a->setFeul(temp);
	}


	

	
	
	

