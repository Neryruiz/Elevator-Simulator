#include <iostream>
#include <map>
#include <vector>

using namespace std;


#ifndef ELEVATORTESTSIMULATION_SYSTEMCONTROLLER_H
#define ELEVATORTESTSIMULATION_SYSTEMCONTROLLER_H

#include "Passenger.h"
#include "timingWheel.h"
#include "partitions.h"


class SystemController {

public:
    /*
     * Constructor and Destructor
     */
    SystemController(std::string path, int epoch, int delay);      // Populate Traffic in Const
    ~SystemController();                                // Dest

public:
    /*
     * Methods
     */

    void startElevator();                   // Creates Elevator object and Starts Lift etc


public:
    /*
     * Attributes
     */

    map<int, vector<vector<std::string>>> PData;        // PData DataStructure
    map<int,vector<Passenger *>> Levels;                // Current Floow Data Structrue
    map<int , vector<Passenger *>> LevelDest;           // Dest Floor Data Structure
    map<int, bool> floorStatus;                         // Its Flag whether person is there on that FLoor or not

    std::string path;                                   // File Path
    int epoch;                                          // Epoch of Iteration
    int numberElevator;                                 // Total Number of Elevators
    int maxCapacity;                                    // max capacity of elevator
    int maxFloor;                                       // Max Floors
    timingWheel *timewheel;                             // timing wheel partition
    int delay;

};


#endif //ELEVATORTESTSIMULATION_SYSTEMCONTROLLER_H
