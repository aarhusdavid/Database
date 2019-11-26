#include "FileReader.h"
#include <iostream>
#include <fstream>

using namespace std;

FileReader::FileReader()
{

}

FileReader::~FileReader()
{

}

void FileReader::readStudent()
{
    ifstream infile;
    infile.open("studentTable.txt");
    if(infile.fail())
    {
        return;
    }
    while(infile.peek() != EOF)
    {
        int count = 0;
        getline(infile,strand);
        data = "";
        for(int i = 0; i < strand.size(); ++i)
        {
            ++count;
            if(strand[i] == ',')
            {
                break;
            }
            data += strand[i];
        }
        r_student_id = stoi(data);

        data = "";
        for(int i = count; i < strand.size(); ++i)
        {
            ++count;
            if(strand[i] == ',')
            {
                break;
            }
            data+=strand[i];
        }
        r_student_name = data;

        data = "";
        for(int i = count; i < strand.size(); ++i)
        {
            ++count;
            if(strand[i] == ',')
            {
                break;
            }
            data += strand[i];
        }
        r_grade_level = data;

        data = "";
        for(int i = count; i < strand.size(); ++i) //Reads the student major
        {
            ++count;
            if(strand[i] == ',')
            {
                break;
            }
            data += strand[i];
        }
        r_major = data;

        data = "";
        for(int i = count; i < strand.size(); ++i) //Reads the student gpa
        {
            ++count;
            if(strand[i] == ',')
            {
                break;
            }
            data += strand[i];
        }
        r_gpa = stod(data);

        data = "";
        for(int i = count; i < strand.size(); ++i) //Reads the advisor's ID
        {
            ++count;
            if(strand[i] == ',')
            {
                break;
            }
            data += strand[i];
        }
        r_advisor = stoi(data);

        masterStudent->insert(new Student(r_student_id, r_student_name, r_grade_level, r_major, r_gpa, r_advisor));

    }
    infile.close();
}

void FileReader::readFaculty()
{
    ifstream infile;
    infile.open("facultyTable.txt");
    if(infile.fail())
    {
        return;
    }
    while(infile.peek() != EOF)
    {
        int count = 0;
        getline(infile,strand);

        data = "";
        for(int i = 0; i < strand.size(); ++i)//reads the faculty ID
        {
            ++count;
            if(strand[i] == ',')
            {
                break;
            }
            data += strand[i];
        }
        r_faculty_id = stoi(data);

        data = "";
        for(int i = count; i < strand.size(); ++i) //Reads the faculty member's name
        {
            ++count;
            if(strand[i] == ',')
            {
                break;
            }
            data += strand[i];
        }
        r_faculty_name = data;

        data = "";
        for(int i = count; i < strand.size(); ++i) //Reads the faculty member's level
        {
            ++count;
            if(strand[i] == ',')
            {
                break;
            }
            data += strand[i];
        }
        r_faculty_level = data;

        data = "";
        for(int i = count; i < strand.size() ; ++i) //Reads the faculty member's department
        {
            ++count;
            if(strand[i] == ',')
            {
                break;
            }
            data += strand[i];
        }
        r_deparment = data;


        r_advises = new Doubly<int>();
        data = "";
        for(int i = count + 1; i < strand.size(); ++i) //Reads the list of advisees, count is "count + 1" to ignore the open bracket
        {
            if(strand[i] == ']')
            {
                r_advises->insertBack(stoi(data));
                break;
            }
            if(strand[i] == ',')
            {
                r_advises->insertBack(stoi(data));
                data = "";
            }
            else
            {
                data+=strand[i];
            }

        }

        masterFaculty->insert(new Faculty(r_faculty_id, r_faculty_name, r_faculty_level, r_deparment, r_advises));

    }

    infile.close();
}

void FileReader::writeStudent()
{
    ofstream outfile;
    outfile.open("studentTable.txt");
    TreeNode<Student>* current = masterStudent->root;

    while(true)
    {
        outfile << getStudent(current) << endl;
        Student* s = current->value;
        masterStudent->deleteNode(s);
        current = masterStudent->root;
        if(current == NULL)
        {
            break;
        }
    }
}

string FileReader::getStudent(TreeNode<Student>* node)
{
    r_student_id = node->value->getID();
    r_student_name = node->value->getName();
    r_grade_level = node->value->getGradelevel();
    r_major = node->value->getMajor();
    r_gpa = node->value->getGpa();
    r_advisor = node->value->getAdvisor();

    return(to_string(r_student_id) + "," + r_student_name + "," + r_grade_level + "," + r_major + "," + to_string(r_gpa) + "," + to_string(r_advisor));
}

void FileReader::writeFaculty()
{
    ofstream outfile;
    outfile.open("facultyTable.txt");
    TreeNode<Faculty>* current = masterFaculty->root;

    while(true)
    {
        outfile << getFaculty(current) << endl;
        Faculty* f = current->value;
        masterFaculty->deleteNode(f);
        current = masterFaculty->root;
        if(current == NULL)
            break;
    }
}

string FileReader::getFaculty(TreeNode<Faculty> * node)
{
    r_faculty_id = node->value->getID();
    r_faculty_name = node->value->getName();
    r_faculty_level = node->value->getLevel();
    r_deparment = node->value->getDepartment();
    string advisees = node->value->getAdvises();//advisee list

    return (to_string(r_faculty_id) + "," + r_faculty_name + "," + r_faculty_level + "," + r_deparment + "," + advisees);
}
