#include <iostream>
#include "types/ClassRoomType.hpp"
using namespace std;
class ClassRoom
{
private:
    string id;
    string className;
    int capacity;
    bool isAvailable;
    ClassRoomType type;
};