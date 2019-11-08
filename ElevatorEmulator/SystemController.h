#include <istream>
#include <string>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <iterator>



using namespace std;


#ifndef ELEVATOREMULATOR_SYSTEMCONTROLLER_H
#define ELEVATOREMULATOR_SYSTEMCONTROLLER_H


class SystemController {

public:
    /*
     * Attributes
     */
    std::string line;
    string result {};
    int counter = 1;
    map<int, vector<std::string>> Data;


public:
    /*
     * Constructor and Destructor
     */
    SystemController();
    ~SystemController();

public:
    /*
     * Methods
     */
    void readFile(std::string path);
};


#endif //ELEVATOREMULATOR_SYSTEMCONTROLLER_H
