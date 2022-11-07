#include <string>
#include <iostream>
#include "Politician.h"

using namespace std;

	Politician::Politician():Citizen()// default constuctor 
	{
		
		//cout<<"Politician’s Constructor was Called"<<endl;
		setHp(22);
		setDamage(5);
		setCountry("SA");
		setXpos(0);
		setYpos(0);

		types.push_back("Politician");
	} 


	Politician::Politician(int h,string c, int d, int x , int y ):Citizen(h,c,d,x,y)// param constuctor 
	{
		setHp(h);
		setDamage(d);
		setCountry(c);
		setXpos(x);
		setYpos(y);

		types.push_back("Politician");
	}
	
	
	Politician::~Politician() //destructor
	{
		//cout<<"Politician’s Destructor was Called"<<endl;
	}


	

	
	
	

