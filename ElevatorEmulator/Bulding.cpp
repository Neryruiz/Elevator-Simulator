#include <iostream>

using namespace std;
#include "Bulding.h"

Bulding::Bulding():floor{0}
{
    // By Deaf val is set to 0
    cout << "Bulding constructor " << endl;
}


Bulding::Bulding(int floor) :floor{floor}
{
    cout << "Overloaded Constructor " << endl;
}

Bulding::~Bulding()
{
    cout << "Bulding class Destructor "<< endl;
}

