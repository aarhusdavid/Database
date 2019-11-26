#include "FileReader.h"
#include <iostream>
#include <string>

using namespace std;

BST<Faculty>* masterFaculty = new BST<Faculty>; //student tree
BST<Student>* masterStudent = new BST<Student>; //faculty tree

int main(int argc, char** argv)
{
    FileReader fr; //creates filereader object

    fr.readStudent(); //reads student txt file to tree
    fr.readFaculty(); //reads fac txt file to tree

    //new student variables
    string newSname;
    string newSgrade_level;
    string newSmajor;
    int student_id;
    double gpa;
    int advisor;

    //new fac member variables
    int faculty_id;
    string newFname;
    string newFlevel;
    string deparment;
    Doubly<int>* advises;//advisee list

    //instances for deleting students and fac members
    Student *stud;
    int dsid;
    Faculty *fac;
    int dfid;

    bool menu = true;
    while(menu == true)
    {
        cout << "Welcome to the Chapman Student/Faculty Database" << endl;
        cout << "--------------------------------------------------------------------------" << endl;
        cout << "1. Print all students and their information (sorted by ascending id #)." << endl;
        cout << "2. Print all faculty and their information (sorted by ascending id #)." << endl;
        cout << "3. Find and display student information given the students id." << endl;
        cout << "4. Find and display faculty information given the faculty id." << endl;
        cout << "5. Given a student’s id, print the name and info of their faculty advisor." << endl;
        cout << "6. Given a faculty id, print ALL the names and info of his/her advisees." << endl;
        cout << "7. Add a new student." << endl;
        cout << "8. Delete a student given the id." << endl;
        cout << "9. Add a new faculty member." << endl;
        cout << "10. Delete a faculty member given the id." << endl;
        cout << "11. Change a student’s advisor given the student id and the new faculty id." << endl;
        cout << "12. Remove an advisee from a faculty member given the ids." << endl;
        cout << "13. Rollback." << endl;
        cout << "14. Exit." << endl;
        cout << "Enter the number of your choice: ";
        int choice;
        cin >> choice;

        //cin.get(trash) after reading ID in order to ignore the extra \n
        //getline(cin, name) allows you to enter first and last names

        switch (choice)
        {
            case 1:
                masterStudent->printStudentTree();
                break;
            case 2:
                masterFaculty->printFacultyTree();
                break;
            case 3:
                cout << endl;
                cout << "What is the Students ID number: ";
                int sid;
                cin >> sid;
                masterStudent->printStudent(masterStudent->search(sid));
                break;
            case 4:
                cout << endl;
                cout << "What is the Facultys ID number: ";
                int fid;
                cin >> fid;
                masterFaculty->printFaculty(masterFaculty->search(fid));
                break;
            case 5:
                cout << endl;
                cout << "What is the Students ID number: ";
                int ssid;
                cin >> ssid;
                masterFaculty->printFaculty(masterFaculty->search(masterStudent->returnStudentAdv(masterStudent->search(ssid))));
                break;
            case 6:
                // cout << endl;
                // cout << "What is the Facultys ID number: ";
                // int ffid;
                // cin >> ffid;
                break;
            case 7:
                cout << endl;
                cout << "Please enter the information for the new Student." << endl;
                cout << "Student ID: ";
                cin >> student_id;
                cout << endl;
                cout << "Name: ";
                cin >> newSname;
                cout << endl;
                cout << "Grade Level: ";
                cin >> newSgrade_level;
                cout << endl;
                cout << "Major: ";
                cin >> newSmajor;
                cout << endl;
                cout << "GPA: ";
                cin >> gpa;
                cout << endl;
                cout << "Advisor ID: ";
                cin >> advisor;
                break;
            case 8:
                cout << endl;
                cout << "What is the ID number of the student you would like to delete: ";
                cin >> dsid;
                stud = masterStudent->search(dsid)->value;
                if(masterStudent->deleteNode(stud))
                {
                    if(masterFaculty->search(stud->advisor)->value->advises->remove(dsid))
                    {
                        cout << "Student was removed." << endl;
                    }
                    else
                    {
                        cout << "There was an error removing the student" << endl;
                    }
                }
                break;
            case 9:
                cout << endl;
                cout << "Please enter the information for the new Faculty." << endl;
                cout << "Faculty ID: ";
                cin >> faculty_id;
                cout << endl;
                cout << "Name: ";
                cin >> newFname;
                cout << endl;
                cout << "Level: ";
                cin >> newFlevel;
                cout << endl;
                cout << "Department: ";
                cin >> deparment;
                cout << endl;
                break;
            case 10:
                cout << endl;
                cout << "What is the ID number of the student you would like to delete: ";
                cin >> dfid;
                fac = masterFaculty->search(dfid)->value;
                if(masterFaculty->deleteNode(fac))
                {
                    cout << "Faculty member was removed." << endl;
                }
                else
                {
                    cout << "There was an error removing the Faculty member." << endl;
                }
                while(!fac->advises->isEmpty())
                {
                    dsid = fac->advises->removeFront();
                    masterStudent->search(dsid)->value->advisor = 0;
                }
                break;
            case 11:
                break;
            case 12:
                break;
            case 13:
                break;
            case 14:
                exit(0);
                break;

        }


        if(newSname != "") //if new name variable is empty user did not add new student
        {
            Student *newStudent = new Student(student_id, newSname, newSgrade_level, newSmajor, gpa, advisor);
            masterStudent->insert(newStudent);
        }
        if(newFname != "") //if new name variable for a new fac member is empty user did not add new fac member
        {
            Faculty *newFaculty = new Faculty(faculty_id, newFname, newFlevel, deparment, advises);
            masterFaculty->insert(newFaculty);
        }
    }
    return 0;
}
