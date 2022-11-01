#ifndef HEALINGITEM_H
#define HEALINGITEM_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "Item.h"

class HealingItem: public Item{
public:
	HealingItem():Item(1){
		HealingItem = 10;
	}
	HealingItem(int dmg, int amt):Item(amt){
		healingAmt = dmg;
	}
	HealingItem(HealingItem& wpn):Item(wpn){
		healingAmt = wpn.healingAmt;
	}
	~HealingItem(){

	}

	virtual Resource* clone(){
		return new HealingItem(*this);
	}

	virtual void useOn(Entity* ent){
		if(amount>0 && !used){
			ent->heal(healingAmt);
			amount--;
			if(amount<=0){
				used = true;
			}
		}
	}

	int getHealingAmt(){
		return healingAmt;
	}
protected:
	int healingAmt = 10;
}

#endif