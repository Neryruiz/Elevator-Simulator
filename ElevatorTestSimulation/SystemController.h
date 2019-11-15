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

public:
    /*
     * Attributes
     */

    map<int, vector<vector<std::string>>> PData;
    map<int,vector<Passenger *>> Levels;
    std::string path;
    int epoch;

};


#endif //ELEVATORTESTSIMULATION_SYSTEMCONTROLLER_H
