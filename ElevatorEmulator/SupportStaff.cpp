/*
 * this is SupportStaff.cpp
 */


#include "SupportStaff.h"
using namespace std;


#include "Passenger.h"

int SupportStaff::count = 0;


SupportStaff::SupportStaff()
{
    // cout << "Support Staff Constructor " << endl;

    string uniqueId =  "SS";
    count++;
    string unique = uniqueId + std::to_string(count);
    PassengerId = unique;
}

SupportStaff::~SupportStaff()
{
    //cout << "Support staff Destructor " << endl;
    count --;
}


void SupportStaff::introduce()
{
    cout << "\t\tHi ! I am SupportStaff:\t"<<PassengerId << endl;
    cout << "\t\tCurrent Floor:\t"<<CurrentFloor<< endl;
    cout << "\t\tDestination Floor:\t"<<DestinationFloor<< endl;
    cout <<"\n";
}


void SupportStaff::emergency()
{
    cout << "Support Staff Emergency " << endl;
}