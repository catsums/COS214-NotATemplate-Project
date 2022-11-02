#include <string>
#include <iostream>
#include "Entity.h"


using namespace std;

	Entity::Entity()// default constuctor 
	{
		cout<<"Entity’s Constructor was Called"<<endl;
	} 

	
	Entity::~Entity() //destructor
	{
		cout<<"Entity’s Destructor was Called"<<endl;
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
		damage = d;
	}


	void Entity::setXpos(int x)
	{
		xpos = x;
	}


	void Entity::setYpos(int y)
	{
		ypos = y;
	}
	

	int Entity::getHp()
	{
		return hp;
	}

	string Entity::getCountry()
	{
		return country;
	}

	int Entity::getDamage()
	{
		return damage;
	}

	int Entity::getXpos()
	{
		return xpos;
	}

	int Entity::getYpos()
	{
		return ypos;
	}

	

	

	

