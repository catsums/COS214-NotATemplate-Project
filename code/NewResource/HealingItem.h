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
		healingAmt = 10;
		types.push_back("HealingItem");
	}
	HealingItem(int amt, int healAmt):Item(amt){
		healingAmt = healAmt;
		types.push_back("HealingItem");
	}
	HealingItem(int healAmt):Item(1){
		healingAmt = healAmt;
		types.push_back("HealingItem");
	}
	HealingItem(HealingItem& item):Item(item){
		healingAmt = item.healingAmt;
		types.push_back("HealingItem");
	}
	~HealingItem(){

	}

	virtual Resource* clone(){
		return new HealingItem(*this);
	}

	virtual Entity* useOn(Entity* ent){
		if(amount>0 && !used){
			ent->heal(healingAmt);
			amount--;
			if(amount<=0){
				used = true;
			}
		}
		return ent;
	}

	int getHealingAmt(){
		return healingAmt;
	}
protected:
	int healingAmt = 10;
}

#endif