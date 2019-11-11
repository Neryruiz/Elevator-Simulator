#include <iostream>

using namespace std;

#include "Elevators.h"
int Elevators::count=0;

Elevators::Elevators():maxCapacity{0}, ElevatorFloor{0}{

    string uniqueId =  "ELEV";
    count++;
    string unique = uniqueId + std::to_string(count);
    ElevatorId = unique;
}

Elevators::Elevators(int topFloors):maxCapacity{0},
ElevatorFloor{0},
TopFloor{topFloors},
Direction{true}{

    string uniqueId =  "ELEV";
    count++;
    string unique = uniqueId + std::to_string(count);
    ElevatorId = unique;
}

Elevators::~Elevators()
{

    // cout << "Elevators Dest " << endl;
}

int Elevators::getCurrentFloor()
{
    return ElevatorFloor;
}


void Elevators::incrementCurrentFloor()
{
    // If True
    if (Direction and ElevatorFloor < TopFloor)
    {
        ElevatorFloor++;
    } else if(!Direction and ElevatorFloor>0)
        {
        ElevatorFloor --;
        }
    else{
        ToggleDirection();
    }
}

bool Elevators::getCurrentDirection()
{
    return Direction;
}

void Elevators::ToggleDirection()
{
    Direction = ! Direction;
}



