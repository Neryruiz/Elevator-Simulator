#include <iostream>
#include <ctime>
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
    std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);
    return  now->tm_mon;
}

time_t DateTime::getDate()
{
    std::cout <<"Yet to Implement " <<endl;
}

time_t DateTime::getDateTime()
{
    std::time_t t = std::time(0);   // get time now
    std::tm* now6 = std::localtime(&t);
    return  t;
}