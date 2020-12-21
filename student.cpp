#include "student.h"

Student::Student() {
    this->studentID = "";
}

Student::Student(string studentID) {
    this->studentID = studentID;
}

string Student::getStudentStudentID() {
    return this->studentID;
}

void Student::print() {
    cout << this->getStudentStudentID() << "\n";
}