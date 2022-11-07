#ifndef WEAPONITEM_H
#define WEAPONITEM_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "Item.h"

class WeaponItem: public Item{
public:
	WeaponItem():Item(1){
		damage = 10;
		types.push_back("WeaponItem");
	}
	WeaponItem(int amt, int dmg):Item(amt){
		damage = dmg;
		types.push_back("WeaponItem");
	}
	WeaponItem(int dmg):Item(1){
		damage = dmg;
		types.push_back("WeaponItem");
	}
	WeaponItem(WeaponItem& wpn):Item(wpn){
		damage = wpn.damage;
		types.push_back("WeaponItem");
	}
	~WeaponItem(){

	}

	virtual Resource* clone(){
		return new WeaponItem(*this);
	}

	virtual Entity* useOn(Entity* ent){
		if(amount>0 && !used){
			ent->takeDamage(damage);
			amount--;
			if(amount<=0){
				used = true;
			}
		}
		return ent;
	}

	int getDamage(){
		return damage;
	}
protected:
	int damage = 10;
}

#endif