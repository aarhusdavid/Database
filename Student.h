#include <iostream>

using namespace std;

class Student
{
    public:
        Student(); //empty const
        Student(int student_id, string name, string grade_level, string major, double gpa, int advisor);
        ~Student(); //when creating a template class destructor must me virtual

        //student variables
        int student_id;
        string name;
        string grade_level;
        string major;
        double gpa;
        int advisor;

        //helper methods
        string getInfo();
        int getID();
        string getName();
        string getGradelevel();
        string getMajor();
        double getGpa();
        int getAdvisor();



};
