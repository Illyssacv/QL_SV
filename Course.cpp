#include <iostream>
#include "types/Time.hpp"
#include "types/Subject.hpp"
using namespace std;

class Course
{
private:
    string id;
    string instructorId;
    string classRoomId;
    Subject subjectName;
    int credits;
    string department;
    int capacity;
    DateTime schedule;
    int enrolledStudents;

public:
    Course(string id, string instructorId, string classRoomId, string courseName, int credits, string department, string instructor, int capacity, DateTime schedule)
    {
        this->id = id;
        this->instructorId = instructorId;
        this->classRoomId = classRoomId;
        this->subjectName = subjectName;
        this->credits = credits;
        this->department = department;
        this->capacity = capacity;
        this->schedule = schedule;
        this->enrolledStudents = 0;
    }
};