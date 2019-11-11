#include <iostream>

using namespace std;

#include "Elevators.h"

int Elevators::count=0;

Elevators::Elevators():ElevatorWeightCounter{0}
{
    string uniqueId =  "ELEV";
    string unique = uniqueId + std::to_string(count);
    ElevatorId = unique;
    count = count + 1;
}

Elevators::~Elevators()
{
    count = count - 1;

}

void Elevators::elevatorIntroduce()
{

    cout << "\t\tElevator ID:\t"<<ElevatorId<< endl;
    cout << "\t\tElevator Going : \t"<<directionElevator<< endl;
    cout << "\t\tMax Capacity :\t"<< maxCapacity<< endl;
    cout <<"\n";

}















