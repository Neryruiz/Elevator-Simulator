#include <iostream>
#include <ctime>
#include <queue>
#include <map>
#include <vector>


using namespace std;

#ifndef ELEVATOREMULATOR_ELEVATORS_H
#define ELEVATOREMULATOR_ELEVATORS_H

#include "Passenger.h"

class Elevators {

public:
    /*
     * Attributes
     */

    int maxCapacity;
    char directionElevator;
    int elevatorCurrentFloor;
    int static  count;
    string ElevatorId;
    int ElevatorWeightCounter;

    queue <Passenger *> Up;
    queue <Passenger *> Down;


public:
    /*
     *  Constructor and Dest
     */

    Elevators();
    ~Elevators();


public:
    /*
     * Methods
     */

    void elevatorIntroduce();
};


#endif //ELEVATOREMULATOR_ELEVATORS_H
