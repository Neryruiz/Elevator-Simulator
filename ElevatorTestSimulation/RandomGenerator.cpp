#include <iostream>
#include <istream>
#include <string>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <iterator>
#include <random>
#include <ctime>

using namespace std;

#include "RandomGenerator.h"



RandomGenerator::RandomGenerator()
{
    cout  << "Random Generator" << endl;
}

RandomGenerator::~RandomGenerator()
{
    cout << "Destructor called " << endl;
}

int RandomGenerator::generateRandomNumber(int low, int high){

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(low,high);
    return dist6(rng);
}
