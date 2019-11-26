//
// Created by Soumil Shah on 11/26/19.
//

#ifndef ELEVATORSIMULATIONSSOFTWARE_TIMINGWHEEL_H
#define ELEVATORSIMULATIONSSOFTWARE_TIMINGWHEEL_H

#include <vector>
#include <map>
#include <queue>

#include "partitions.h"
#include "Elevators.h"


class timingWheel {

public:
    partitions ** slots;
    int currentSlot;
    int delaySize;
    int maxDelay;
    int numFloors;

    timingWheel(int floors, int delay,
            map<int,vector<Passenger *>> &Levels, map<int, vector<vector<std::string>>> &PData);

    ~timingWheel();
    void insert(int travelFloors, Elevators* p);
    void schedule();
    void clearCurrentSlot();
    void clearSlot(int s);
};


#endif //ELEVATORSIMULATIONSSOFTWARE_TIMINGWHEEL_H
