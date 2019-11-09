

#include <iostream>
#include <ctime>

using  namespace std;


#ifndef ELEVATOREMULATOR_DATETIME_H
#define ELEVATOREMULATOR_DATETIME_H


class DateTime {
public:
    /*
     * Methods
     */
    static time_t  getDate();
    static time_t getMonth();
    static time_t getDay();
    static time_t getDateTime();


public:
    DateTime();
    ~DateTime();

};


#endif //ELEVATOREMULATOR_DATETIME_H
