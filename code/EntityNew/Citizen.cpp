#include <string>
#include <iostream>
#include "Citizen.h"

using namespace std;

	Citizen::Citizen()// default constuctor 
	{
		
		cout<<"Citizen’s Constructor was Called"<<endl;

	} 
	
	
	Citizen::~Citizen() //destructor
	{
		cout<<"Citizen’s Destructor was Called"<<endl;
	}


	

	void Citizen::takeDamage(int d)
	{
		int tempdamage = getDamage();
		tempdamage = tempdamage-d;
		setDamage(tempdamage);
	}
	

	

	void Citizen::dealDamage()
	{

	}

	
	

	void Citizen::move(int x,int y)
	{

	}


	
	void Citizen::recieveHp(int h)
	{
		int temphp = getHp();
		temphp = temphp+h;
		setHp(temphp);
	}

	
	
	

