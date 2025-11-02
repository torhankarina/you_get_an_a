#include "gradebook.hpp"
#include <sstream>
#include <iomanip>
#include <iostream>

void Gradebook::add_student(const std::string &first, const std::string &last, const std::string &id) {
   students.push_back({first, last, id});
}

void Gradebook::add_assignment(const std::string &name, int total_points) {
   assignments.push_back({name, total_points});
}

void Gradebook::enter_grade(const std::string &student_name, const std::string &assignment_name, int grade) {
   // Find student by "First Last"
   for (auto &s : students) {
      std::string full_name = s.first_name + " " + s.last_name;
      if (full_name == student_name) {
         grades[s.id][assignment_name] = grade;
         return;
      }
   }
   std::cout << "Student " << student_name << " not found!\n";
}

std::string Gradebook::report() const {
   std::ostringstream out;
   out << "Last_Name,First_Name,Student_Id";

   for (auto &a : assignments)
      out << "," << a.name;
   out << "\n";

   for (auto &s : students) {
      out << s.last_name << "," << s.first_name << "," << s.id;
      for (auto &a : assignments) {
         auto student_it = grades.find(s.id);
         if (student_it != grades.end() && student_it->second.count(a.name))
            out << "," << student_it->second.at(a.name);
         else
            out << ",none";
      }
      out << "\n";
   }

   return out.str();
}