#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Position{
	int x = 0;
	int y = 0;
};

class Entity{
public:
	Entity(int hp, string c, string t);
	~Entity();

	virtual bool takeDamage(int dmg);
	virtual void heal(int hp);
	virtual bool travel(int x, int y) = 0;
	virtual void attack(Entity* target) = 0;

	//setters and getters
	void setHP(int hp){
		HP = hp;
	}
	int getHP(){
		return HP;
	}

	string setCountry(string c){
		string temp = country;
		country = c;
		return temp;
	}
	string getCountry(){
		return country;
	}

	void setAlive(bool _alive){
		alive = _alive;
	}
	bool isAlive(){
		return alive;
	}

	Position getPosition(){
		return zone;
	}

	void setPosition(int x, int y){
		zone.x = x;
		zone.y = y;
	}

	void setPosition(Position newPos){
		zone.x = newPos.x;
		zone.y = newPos.y;
	}

	string getType(){
		return type;
	}
	string setType(string t){
		string temp = type;
		type = t;
		return temp;
	}

protected:
	bool alive;
	int HP;
	string country;
	string type;
	Position zone;
};


#endif