#include "roster.h"

void Roster::parse(string studentData) {
    int rhs = studentData.find(",");
    string studentID = studentData.substr(0, rhs);

    add(studentID);
}

void Roster::add(string studentID) {
    index++;
    classRosterArray[index] = new Student(studentID);

}

void Roster::printAll() {
    for (int i = 0; i <= index; i++) {
        classRosterArray[i]->print();
    }
    
}