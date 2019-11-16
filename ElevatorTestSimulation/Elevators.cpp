#include <iostream>
#include <vector>
#include <map>
using  namespace std;

#include "Elevators.h"

int Elevators::count=0;


Elevators::Elevators():elevatorWeightCounter{0}
{
    string uniqueId =  "ELEV";
    string unique = uniqueId + std::to_string(count);
    ElevatorId = unique;
    count = count + 1;

}
Elevators::~Elevators()
{

}

void Elevators::elevatorIntroduce()
{

    cout << "\t\tElevator ID:\t"<<ElevatorId<< endl;
    cout << "\t\tElevator Going : \t"<<elevatorDirection<< endl;
    cout << "\t\tMax Capacity :\t"<< maxCapacity<< endl;
    cout <<"\n";

}
