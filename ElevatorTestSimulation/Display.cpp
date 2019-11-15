#include <map>
#include <vector>
#include <iostream>

#include "Passenger.h"
#include "Display.h"

void Display::introducePassenger(map<int,vector<Passenger *>> Levels)
{
    cout << "\n";
    cout << "\t\t==============================================="<< endl;
    cout << "\t\t\t\t\t" << "Passenger Created  " << endl;
    cout << "\t\t==============================================="<< endl;
    cout << "\n";

    // LEVEL DATA STRUCTURE
    for(int j = 0; j< Levels.size(); j++){
        for(auto x:Levels[j])
        {
            x->introduce();
        }
    }

    // For a given Batch Keeps count of Total Passengers
}


void Display::displayTotalPassengerCount(int num)
{
    cout << "\n";
    cout << "\t\t==============================================="<< endl;
    cout << "\t\t\t\t\t" << "Total Passenger Generated  "<< num  << endl;
    cout << "\t\t==============================================="<< endl;
    cout << "\n";

}