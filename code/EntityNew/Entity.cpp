#include <string>
#include <iostream>
#include "Entity.h"


using namespace std;

	Entity::Entity()// default constuctor 
	{
		//cout<<"Entity’s Constructor was Called"<<endl;
	} 

	
	Entity::~Entity() //destructor
	{
		//cout<<"Entity’s Destructor was Called"<<endl;
	}

	void Entity::setHp(int h)
	{
		hp = h;
	}

	void Entity::setCountry(string c)
	{
		country = c;
	}


	void Entity::setDamage(int d)
	{
		hp = h;
	}


	void Entity::setXpos(int h)
	{
		hp = h;
	}


	void Entity::setYpos(int h)
	{
		hp = h;
	}
	

	int Entity::getHp()
	{
		return hp;
	}

	string Entity::getCountry()
	{
		return country;
	}

	
	

	

	

