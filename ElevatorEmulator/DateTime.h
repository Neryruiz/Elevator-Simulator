

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
    static time_t getDay();
    static time_t getMonth();
    static time_t getYear();
    static time_t  getDate();   // dont work

    static time_t getHour();
    static time_t getMinutes();
    static time_t getSeconds();

    static time_t getDateTime();
    static time_t getTime();        // dont work


public:
    DateTime();
    ~DateTime();

};


#endif //ELEVATOREMULATOR_DATETIME_H
