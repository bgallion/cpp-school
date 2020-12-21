#include "student.h"

Student::Student() {
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->age = 0;
    this->daysToCompleteEachCourse[0] = 0;
    this->daysToCompleteEachCourse[1] = 0;
    this->daysToCompleteEachCourse[2] = 0;
    this->degreeProgram = SECURITY;
}

Student::Student(string studentID,
            string firstName, 
            string lastName, 
            string emailAddress, 
            int age, 
            int daysToCompleteEachCourse[], 
            DegreeProgram degreeProgram) {
    this->studentID = studentID;
}

string Student::getStudentStudentID() {
    return this->studentID;
}

void Student::print() {
    cout << this->getStudentStudentID() << "\n";
}