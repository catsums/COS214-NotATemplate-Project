#include <string>
#include <iostream>
#include "Entity.h"
#include "Citizen.h"
#include "Soldier.h"
#include "Medic.h"
#include "Informant.h"
#include "Politician.h"

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
	

	int Entity::getHp()
	{
		return hp;
	}

	string Entity::getCountry()
	{
		return country;
	}

	
	

	

	

