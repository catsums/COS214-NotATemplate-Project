#include <string>
#include <iostream>
#include "FighterJet.h"

using namespace std;

	FighterJet::FighterJet():Artillery()// default constuctor 
	{
		
		//cout<<"FighterJet’s Constructor was Called"<<endl;

		setHp(22);
		setDamage(5);
		setCountry("SA");
		setXpos(0);
		setYpos(0);
		
		types.push_back("FighterJet");
		land = true; sea = true;

	}
	FighterJet::FighterJet(Artillery& v):Artillery(v)// default constuctor 
	{
		types.push_back("FighterJet");
		land = true; sea = true;

	} 


	FighterJet::FighterJet(int h,string c, int d, int x , int y ):Artillery(h,c,d,x,y)// param constuctor 
	{
		setHp(h);
		setDamage(d);
		setCountry(c);
		setXpos(x);
		setYpos(y);

		types.push_back("FighterJet");
		land = true; sea = true;
	}
	
	
	FighterJet::~FighterJet() //destructor
	{
		//cout<<"FighterJet’s Destructor was Called"<<endl;
	}

	void FighterJet::decreaseFeul(int f)
	{
		int temp = getFeul();

		temp = temp - f;

		setFeul(temp);
	}


	Vehicle* FighterJet::clone(){
		return new FighterJet(*this);
	}

	
	
	

