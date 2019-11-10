//
// Created by Soumil Shah on 10/30/19.
//

#include <iostream>
using namespace std;



#include "SecurityPersonnel.h"

int SecurityPersonnel::count = 0;

SecurityPersonnel::SecurityPersonnel()
{
    cout << "SecurityPersonall Constructor " << endl;

    string uniqueId =  "SEC";
    count++;
    string unique = uniqueId + std::to_string(count);
    PassengerId = unique;
}

SecurityPersonnel::~SecurityPersonnel()
{
    cout << "SecurityPersonnel Destructor  " << endl;
    count --;
}

void SecurityPersonnel::introduce()
{
    cout << "-------------------------------------------"<< endl;
    cout << "Hi ! I am SecurityPersonnel:\t"<<PassengerId << endl;
    cout << "Current Floor:\t"<<CurrentFloor<< endl;
    cout << "Destination Floor:\t" << DestinationFloor << endl;
}

void SecurityPersonnel::evacuate()
{
    cout << "SecurityPersonnel : evacuate " << endl;
}