#include "gradebook.hpp"
#include <iostream>
#include <sstream>

using namespace std;

void Gradebook::add_student(const string& firstName, const string& lastName, const string& id) {
   students.push_back({firstName, lastName, id});
}

void Gradebook::add_assignment(const string& name, int totalPoints) {
   assignments.push_back({name, totalPoints});
}

void Gradebook::enter_grade(const string& studentFullName, const string& assignmentName, int grade) {
   for (const auto& s : students) {
      string full = s.firstName + " " + s.lastName;
      if (full == studentFullName) {
         grades[s.studentID][assignmentName] = grade;
         return;
      }
   }
   cout << "Student not found: " << studentFullName << endl;
}

string Gradebook::report() const {
   stringstream ss;
   ss << "Last_Name,First_Name,Student_Id";
   for (const auto& a : assignments)
      ss << "," << a.name;
   ss << "\n";

   for (const auto& s : students) {
      ss << s.lastName << "," << s.firstName << "," << s.studentID;
      for (const auto& a : assignments) {
         auto it = grades.find(s.studentID);
         if (it != grades.end() && it->second.find(a.name) != it->second.end()) {
            ss << "," << it->second.at(a.name);
         } else {
            ss << ",none";
         }
      }
      ss << "\n";
   }
   return ss.str();
}
