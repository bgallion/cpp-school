#pragma once
#include <iostream>
#include "degree.h"
using std::string;
using std::cout;

class Student {
    public:
        const static int daysToCompleteEachCourseArraySize = 3;

    private:
        // Requirement D1.
        string studentID;
        string firstName;
        string lastName;
        string emailAddress;
        int age;
        int daysToCompleteEachCourse[daysToCompleteEachCourseArraySize];
        DegreeProgram degreeProgram;

    public:
        Student(); // Parameterless constructor for default values
        // Requirement D2 d
        Student(string studentID, 
            string firstName, 
            string lastName, 
            string emailAddress, 
            int age, 
            int daysToCompleteEachCourse[], 
            DegreeProgram degreeProgram
            ); // Full constructor
        ~Student(); // Destructor call

        // Requirement D2 a.
        // Getters
        string getStudentStudentID();
        string getStudentFirstName();
        string getStudentLastName();
        string getStudentEmailAddress();
        int getStudentAge();
        int* getStudentDaysToCompleteEachCourse();
        string getStudentDegreeProgram();

        // Requirement D2 b.
        // Setters
        void setStudentStudentID(string studentID);
        void setStudentFirstName(string firstName);
        void setStudentLastName(string lastName);
        void setStudentEmailAddress(string emailAddress);
        void setStudentAge(int age);
        void setStudentDaysToCompleteEachCourse(int daysToCompleteEachCourse[]);
        void setStudentDegreeProgram(DegreeProgram degreeProgram);

        // Requirement D2 e
        void print(); // Print specific student data

};