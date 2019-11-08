//
// Created by Soumil Shah on 11/7/19.
//

#ifndef ELEVATOREMULATOR_STATISTICSKEEPER_H
#define ELEVATOREMULATOR_STATISTICSKEEPER_H


class StatisticsKeeper {

public:
    std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);

public:
    StatisticsKeeper();
    ~StatisticsKeeper();


public:
    static time_t getMonth();
    static time_t getDay();
    static time_t getYear();
    static time_t getDateTime();

};


#endif //ELEVATOREMULATOR_STATISTICSKEEPER_H
