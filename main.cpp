#include "roster.h"

int main() {

   const string studentData[] = {
      "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
      "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
      "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
      "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
      "A5,Bruce,Gallion,bgalli5@wgu.edu,32,30,37,44,SOFTWARE"
   };

   const int numStudents = 5;

   cout << "Header:\n";
   cout << "Scripting and Programming - Applications – C867\t";
   cout << "Langauge used: C++\t" << "Student ID: 001457055\t" << "Name: Bruce Gallion\n";

   Roster classRoster;

   for (int i = 0; i < numStudents; i++) {
      classRoster.parse(studentData[i]);
   }

   cout << "Print all:\n";
   classRoster.printAll();

   cout << "Print invalid email addresses:\n";
   classRoster.printInvalidEmails();

   cout << "Print average days in course:\n";
   for (int i = 0; i <= classRoster.index; i++) {
      string studentID = classRoster.classRosterArray[i]->getStudentStudentID();
      classRoster.printAverageDaysInCourse(studentID);
   }
   
   cout << "Print by degree program SOFTWARE:\n";
   classRoster.printByDegreeProgram(SOFTWARE);

   cout << "Remove A3:\n";
   classRoster.remove("A3");

   cout << "Print all:\n";
   classRoster.printAll();

   cout << "Remove A3:\n";
   classRoster.remove("A3");

   classRoster.~Roster();

   return 0;
}