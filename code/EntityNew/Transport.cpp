#include <string>
#include <iostream>
#include "Transport.h"

using namespace std;

	Transport::Transport()// default constuctor 
	{
		
		//cout<<"Transport’s Constructor was Called"<<endl;
		setHp(80);
		setDamage(8);
		setCountry("SA");
		setXpos(0);
		setYpos(0);

	} 


	Transport::Transport(int h,string c, int d, int x , int y ):Vehicle(h,c,d,x,y)// param constuctor 
	{
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


	

	
	
	

