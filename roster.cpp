#include "roster.h"

void Roster::parse(string studentData) {
    int rhs = studentData.find(",");
    string studentID = studentData.substr(0, rhs);
    string firstName = "First";
    string lastName = "Last";
    string emailAddress = "first@last.com";
    int age = 21;
    int daysInCourse1 = 5;
    int daysInCourse2 = 10;
    int daysInCourse3 = 15; 
    DegreeProgram degreeProgram = SECURITY;

    add(studentID,
        firstName, 
        lastName, 
        emailAddress, 
        age, 
        daysInCourse1,
        daysInCourse2,
        daysInCourse3, 
        degreeProgram);
}

void Roster::add(string studentID,
                string firstName, 
                string lastName, 
                string emailAddress, 
                int age, 
                int daysInCourse1,
                int daysInCourse2,
                int daysInCourse3, 
                DegreeProgram degreeProgram) {
    index++;
    int daysInCourses[3] = {daysInCourse1, daysInCourse2, daysInCourse3};
    classRosterArray[index] = new Student(studentID,
                                        firstName, 
                                        lastName, 
                                        emailAddress, 
                                        age, 
                                        daysInCourses, 
                                        degreeProgram);

}

void Roster::printAll() {
    for (int i = 0; i <= index; i++) {
        classRosterArray[i]->print();
    }
    
}