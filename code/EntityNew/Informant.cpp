#include <string>
#include <iostream>
#include "Informant.h"

using namespace std;

	Informant::Informant()// default constuctor 
	{
		
		//cout<<"Informant’s Constructor was Called"<<endl;
		setHp(15);
		setDamage(3);
		setCountry("SA");
		setXpos(0);
		setYpos(0);

	} 


	Informant::Informant(int h,string c, int d, int x , int y ):Citizen(h,c,d,x,y)// param constuctor 
	{
		setHp(h);
		setDamage(d);
		setCountry(c);
		setXpos(x);
		setYpos(y);
	}
	
	
	Informant::~Informant() //destructor
	{
		//cout<<"Informant’s Destructor was Called"<<endl;
	}


	

	
	
	

