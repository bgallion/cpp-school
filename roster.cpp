#include "roster.h"

void Roster::parse(string studentData) {
    int delim1 = studentData.find(",");
    string studentID = studentData.substr(0, delim1);
    string strAfterDelim1 = studentData.substr(delim1 + 1, studentData.length() - delim1);

    int delim2 = strAfterDelim1.find(",");
    string firstName = strAfterDelim1.substr(0, delim2);
    string strAfterDelim2 = strAfterDelim1.substr(delim2 + 1, strAfterDelim1.length() - delim2);

    int delim3 = strAfterDelim2.find(",");
    string lastName = strAfterDelim2.substr(0, delim3);
    string strAfterDelim3 = strAfterDelim2.substr(delim3 + 1, strAfterDelim2.length() - delim3);
    
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