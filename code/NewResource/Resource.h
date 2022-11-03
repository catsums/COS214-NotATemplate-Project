#ifndef RESOURCE_H
#define RESOURCE_H

#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <random>
#include <cmath>
#include <math.h>
#include <sstream>

using namespace std;

class Resource{
public:
	Resource();
	Resource(Resource& r);
	~Resource();

	virtual Resource* clone() = 0;

	bool isUsed();

	string getID(){
		return id;
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

	string printInfo(){
		stringstream ss;

		ss << "RESOURCE-" << getID() << "{" << getInfo() << "}";

		return ss.str();
	}

	virtual string getInfo(){
		stringstream ss;

		ss << " Type: " << getType() << "|";
		ss << " isUsed: " << (used ? "Y" : "N") << "|";

		return ss.str();
	}

protected:
	bool used;
	string id;
	vector<string> types;
};

#endif