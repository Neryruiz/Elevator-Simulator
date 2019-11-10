#include <iostream>
#include <cmath>


#include "Probablity.h"
#include "StringHelper.h"

int Probablity::roundoff(string probablity, string num)
{
    float prob = StringHelper::string_to_float(probablity);
    float n =  StringHelper::string_to_float(num);

    int result = round(n * prob);
    return result;

}
