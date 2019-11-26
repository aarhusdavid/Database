#include <iostream>
#include <fstream>
#include "BST.h"

using namespace std;

extern BST<Student> *masterStudent;
extern BST<Faculty> *masterFaculty;

class FileReader
{
    public:
        FileReader();
        ~FileReader();

        void readStudent();
        void readFaculty();

        //possible functions
        void readAllStudents();
        void readAllFaculty();
        ////////////////////////

        void writeStudent();
        string getStudent(TreeNode<Student>* node);

        void writeFaculty();
        string getFaculty(TreeNode<Faculty>* node);

        string strand;
        string data;

        int r_faculty_id;
        string r_faculty_name;
        string r_faculty_level;
        string r_deparment;
        Doubly<int>* r_advises;//advisee list

        int r_student_id;
        string r_student_name;
        string r_grade_level;
        string r_major;
        double r_gpa;
        int r_advisor;

};
