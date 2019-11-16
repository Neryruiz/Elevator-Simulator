#include <iostream>
#include <map>
#include <vector>

using namespace std;


#ifndef ELEVATORTESTSIMULATION_ELEVATORS_H
#define ELEVATORTESTSIMULATION_ELEVATORS_H


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
    int maxCapacity;
    char elevatorDirection;
    int currentFloor;
    int lowestFlooor;
    int higestFloor;
    int static  count;
    string ElevatorId;

};


#endif //ELEVATORTESTSIMULATION_ELEVATORS_H
