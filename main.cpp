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

   Roster roster;

   for (int i = 0; i < numStudents; i++) {
      roster.parse(studentData[i]);
   }
   
   roster.printAll();

   return 0;
}