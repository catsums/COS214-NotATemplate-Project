#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <cmath>
#include <math.h>
#include <sstream>

#include "../Structs.h"

using namespace std;

class Entity{
public:
	Entity(int hp);
	Entity(int hp, string c);
	Entity(Entity& ent);
	~Entity();

	virtual bool takeDamage(int dmg);
	virtual bool heal(int hp);
	virtual bool travel(int x, int y) = 0;
	virtual bool travel(Position pos){
		return travel(pos.x,pos.y);
	}
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

	virtual int getOverallStrength(){
		return HP;
	}

	string printInfo(){
		stringstream ss;

		ss << "ENTITY-" << getID() << "{" << getInfo() << "}";

		return ss.str();
	}

	virtual string getInfo(){
		stringstream ss;

		ss << " Type: " << getType() << "|";
		ss << " HP: " << HP << "|";
		ss << " Pos: " << zone.x << "," << zone.y << "|";
		ss << " Alive: " << ((alive) ? "Y" : "N") << "|";
		ss << " Country: " << country << " | ";
		ss << " OverallStrength: " << getOverallStrength() << "|";


		return ss.str();
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