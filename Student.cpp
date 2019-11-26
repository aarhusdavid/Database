#include "Student.h"
#include <iostream>

using namespace std;

Student::Student()
{

}

Student::Student(int student_id, string name, string grade_level, string major, double gpa, int advisor)
{
    this->student_id = student_id;
    this->name = name;
    this->grade_level = grade_level;
    this->major = major;
    this->gpa = gpa;
    this->advisor = advisor;
}


Student::~Student()
{
    
}

int Student::getID()
{
    return this->student_id;
}

string Student::getName()
{
    return this->name;
}

string Student::getGradelevel()
{
    return this->grade_level;
}

string Student::getMajor()
{
    return this->major;
}

double Student::getGpa()
{
    return this->gpa;
}

int Student::getAdvisor()
{
    return this->advisor;
}

string Student::getInfo()
{
    return to_string(student_id) + "\n" + name + "\n" + grade_level + "\n" + major + "\n" + to_string(gpa) + "\n" + to_string(advisor);

}
