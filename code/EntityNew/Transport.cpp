#include <string>
#include <iostream>
#include "Transport.h"

using namespace std;

	Transport::Transport()// default constuctor 
	{
		
		//cout<<"Transport’s Constructor was Called"<<endl;
		setFeul(150);
		setHp(60);
		setDamage(1);
		setCountry("SA");
		setXpos(0);
		setYpos(0);

	} 


	Transport::Transport(int h,string c, int d, int x , int y ):Vehicle(h,c,d,x,y)// param constuctor 
	{
		setFeul(100);
		setHp(h);
		setDamage(d);
		setCountry(c);
		setXpos(x);
		setYpos(y);
	}
	
	
	Transport::~Transport() //destructor
	{
		//cout<<"Transport’s Destructor was Called"<<endl;
	}


	int Transport::getFeul() 
	{
		return feul;
	}
	
	
	void Transport::setFeul(int f) 
	{
		feul = f;;
	}

	
	
	

