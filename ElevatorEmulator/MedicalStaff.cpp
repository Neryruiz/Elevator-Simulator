/*
 * this os MedicalStafff.cpp File
 *
 */
#include <iostream>


#include "MedicalStaff.h"
#include "Passenger.h"

int MedicalStaff::count=0;

MedicalStaff::MedicalStaff()
{
    //cout << " MedicaStaff Constructor ---->" << endl;
    string uniqueId =  "MS";
    count++;
    string unique = uniqueId + std::to_string(count);
    PassengerId = unique;
}


MedicalStaff::~MedicalStaff()
{
    // cout << "MedicalStaff Destructor  --> " << endl;
    count --;
}

void MedicalStaff::introduce()
{
    cout << "\t\tHi ! I am MedicalStaff:\t"<<PassengerId << endl;
    cout << "\t\tCurrent Floor:\t"<<CurrentFloor<< endl;
    cout << "\t\tDestination Floor:\t"<<DestinationFloor<< endl;
    cout <<"\n";
}

void MedicalStaff::emergency()
{
    cout << "MedicalStaff : emergencey" << endl;
}