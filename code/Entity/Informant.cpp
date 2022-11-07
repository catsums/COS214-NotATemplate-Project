#include <string>
#include <iostream>
#include "Informant.h"

using namespace std;

	Informant::Informant():Citizen()// default constuctor 
	{
		
		//cout<<"Informant’s Constructor was Called"<<endl;
		setHp(15);
		setDamage(3);
		setCountry("SA");
		setXpos(0);
		setYpos(0);

		types.push_back("Informant");

	} 

	Informant::Informant(Citizen& other):Citizen(other)// default constuctor 
	{
		
		types.push_back("Informant");
	} 


	Informant::Informant(int h,string c, int d, int x , int y ):Citizen(h,c,d,x,y)// param constuctor 
	{
		setHp(h);
		setDamage(d);
		setCountry(c);
		setXpos(x);
		setYpos(y);

		types.push_back("Informant");
	}
	
	
	Informant::~Informant() //destructor
	{
		//cout<<"Informant’s Destructor was Called"<<endl;
	}


	

	
	
	

