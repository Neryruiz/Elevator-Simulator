/*
 * This is Patient.cpp File
 *
 */

#include <iostream>

using namespace std;

#include "Patients.h"
#include "Passenger.h"

int Patients::count = 0;


Patients::Patients()
{
    // cout << " Patients class  Constructor ---->" << endl;
    string uniqueId =  "P";
    count ++;
    string unique = uniqueId + std::to_string(count);
    PassengerId = unique;
}

Patients::~Patients()
{
    // cout  << "Patient class Destructor --------> " <<  endl;
    count --;
}


void Patients::introduce()
{
    cout << "\t\tHi ! I am Patients:\t"<<PassengerId << endl;
    cout << "\t\tCurrent Floor:\t"<<CurrentFloor<< endl;
    cout << "\t\tDestination Floor:\t"<<DestinationFloor<< endl;
    cout <<"\n";
}
