#include <string>
#include <iostream>
#include "Medic.h"

using namespace std;

	Medic::Medic():Citizen()// default constuctor 
	{
		
		//cout<<"Medic’s Constructor was Called"<<endl;
		setHeal(4);
		setHp(18);
		setDamage(2);
		setCountry("SA");
		setXpos(0);
		setYpos(0);

		types.push_back("Medic");

	} 

	Medic::Medic(Citizen& other):Citizen(other)// default constuctor 
	{
		types.push_back("Medic");
	}



	Medic::Medic(int h,string c, int d, int x , int y ):Citizen(h,c,d,x,y)// param constuctor 
	{
		setHeal(4); //have to call setter in main to change heal amount
		setHp(h);
		setDamage(d);
		setCountry(c);
		setXpos(x);
		setYpos(y);

		types.push_back("Medic");
	}
	
	
	Medic::~Medic() //destructor
	{
		//cout<<"Medic’s Destructor was Called"<<endl;
	}


	
	int Medic::getHeal()
	{
		return healAmount;
	}



	void Medic::setHeal(int h)
	{
		healAmount=h;
	}



	
	
	
	

