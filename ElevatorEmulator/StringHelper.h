#include <iostream>
#include <string>

#ifndef ELEVATOREMULATOR_STRINGHELPER_H
#define ELEVATOREMULATOR_STRINGHELPER_H

using namespace std;

class StringHelper {

public:
    static int string_to_int(std::string num);
    static float string_to_float(std::string num);
    static char time_tToChar(time_t t);

};


#endif //ELEVATOREMULATOR_STRINGHELPER_H
