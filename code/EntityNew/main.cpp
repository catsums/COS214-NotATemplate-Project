#include <iostream>

#include "Entity.cpp"
#include "Citizen.cpp"




using namespace std; 


int main()
{

	Entity *test = new Citizen();


	cout<<"Testing Damage Taken:"<<endl;

	cout<<test->getHp()<<endl;
	test->takeDamage(4);
	cout<<test->getHp()<<endl;


	cout<<"Testing Healing:"<<endl;

	test->recieveHp(4);
	cout<<test->getHp()<<endl;

	delete test;

}