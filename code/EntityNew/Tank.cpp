#include <string>
#include <iostream>
#include "Tank.h"

#include "Artillery.h"


using namespace std;

	Tank::Tank()// default constuctor 
	{
		//cout<<"Tank’s Constructor was Called"<<endl;
	} 

	
	Tank::~Tank() //destructor
	{
		//cout<<"Tank’s Destructor was Called"<<endl;
	}

	
	
	void Tank::decreaseFeul(Artillery* a,int f)
	{

		cout<<a->getFeul()<<endl;
		//int temp = a->getFeul();
		// temp=temp-f;

		// if (temp>=0)
		// {
		// 	//a->setFeul(temp);

		// }

		// else
		// {
		// 	//a->setFeul(0);

		// }
	}

	

