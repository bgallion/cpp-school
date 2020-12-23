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

    int delim4 = strAfterDelim3.find(",");
    string emailAddress = strAfterDelim3.substr(0, delim4);
    string strAfterDelim4 = strAfterDelim3.substr(delim4 + 1, strAfterDelim3.length() - delim4);

    int delim5 = strAfterDelim4.find(",");
    int age = stoi(strAfterDelim4.substr(0, delim5));
    string strAfterDelim5 = strAfterDelim4.substr(delim5 + 1, strAfterDelim4.length() - delim5);

    int delim6 = strAfterDelim5.find(",");
    int daysInCourse1 = stoi(strAfterDelim5.substr(0, delim6));
    string strAfterDelim6 = strAfterDelim5.substr(delim6 + 1, strAfterDelim5.length() - delim6);

    int delim7 = strAfterDelim6.find(",");
    int daysInCourse2 = stoi(strAfterDelim6.substr(0, delim7));
    string strAfterDelim7 = strAfterDelim6.substr(delim7 + 1, strAfterDelim6.length() - delim7);

    int delim8 = strAfterDelim7.find(",");
    int daysInCourse3 = stoi(strAfterDelim7.substr(0, delim8));
    string strAfterDelim8 = strAfterDelim7.substr(delim8 + 1, strAfterDelim7.length() - delim8);

    int delim9 = strAfterDelim8.find(",");
    string degreeProgramStr = strAfterDelim8.substr(0, delim9);

    DegreeProgram degreeProgram;

    if (degreeProgramStr == "SECURITY") {
        degreeProgram = SECURITY;
    } else if (degreeProgramStr == "NETWORK") {
        degreeProgram = NETWORK;
    } else if (degreeProgramStr == "SOFTWARE") {
        degreeProgram = SOFTWARE;
    }


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

void Roster::remove(string studentID) {
    try
    {
        int studentIDFound = 0;
        for (int i = 0; i < numStudents; i++) {
            if (classRosterArray[i]->getStudentStudentID() == studentID) {
                for (int j = i; j < numStudents - 1; j++) {
                    classRosterArray[j] = classRosterArray[j+1];
                }
                index--;
                studentIDFound = 1;
            }
        }
        if (studentIDFound == 0) {
            throw("Student ID " + studentID + " was not found.");
        }
    }
    catch(string e)
    {
        std::cerr << e << "\n";
    }
    
}

void Roster::printAll() {
    for (int i = 0; i <= index; i++) {
        classRosterArray[i]->print();
    }
    
}