#include <iostream>
#include <string>
#include <map>
#include <vector>




#ifndef ELEVATORTESTSIMULATION_STATISTICSKEEPER_H
#define ELEVATORTESTSIMULATION_STATISTICSKEEPER_H


class StatisticsKeeper {
public:
    StatisticsKeeper();
    ~StatisticsKeeper();

public:
    static int totalPassengerCreatedInBatchSize;

};


#endif //ELEVATORTESTSIMULATION_STATISTICSKEEPER_H
