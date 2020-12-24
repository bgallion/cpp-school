#include "roster.h"

Roster::Roster() {

}

Roster::~Roster() {

}

void Roster::parse(string studentData) {
    /*
        Go through the string and find each instance of the delimeter.
        Take the values between the delimeters along the way and assign them to the variables.
    */

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
    // stoi() converts string value to int.
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

    // Case statement for the program string. Find a match and assign the enum.
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
        // Variable to track whether we find a match or not for the studentID.
        int studentIDFound = 0;

        // Loop through the class roster and look for a match.
        for (int i = 0; i <= index; i++) {
            if (classRosterArray[i]->getStudentStudentID() == studentID) {
                // A match was found. Replace this element in the array with the next element and continue forward.
                for (int j = i; j < index; j++) {
                    classRosterArray[j] = classRosterArray[j+1];
                }
                studentIDFound = 1;
                // Student ID was found and removed.
                index--;
            }
        }

        // If the studentID was not found, throw an error.
        if (studentIDFound == 0) {
            throw("Student ID " + studentID + " was not found.");
        } 
    }
    catch(string e)
    {
        std::cerr << e << "\n";
    } 
}

void Roster::printAverageDaysInCourse(string studentID) {
    try
    {
        // Variable to track whether we find a match or not for the studentID.
        int studentIDFound = 0;

        for (int i = 0; i <= index; i++) {
            if (classRosterArray[i]->getStudentStudentID() == studentID) {
                int sumOfDays = 0;
                int numOfCourses = classRosterArray[i]->daysToCompleteEachCourseArraySize;
                for (int j = 0; j < numOfCourses; j++) {
                    int days = classRosterArray[i]->getStudentDaysToCompleteEachCourse()[j];
                    sumOfDays += days;
                }
                double average = sumOfDays / numOfCourses;
                cout << average << "\n";
                studentIDFound = 1;
            }
        }

        // If the studentID was not found, throw an error.
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

void Roster::printInvalidEmails() {
    // Loop through the class roster and search for invalid email strings.
    for (int i = 0; i <= index; i++) {
        string emailAddress = classRosterArray[i]->getStudentEmailAddress();
        int atSign = emailAddress.find("@");
        int period = emailAddress.find(".");
        int space = emailAddress.find(" ");

        // If the email address is missing an "@" OR missing a "." OR has a space.
        if (atSign < 0 || period < 0 || space >= 0) {
            cout << emailAddress << "\n";
        }
    }
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    // Loop through the class roster and search for matching degree programs.
    for (int i = 0; i <= index; i++) {
        if (degreeProgram == classRosterArray[i]->getStudentDegreeProgram()) {
            classRosterArray[i]->print();
        }
    }
}