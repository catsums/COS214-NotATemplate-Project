#include <string>
#include <iostream>
#include "Transport.h"

using namespace std;

	Transport::Transport():Vehicle()// default constuctor 
	{
		
		//cout<<"Transport’s Constructor was Called"<<endl;
		setFeul(150);
		setHp(80);
		setDamage(8);
		setCountry("SA");
		setXpos(0);
		setYpos(0);

		types.push_back("Transport");
	} 


	Transport::Transport(int h,string c, int d, int x , int y ):Vehicle(h,c,d,x,y)// param constuctor 
	{
		setFeul(150);
		setHp(h);
		setDamage(d);
		setCountry(c);
		setXpos(x);
		setYpos(y);

		types.push_back("Transport");
	}
	
	
	Transport::~Transport() //destructor
	{
		//cout<<"Transport’s Destructor was Called"<<endl;
	}


	
	void Transport::setFeul(int f)
	{
		feul=f;
	}

	int Transport::getFeul()
	{
		return feul;
	}


	void Transport::infoSummary()
	{
		cout<<"*Entity Details*:"<<endl;
		cout<<"Health: " <<hp<<endl;
		cout<<"Country: " <<country<<endl;
		cout<<"Damage: " <<damage<<endl;
		cout<<"Position: (" <<xpos<<","<<ypos<<")"<<endl;
		cout<<"Feul: "<<getFeul()<<endl;
	}

