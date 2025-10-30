#pragma once
#include <string>
#include <vector>
#include <map>

using namespace std;

struct Student {
    string firstName;
    string lastName;
    string studentID;
};

struct Assignment {
    string name;
    int totalPoints;
};

class Gradebook {
private:
    vector<Student> students;
    vector<Assignment> assignments;
    map<string, map<string, int>> grades; // studentID -> (assignmentName -> grade)
public:
    void add_student(const string& firstName, const string& lastName, const string& id);
    void add_assignment(const string& name, int totalPoints);
    void enter_grade(const string& studentFullName, const string& assignmentName, int grade);
    string report() const;
};
