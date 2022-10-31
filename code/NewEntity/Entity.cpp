#ifndef ENTITY_CPP
#define ENTITY_CPP

#include "Entity.h"

using namespace std;

Entity::Entity(int hp, string c, string t){
	setHP(hp);
	setCountry(c);
	setType(t);
}
Entity::~Entity(){

}

bool Entity::takeDamage(int dmg){
	HP -= dmg;
	if(HP<=0){
		HP = 0;
		return true;
	}
	return false;
}
void Entity::heal(int hp){
	HP += hp;
}

#endif