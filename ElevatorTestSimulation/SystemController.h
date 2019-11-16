#include <iostream>
#include <map>
#include <vector>

using namespace std;


#ifndef ELEVATORTESTSIMULATION_SYSTEMCONTROLLER_H
#define ELEVATORTESTSIMULATION_SYSTEMCONTROLLER_H

#include "Passenger.h"

class SystemController {

public:
    /*
     * Constructor and Destructor
     */
    SystemController(std::string path, int epoch);
    ~SystemController();

public:
    /*
     * Methods
     */

    void generateTraffic(int epoch);
    void startElevator();


public:
    /*
     * Attributes
     */

    map<int, vector<vector<std::string>>> PData;
    map<int,vector<Passenger *>> Levels;
    map<int,vector<Passenger *>> LevelsCopy;
    std::string path;
    int epoch;
    int numberElevator;
    int maxCapacity;

};


#endif //ELEVATORTESTSIMULATION_SYSTEMCONTROLLER_H
