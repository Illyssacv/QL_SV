#include <iostream>
#include <vector>
#include "Person.hpp"
#include "types/Grade.hpp"
#include "types/Major.hpp"
#include "types/Role.hpp"
#include "types/IsActive.hpp"
#include <map>
#include "types/Subject.hpp"
using namespace std;
class Student : public Person
{
private:
    std::string id;
    Major major;
    std::string classId;
    std::string schoolYear;
    //
    std::vector<std::string> requiredCourses;
    std::vector<std::string> coursesCompleted;
    std::vector<std::string> coursesInProgress;
    std::vector<std::string> coursesFailed;
    //
    int totalCredits;
    int completedCredits;
    int failedCredits;
    long long totalTuition;
    long long paidTuition;
    //
    float gpa;
    float progressScore;
    float participationScore;
    map<Subject, float> subjectScores;

    Grade grade;

public:
    Student(string fullName, Role role = Role::Student, IsActive isActive = IsActive::Active, std::chrono::system_clock::time_point birthDate, string userName, string password,
            string id, Major major, string classId, string schoolYear)
        : Person(fullName, role, isActive, birthDate, userName, password)
    {
        this->id = id;
        this->major = major;
        this->classId = classId;
        this->schoolYear = schoolYear;
        this->totalCredits = 0;
        this->completedCredits = 0;
        this->failedCredits = 0;
        this->totalTuition = 0;
        this->paidTuition = 0;
        this->gpa = 0.0f;
        this->progressScore = 0.0f;
        this->participationScore = 0.0f;
    }
};