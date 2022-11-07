#include <string>
#include <iostream>
#include "Soldier.h"

using namespace std;

	Soldier::Soldier():Citizen()// default constuctor 
	{
		
		//cout<<"Soldier’s Constructor was Called"<<endl;
		setHp(22);
		setDamage(5);
		setCountry("SA");
		setXpos(0);
		setYpos(0);
		
		types.push_back("Soldier");
	} 

	Soldier::Soldier(Citizen& other):Citizen(other)// default constuctor 
	{
		
		types.push_back("Soldier");
	} 


	Soldier::Soldier(int h,string c, int d, int x , int y ):Citizen(h,c,d,x,y)// param constuctor 
	{
		setHp(h);
		setDamage(d);
		setCountry(c);
		setXpos(x);
		setYpos(y);

		types.push_back("Soldier");
	}
	
	
	Soldier::~Soldier() //destructor
	{
		//cout<<"Soldier’s Destructor was Called"<<endl;
	}


	

	
	
	

