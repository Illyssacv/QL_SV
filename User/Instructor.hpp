#include <iostream>
#include "Person.hpp"
using namespace std;
class Instructor : public Person
{
private:
    string instructorID;
    string department;
    string officeLocation;

public:
    Instructor(string fullName, Role role = Role::Instructor, IsActive isActive = IsActive::Active, std::chrono::system_clock::time_point birthDate, string userName, string password,
               string instructorID, string department, string officeLocation, string phoneNumber)
        : Person(fullName, role, isActive, birthDate, userName, password)
    {
        this->instructorID = instructorID;
        this->department = department;
        this->officeLocation = officeLocation;
        this->phoneNumber = phoneNumber;
    }
};