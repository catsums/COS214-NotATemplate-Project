#ifndef ENTITY_H
#define ENTITY_H

#include <string>


using namespace std; 

class Entity
{

private:

	int hp; // health of each entity 
	string country; // country each entity belongs to 
	// TODO: change to country type
	int damage; // determines how much damage the entity deals

	int xpos; // The x coordinate of the entity 
	int ypos; // The y coordinate of the entity 




public: 

	Entity();// default constuctor
	virtual ~Entity(); //destructor

	//setters
	void setHp(int);

	void setCountry(string);

	void setDamage(int);

	void setXpos(int);

	void setYpos(int);
	

	//getters
	int getHp();

	string getCountry();

	int getDamage();

	int getXpos();

	int getYpos();
	
	/*

	This function takes in an integer amount that will decrease 
	the entity's hp

	*/

	virtual void takeDamage(int)=0;
	

	/*

	This function will deal a damage amount to another entity

	*/

	virtual void dealDamage()=0;

	
	/*

	This function allow the entity to move

	*/

	virtual void move(int,int)=0;


	/*

	This function will allow an entity to recieve more hp 
	eg. From a medic

	*/

	virtual void recieveHp(int)=0;

	
	
	
	
};

#endif