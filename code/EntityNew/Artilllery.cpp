#include <string>
#include <iostream>
#include "Artillery.h"

using namespace std;

	Artillery::Artillery()// default constuctor 
	{
		
		//cout<<"Artillery’s Constructor was Called"<<endl;
		setFeul(100);
		setHp(80);
		setDamage(8);
		setCountry("SA");
		setXpos(0);
		setYpos(0);

	} 


	Artillery::Artillery(int h,string c, int d, int x , int y ):Vehicle(h,c,d,x,y)// param constuctor 
	{
		setFeul(100);
		setHp(h);
		setDamage(d);
		setCountry(c);
		setXpos(x);
		setYpos(y);
	}
	
	
	Artillery::~Artillery() //destructor
	{
		//cout<<"Artillery’s Destructor was Called"<<endl;
	}


	
	int Artillery::getFeul() 
	{
		return feul;
	}
	
	
	void Artillery::setFeul(int f) 
	{
		feul = f;
	}

