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
    cout << "-------------------------------------------"<< endl;
    cout << "Hi ! I am MedicalStaff:\t"<<PassengerId << endl;
    cout << "Current Floor:\t"<<CurrentFloor<< endl;
    cout << "Destination Floor:\t" << DestinationFloor << endl;
}

void MedicalStaff::emergency()
{
    cout << "MedicalStaff : emergencey" << endl;
}