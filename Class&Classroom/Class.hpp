#include <iostream>
#include "types/Major.hpp"
using namespace std;
class Class
{
private:
    string id;
    string className;
    string instructorID;
    Major major;
    string schoolYear;

    int capacity;

public:
    Class(string id, string className, Major major, string schoolYear, int capacity)
    {
        this->id = id;
        this->className = className;
        this->major = major;
        this->schoolYear = schoolYear;
        this->capacity = capacity;
    }
};