#include <iostream>
#include <chrono>
#include "types/Role.hpp"
#include "types/IsActive.hpp"

using namespace std;
class Person
{
protected:
    string id;
    string fullName;
    string email;
    string phoneNumber;
    std::chrono::system_clock::time_point createdAt;
    std::chrono::system_clock::time_point birthDate;
    //

    //
    string userName;
    string password;
    //
    Role role;
    IsActive isActive;

public:
    Person(string fullName, Role role, IsActive isActive = IsActive::Active, std::chrono::system_clock::time_point birthDate, string userName, string password)
    {
        this->fullName = fullName;
        this->role = role;
        this->isActive = isActive;
        this->createdAt = std::chrono::system_clock::now();
        this->birthDate = birthDate;
        this->userName = userName;
        this->password = password;
    }
    string getFullName()
    {
        return fullName;
    }
    Role getRole()
    {
        return role;
    }
    IsActive getIsActive()
    {
        return isActive;
    }
};
