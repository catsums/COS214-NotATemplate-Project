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
	}
	WeaponItem(int dmg, int amt):Item(amt){
		damage = dmg;
	}
	WeaponItem(WeaponItem& wpn):Item(wpn){
		damage = wpn.damage;
	}
	~WeaponItem(){

	}

	virtual Resource* clone(){
		return new WeaponItem(*this);
	}

	virtual void useOn(Entity* ent){
		if(amount>0 && !used){
			ent->takeDamage(damage);
			amount--;
			if(amount<=0){
				used = true;
			}
		}
	}

	int getDamage(){
		return damage;
	}
protected:
	int damage = 10;
}

#endif