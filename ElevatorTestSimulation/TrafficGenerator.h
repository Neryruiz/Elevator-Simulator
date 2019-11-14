#include <map>
#include <vector>

using namespace std;


#ifndef ELEVATORTESTSIMULATION_TRAFFICGENERATOR_H
#define ELEVATORTESTSIMULATION_TRAFFICGENERATOR_H

#include "Passenger.h"


class TrafficGenerator {

public:
    /*
     * Attributes
     */
    int numFloor;
    int numElevators;
    int maxCapacity;
    int batchSize;

    vector<int>PassengerSpawnRange;
    map<int, vector<vector<std::string>>> PData;
    map<int,vector<Passenger *>> Levels;

public:
    void generatePassengers();
    vector<int> setSpawnRange(vector<float> &Rates);
public:
    TrafficGenerator(std::string path);
    ~TrafficGenerator();


};


#endif //ELEVATORTESTSIMULATION_TRAFFICGENERATOR_H
