#include <iostream>
#include <chrono>
#include "Role.cpp"
#include "IsActive.cpp"

using namespace std;
class Person
{
protected:
    string id;
    string fullName;
    string email;
    std::chrono::system_clock::time_point createdAt;
    std::chrono::system_clock::time_point birthDate;

    //
    Role role;
    IsActive isActive;
    string userName;
    string password;

public:
    Person(string fullName, Role role, IsActive isActive, std::chrono::system_clock::time_point birthDate, string userName, string password)
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
