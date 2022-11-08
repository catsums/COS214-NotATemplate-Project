#include <string>
#include <iostream>
#include "Tank.h"

using namespace std;

	Tank::Tank():Artillery()// default constuctor 
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
	Tank::Tank(Artillery& v):Artillery(v)// copy constuctor 
	{
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

	void Tank::decreaseFeul(int f)
	{
		int temp = getFeul();

		temp = temp - f;

		setFeul(temp);
	}


	Vehicle* Tank::clone(){
		return new Tank(*this);
	}

	
	
	

