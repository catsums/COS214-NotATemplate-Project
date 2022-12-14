#include <string>
#include <iostream>
#include "Submarine.h"

using namespace std;

	Submarine::Submarine():Artillery()// default constuctor 
	{
		
		//cout<<"Submarine’s Constructor was Called"<<endl;
		
		setHp(22);
		setDamage(5);
		setCountry("SA");
		setXpos(0);
		setYpos(0);
		
		types.push_back("Submarine");
		land = false; sea = true;
	}
	Submarine::Submarine(Artillery& v):Artillery(v)// default constuctor 
	{
		types.push_back("Submarine");
		land = false; sea = true;
	} 


	Submarine::Submarine(int h,string c, int d, int x , int y ):Artillery(h,c,d,x,y)// param constuctor 
	{
		setHp(h);
		setDamage(d);
		setCountry(c);
		setXpos(x);
		setYpos(y);

		types.push_back("Submarine");
		land = false; sea = true;
	}
	
	
	Submarine::~Submarine() //destructor
	{
		//cout<<"Submarine’s Destructor was Called"<<endl;
	}

	void Submarine::decreaseFeul(int f)
	{
		int temp = getFeul();

		temp = temp - f;

		setFeul(temp);
	}


	Vehicle* Submarine::clone(){
		return new Submarine(*this);
	}

	
	
	

