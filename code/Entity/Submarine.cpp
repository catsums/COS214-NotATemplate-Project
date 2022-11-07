#include <string>
#include <iostream>
#include "Submarine.h"

using namespace std;

	Submarine::Submarine()// default constuctor 
	{
		
		//cout<<"Submarine’s Constructor was Called"<<endl;
		
		setHp(22);
		setDamage(5);
		setCountry("SA");
		setXpos(0);
		setYpos(0);
		

	} 


	Submarine::Submarine(int h,string c, int d, int x , int y ):Artillery(h,c,d,x,y)// param constuctor 
	{
		setHp(h);
		setDamage(d);
		setCountry(c);
		setXpos(x);
		setYpos(y);
	}
	
	
	Submarine::~Submarine() //destructor
	{
		//cout<<"Submarine’s Destructor was Called"<<endl;
	}

	void Submarine::decreaseFeul(Artillery* a,int f)
	{
		int temp = a->getFeul();

		temp = temp - f;

		a->setFeul(temp);
	}


	

	
	
	
