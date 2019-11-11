#include <iostream>
#include <ctime>
#include <chrono>
#include <sstream>
#include <string>

using namespace std;

#include "DateTime.h"

DateTime::DateTime()
{
    cout << "Constructor " << endl;
}

DateTime::~DateTime()
{
    cout << "Destructor " <<endl;
}

time_t DateTime::getDay()
{
    std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);
    return  now->tm_mday;
}

time_t DateTime::getMonth()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    return ltm->tm_mon+1;
}

time_t DateTime::getYear()
{
    time_t t = time(NULL);
    tm* timePtr = localtime(&t);
    return  timePtr->tm_year + 1900;
}

time_t DateTime::getDate()
{
    time_t day = getDay();
    time_t month = getMonth();
    time_t year = getYear();


    return day;
}


time_t DateTime::getHour()
{
    time_t t = time(NULL);
    tm* timePtr = localtime(&t);
    return  timePtr->tm_hour;
}
time_t DateTime::getMinutes()
{
    time_t t = time(NULL);
    tm* timePtr = localtime(&t);
    return timePtr->tm_min;
}

time_t DateTime::getSeconds()
{
    time_t t = time(NULL);
    tm* timePtr = localtime(&t);
    return timePtr->tm_sec;
}


time_t DateTime::getTime()
{
    time_t hour = getHour();
    time_t minutes = getMinutes();
    time_t sec = getSeconds();
    time_t time = hour + minutes + sec;

    return time;

}

time_t DateTime::getDateTime()
{
//    time_t date = getDate();
//    time_t time = getTime();
//    time_t datetime = date+time;

    time_t now = time(0);
    cout << "***" << endl;

    char* dt = ctime(&now);     // Coverts time_t into Char  Nov 10 15:24:56 2019

    return now;
}

