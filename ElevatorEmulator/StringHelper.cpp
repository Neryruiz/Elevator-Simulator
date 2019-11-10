#include <iostream>
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