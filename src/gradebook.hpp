#pragma once
#include <string>
#include <vector>
#include <map>

class Gradebook {
private:
    struct Student {
        std::string first_name;
        std::string last_name;
        std::string id;
    };

    struct Assignment {
        std::string name;
        int total_points;
    };

    std::vector<Student> students;
    std::vector<Assignment> assignments;
    // grades[student_id][assignment_name] = grade
    std::map<std::string, std::map<std::string, int>> grades;

public:
    void add_student(const std::string &first, const std::string &last, const std::string &id);
    void add_assignment(const std::string &name, int total_points);
    void enter_grade(const std::string &student_name, const std::string &assignment_name, int grade);
    std::string report() const;
};