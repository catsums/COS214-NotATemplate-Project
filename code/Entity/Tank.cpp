#include <string>
#include <iostream>
#include "Tank.h"

using namespace std;

	Tank::Tank()// default constuctor 
	{
		
		//cout<<"Tank’s Constructor was Called"<<endl;
		
		setHp(22);
		setDamage(5);
		setCountry("SA");
		setXpos(0);
		setYpos(0);
		
		land = true; sea = false;
		types.push_back("Tank");
	} 


	Tank::Tank(int h,string c, int d, int x , int y ):Artillery(h,c,d,x,y)// param constuctor 
	{
		setHp(h);
		setDamage(d);
		setCountry(c);
		setXpos(x);
		setYpos(y);

		land = true; sea = false;
		types.push_back("Tank");
	}
	
	
	Tank::~Tank() //destructor
	{
		//cout<<"Tank’s Destructor was Called"<<endl;
	}

	void Tank::decreaseFeul(Artillery* a,int f)
	{
		int temp = a->getFeul();

		temp = temp - f;

		a->setFeul(temp);
	}


	

	
	
	

