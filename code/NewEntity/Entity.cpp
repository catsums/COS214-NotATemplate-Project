#ifndef ENTITY_CPP
#define ENTITY_CPP

#include "Entity.h"

using namespace std;

static int getRandomInt(int a, int b){
    int max, min;
    if(a>b){
        max = a; min = b;
    }else{
        max = b; min = a;
    }
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> distr(min, max);

    return (int) distr(gen);
}
static string randomString(int len = 9) {
    const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    int stringLen = sizeof(alphanum) - 1;

    string str;
    for (int i = 0; i < len; i++) {
        int rnd = getRandomInt(0, stringLen);
        str += alphanum[rnd % stringLen];
    }
    return str;
}

Entity::Entity(int hp, string c){
	id = randomString(8);
	setHP(hp);
	setCountry(c);
	types.push_back("Entity");

	alive = true;
}
Entity::Entity(Entity& ent){
	id = randomString(8);
	HP = ent.HP;
    alive = ent.alive;
    country = ent.country;
    types.push_back("Entity");
    zone = ent.zone;
}
Entity::~Entity(){

}

bool Entity::takeDamage(int dmg){
	HP -= dmg;
	if(HP<=0){
		die();
		return true;
	}
	return false;
}
bool Entity::heal(int hp){
    if(isAlive()){
	   HP += hp;
    }
    return isAlive();
}

void Entity::die(){
	alive = false;
    HP = 0;
}

#endif