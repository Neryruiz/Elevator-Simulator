#include <ctime>
#include <iostream>

using namespace std;


#include "StatisticsKeeper.h"


StatisticsKeeper::StatisticsKeeper()
{
    cout << "Constructor " << endl;
}

StatisticsKeeper::~StatisticsKeeper()
{
    cout << "Destructor  "<< endl;
}

time_t StatisticsKeeper::getDateTime()

{    std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);
    return  t;
}


time_t StatisticsKeeper::getDay()
{

    std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);
    return  now->tm_mday;

}


time_t  StatisticsKeeper::getMonth()
{
    std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);
    return  now->tm_mon;
}

time_t StatisticsKeeper::getYear()
{
    std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);
    return  now->tm_year+1900;
}