#include <iostream>
#include <string>
#include <iostream>
#include <ctime>
#include <chrono>
#include <sstream>
#include <string>


#include "StringHelper.h"

int StringHelper::string_to_int(std::string num)
{
    int number;
    number = stoi(num);
    return number;
}

float StringHelper::string_to_float(std::string num)
{
    float number;
    number = stof(num);
    return number;
}


char StringHelper::time_tToChar(time_t t)
{
    char* dt = ctime(&t);
    return *dt;
}

