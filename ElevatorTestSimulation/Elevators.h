#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <deque>


using namespace std;


#ifndef ELEVATORTESTSIMULATION_ELEVATORS_H
#define ELEVATORTESTSIMULATION_ELEVATORS_H

#include "Passenger.h"

class Elevators {

public:
    /*
     * Const and Dest
     */
    Elevators();
    ~Elevators();


public:

    /*
     * Methods
     */
    void elevatorIntroduce();


public:
    /*
     * Attributes
     */
    int maxCapacity;            // Max capacity
    char elevatorDirection;     // Direction of Elevator
    int currentFloor;           // Floor where Elevator is
    int lowestFlooor;           // Lowest Floor it can go is
    int higestFloor;            // Higest Floor it can Go

    int static  count;          // Elevator ID
    string ElevatorId;          // Elevator ID
    int elevatorWeightCounter;

    deque <Passenger *> Up;
    deque <Passenger *> Down;

};


#endif //ELEVATORTESTSIMULATION_ELEVATORS_H
