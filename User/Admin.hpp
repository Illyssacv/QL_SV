#include <iostream>
#include "Person.hpp"
#include "types/Role.hpp"
#include "types/IsActive.hpp"
using namespace std;
class Admin : public Person
{
public:
    Admin(string fullName, Role role = Role::Admin, IsActive isActive = IsActive::Active, std::chrono::system_clock::time_point birthDate, string userName, string password)
        : Person(fullName, role, isActive, birthDate, userName, password)
    {
    }
};