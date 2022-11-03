#include <string>
#include <iostream>
#include "Artillery.h"

using namespace std;

	Artillery::Artillery()// default constuctor 
	{
		
		//cout<<"Artillery’s Constructor was Called"<<endl;
		setHp(22);
		setDamage(5);
		setCountry("SA");
		setXpos(0);
		setYpos(0);

	} 


	Artillery::Artillery(int h,string c, int d, int x , int y ):Vehicle(h,c,d,x,y)// param constuctor 
	{
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


	

	
	
	

