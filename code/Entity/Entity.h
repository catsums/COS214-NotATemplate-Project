/** @file Entity.h
 *  @brief This is the header file to create the entity class.
 *
 *  Creating an entity class allows us to create our various elements that are invloved in the war
 *  an example of an entity is a Citizen
 */


#ifndef ENTITY_H
#define ENTITY_H

#include <string>


using namespace std; 

class Entity
{

protected:

	int hp; /**<int variable showcasing the health points*/
	string country; /**<string variable that holds the country*/
	int damage; /**<int variable holding the amount of damage*/

	int xpos; /**<int variable holding the x-coordinates of the entity*/
	int ypos; /**<int variable holding the y-coordinates of the entity*/




public: 

	/** Default constructor for entity
    */
	Entity();

	/** Destructor
    */
	virtual ~Entity(); 



	///Setters
	/**	This is a setter which sets the health points of an entity
	* 	@param int variable that sets the health points of an entity 
	*/
	void setHp(int);


	/**	This is a setter which sets the country of an entity
	* 	@param string variable that sets the country of an entity 
	*/
	void setCountry(string);

	/**	This is a setter which sets the damage of an entity
	* 	@param int variable that sets the damage of an entity 
	*/
	void setDamage(int);


	/**	This is a setter which sets the x-position of an entity
	* 	@param int variable that sets the x-position of an entity 
	*/
	void setXpos(int);


	/**	This is a setter which sets the y-position of an entity
	* 	@param int variable that sets the y-position of an entity 
	*/
	void setYpos(int);
	

	///Getters
	/**	Gets the health points of an entity
	*/
	int getHp();

	/**	Gets the country of an entity
	*/
	string getCountry();

	/**	Gets the damage of an entity
	*/
	int getDamage();

	/**	Gets the x-position of an entity
	*/
	int getXpos();

	/**	Gets the y-position of an entity
	*/
	int getYpos();


	///Other functions 


	/**This function couts all the entity variables
	*/
	void infoSummary();
	
	/** This function takes in an integer amount that will decrease 
	*	the entity's hp.
	*	@param int variable that takes the damage
	*/
	virtual void takeDamage(int)=0;
	

	/**This function will deal a damage amount to another entity
	*/
	virtual int dealDamage()=0;

	/** This function allow the entity to move
	*	@param int variable that takes in the x-coordinates of an entity
	*	@param int variable that takes in the y-coordinates of an entity
	*/
	virtual void move(int,int)=0;


	/** This function will allow an entity to recieve more hp 
	*	eg. From a medic
	*	@param int variable recieving more health 
	*/
	virtual void recieveHp(int)=0;

	
	
	
	
};

#endif