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
    queue <Passenger *> Up;
    queue <Passenger *> Down;
    int ElevatorFloor;
    bool Direction;
    int static count;
    string ElevatorId;
    int TopFloor;

public:
    /*
     *  Constructor and Dest
     */
    Elevators();
    Elevators(int topFloor);
    ~Elevators();

public:
    /*
     * Attributes
     */


    int getCurrentFloor();
    void incrementCurrentFloor();
    bool getCurrentDirection();
    void ToggleDirection();

};


#endif //ELEVATOREMULATOR_ELEVATORS_H
