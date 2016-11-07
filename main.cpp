#include <iostream>
//#include "download.h"
//#include "curving.h"
#include <fstream>
#include "student.h"
using namespace std;

/* I try to find something that teach how to build a GUI in QT and I found a link below:
 *
http://www.bogotobogo.com/cplusplus/files/c-gui-programming-with-qt-4-2ndedition.pdf

And this is the tutorial for QT4 but I think it still help us to construct a GUI.
I will keep looking and update new files if I find a better one.
Cheers!

/* ASSUMPTION: Data is in .txt file
 * data in .txt is in the format
       assignmenttype(int )indicates whether assignment is a Test or a homework
       student_ID     Marks
       student_ID     Marks
  * TODO: make number of students and number of assignments dynamic
*/


const int NUM_STUDENTS = 10;
int main() {
    int count=0;
    Student s[NUM_STUDENTS];
    //Assignment a[NUM_ASSIGNMENTS]; //TODO
    //for(int k=0; k< NUM_ASSIGNMENTS; k++) {
    ifstream filename("a1.txt");
    if(filename.is_open()){
        for(int k=1;k<=NUM_ASSIGNMENTS;k++){  //NUM_ASSIGNMENTS (for now took it as 2 )is a constant in student.h
            count=0;
            int assignmentType;
            filename>>assignmentType;
            Student::SetAssignmentType(assignmentType);
            if(Student::GetAssignment_type() == 1)
                Student::Set_numAssignments();
            else if(Student::GetAssignment_type() == 2)
                Student::Set_numTests();
            for(int i=0;i<NUM_STUDENTS;i++){

                int id = 0;
                double marks = 0.0;
                filename >> id;
                filename >> marks;
                if (k==1){
                    //First assignment, no data in student objects yet
                    //Assign directly without any checks
                    s[i].Setstudent_id(id);
                    s[i].Set_Marks(k-1,marks);
                    s[i].allAssignments_avg();
                }
                else{
                    for(int j=0; j<NUM_STUDENTS; j++){
                        /*student id's for each assignment will not be in the same
                          order, so check before assigning*/
                        if(s[j].Getstudent_id() == id){
                            s[j].Set_Marks(k-1,marks);
                            s[j].allAssignments_avg();
                        }
                    }
                }
                count++;
            }
            filename.close();
            filename.open("a2.txt");
            if(filename.is_open()){

            }
            else {
               cout<<"not open";
            }
        }
    }
    else
        cout<<"not open";
    cout<<s[0].allAssignments_avg()<<'\n'<<s[1].allAssignments_avg()<<'\n';
    cout<<s[2].allAssignments_avg()<<'\n'<<s[3].allAssignments_avg()<<'\n';
    return 0;
}
