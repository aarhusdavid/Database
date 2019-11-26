#include "Faculty.h"
#include <iostream>

using namespace std;

Faculty::Faculty()
{

}

Faculty::Faculty(int id, string nam, string lvl, string dpt, Doubly<int>* students)
{
    this->faculty_id = id;
    this->name = nam;
    this->level = lvl;
    this->deparment = dpt;
    this->advises = students;
}

Faculty::~Faculty()
{
    delete this->advises;
}

int Faculty::getID()
{
    return this->faculty_id;
}

string Faculty::getName()
{
    return this->name;
}

string Faculty::getLevel()
{
    return this->level;
}

string Faculty::getDepartment()
{
    return this->deparment;
}

string Faculty::getInfo()
{
    return to_string(faculty_id) + "\n" + name + "\n" + level + "\n" + deparment;
}

string Faculty::getAdvises()
{
    string list;
    DoublyNode<int> *node = this->advises->front;
    list += "[";
    while (node != NULL)
    {
        list+= to_string(node->data);
        if(node->next != NULL)
        {
            list += ",";
        }
        node = node->next;
    }
    list += "]";
    return list;
}
