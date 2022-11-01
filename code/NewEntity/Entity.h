#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <cmath>
#include <math.h>

#include "../Structs.h"

using namespace std;

class Entity{
public:
	Entity(int hp, string c);
	Entity(Entity& ent);
	~Entity();

	virtual bool takeDamage(int dmg);
	virtual void heal(int hp);
	virtual bool travel(int x, int y) = 0;
	virtual void attack(Entity* target) = 0;

	virtual void die();

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
		return types.back();
	}
	vector<string> getTypes(){
		return types;
	}
	bool isType(string type){
		for(int i=0;i<(int)types.size();i++){
			if(types[i]==type){
				return true;
			}
		}
		return false;
	}
	string setType(string t){
		string temp = types.back();
		types.pop_back();
		types.push_back(t);
		return temp;
	}

	string getID(){
		return id;
	}

	bool canTravelLand(){
		return land;
	}
	bool canTravelSea(){
		return sea;
	}

protected:
	string id;
	bool alive = true;
	int HP;
	string country;
	vector<string> types;
	Position zone;
	bool land;
	bool sea;
};


#endif