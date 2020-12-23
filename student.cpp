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

    Student::setStudentStudentID(studentID);
    Student::setStudentFirstName(firstName);
    Student::setStudentLastName(lastName);
    Student::setStudentEmailAddress(emailAddress);
    Student::setStudentAge(age);
    Student::setStudentDaysToCompleteEachCourse(daysToCompleteEachCourse);
    Student::setStudentDegreeProgram(degreeProgram);

}

// Requirement D2 a.
// Getters
string Student::getStudentStudentID() {
    return this->studentID;
}

string Student::getStudentFirstName() {
    return this->firstName;
}

string Student::getStudentLastName() {
    return this->lastName;
}

string Student::getStudentEmailAddress() {
    return this->emailAddress;
}

int Student::getStudentAge() {
    return this->age;
}

int *Student::getStudentDaysToCompleteEachCourse() {
    return this->daysToCompleteEachCourse;
}

string Student::getStudentDegreeProgram() {
    string degreeName = degreeProgramStrings[this->degreeProgram];
    return degreeName;
}

// Requirement D2 b.
// Setters
void Student::setStudentStudentID(string studentID) {
    this->studentID = studentID;    
}

void Student::setStudentFirstName(string firstName) {
    this->firstName = firstName;
}

void Student::setStudentLastName(string lastName) {
    this->lastName = lastName;
}

void Student::setStudentEmailAddress(string emailAddress) {
    this->emailAddress = emailAddress;
}

void Student::setStudentAge(int age) {
    this->age = age;
}

void Student::setStudentDaysToCompleteEachCourse(int daysToCompleteEachCourse[]) {
    for (int i = 0; i < daysToCompleteEachCourseArraySize; i++) {
        this->daysToCompleteEachCourse[i] = daysToCompleteEachCourse[i];
    }
}

void Student::setStudentDegreeProgram(DegreeProgram degreeProgram) {
    this->degreeProgram = degreeProgram;
}

void Student::print() {
    cout << this->getStudentStudentID() << "\t";
    cout << "First Name: " << this->getStudentFirstName() << "\t";
    cout << "Last Name: " << this->getStudentLastName() << "\t";
    cout << "Age: " << this->getStudentAge() << "\t";
    cout << "daysInCourse: {" << this->getStudentDaysToCompleteEachCourse()[0] << ", ";
    cout << this->getStudentDaysToCompleteEachCourse()[1] << ", ";
    cout << this->getStudentDaysToCompleteEachCourse()[2] << "}\t";
    cout << "Degree Program: " << this->getStudentDegreeProgram() << "\n";
}