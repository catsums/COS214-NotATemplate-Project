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

	void FighterJet::decreaseFeul(Artillery* a,int f)
	{
		int temp = a->getFeul();

		temp = temp - f;

		a->setFeul(temp);
	}


	

	
	
	

