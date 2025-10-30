#include <iostream>

#include "src/gradebook.hpp"

int main() {
  Gradebook gb;
  int choice;

  do {
    cout << "\n===== CSC122 Gradebook Menu =====\n";
    cout << "1. Add a student\n";
    cout << "2. Add an assignment\n";
    cout << "3. Enter a grade\n";
    cout << "4. Show report\n";
    cout << "5. Exit\n";
    cout << "Choose an option: ";
    cin >> choice;
    cin.ignore();

    if (choice == 1) {
      string first, last, id;
      cout << "Enter first name: ";
      getline(cin, first);
      cout << "Enter last name: ";
      getline(cin, last);
      cout << "Enter student ID: ";
      getline(cin, id);
      gb.add_student(first, last, id);
      cout << "Student added.\n";
    }
    else if (choice == 2) {
      string name;
      int total;
      cout << "Enter assignment name: ";
      getline(cin, name);
      cout << "Enter total points: ";
      cin >> total;
      cin.ignore();
      gb.add_assignment(name, total);
      cout << "Assignment added.\n";
    }
    else if (choice == 3) {
      string fullName, assignment;
      int grade;
      cout << "Enter student's full name (First Last): ";
      getline(cin, fullName);
      cout << "Enter assignment name: ";
      getline(cin, assignment);
      cout << "Enter grade: ";
      cin >> grade;
      cin.ignore();
      gb.enter_grade(fullName, assignment, grade);
      cout << "Grade recorded.\n";
    }
    else if (choice == 4) {
      cout << "\n===== Grade Report =====\n";
      cout << gb.report();
    }
    else if (choice == 5) {
      cout << "Exiting...\n";
    }
    else {
      cout << "Invalid option.\n";
    }
  } while (choice != 5);

  return 0;
}