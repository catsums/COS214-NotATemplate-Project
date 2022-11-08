#include <string>
#include <iostream>
#include "Artillery.h"

using namespace std;

	Artillery::Artillery():Vehicle()// default constuctor 
	{
		
		//cout<<"Artillery’s Constructor was Called"<<endl;
		setFeul(100);
		setHp(80);
		setDamage(8);
		setCountry("SA");
		setXpos(0);
		setYpos(0);

		types.push_back("Artillery");

	} 
	Artillery::Artillery(Vehicle& v):Vehicle(v)// copy constuctor 
	{

		types.push_back("Artillery");

	} 


	Artillery::Artillery(int h,string c, int d, int x , int y ):Vehicle(h,c,d,x,y)// param constuctor 
	{
		setFeul(100);
		setHp(h);
		setDamage(d);
		setCountry(c);
		setXpos(x);
		setYpos(y);

		types.push_back("Artillery");
	}
	
	
	Artillery::~Artillery() //destructor
	{
		//cout<<"Artillery’s Destructor was Called"<<endl;
	}


	void Artillery::infoSummary()
	{
		cout<<"*Entity Details*:"<<endl;
		cout<<"Health: " <<hp<<endl;
		cout<<"Country: " <<country<<endl;
		cout<<"Damage: " <<damage<<endl;
		cout<<"Position: (" <<xpos<<","<<ypos<<")"<<endl;
		cout<<"Feul: "<<getFeul()<<endl;
	}

