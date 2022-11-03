#ifndef COUNTRY_H
#define COUNTRY_H

#include <string>

using namespace std;

class Country
{
    public:
        Country(string n, bool s);
        ~Country();

        bool getSide();
        string getName();
    private:
        bool side;
        string name;
};

#endif