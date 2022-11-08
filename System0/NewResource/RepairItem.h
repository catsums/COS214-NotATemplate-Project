#ifndef REPAIRITEM_H
#define REPAIRITEM_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "Item.h"

class RepairItem: public Item{
public:
	RepairItem():Item(1){
		repairAmt = 10;
		types.push_back("RepairItem");
	}
	RepairItem(int amt, int repAmt):Item(amt){
		repairAmt = repAmt;
		types.push_back("RepairItem");
	}
	RepairItem(int repAmt):Item(1){
		repairAmt = repAmt;
		types.push_back("RepairItem");
	}
	RepairItem(RepairItem& item):Item(item){
		repairAmt = item.healingAmt;
		types.push_back("RepairItem");
	}
	~RepairItem(){

	}
	virtual Resource* clone(){
		return new RepairItem(*this);
	}

	virtual Entity* useOn(Entity* ent){
		if(amount>0 && !used){
			if(ent->isType("Vehicle")){
				ent->heal(healingAmt);
				amount--;
				if(amount<=0){
					used = true;
				}
			}
		}
		return ent;
	}

	int getRepairAmt(){
		return repairAmt;
	}
protected:
	int repairAmt = 10;

};

#endif