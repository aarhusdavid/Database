#include "Doubly.h"
#include <iostream>

using namespace std;

class Faculty
{
    public:
        Faculty();
        Faculty(int id, string nam, string lvl, string dpt, Doubly<int>* students);
        ~Faculty(); //when creating a template class destructor must be virtual

        //fac member variables
        int faculty_id;
        string name;
        string level;
        string deparment;
        Doubly<int>* advises;//advisee list

        //helper methods
        int getID();
        string getName();
        string getLevel();
        string getDepartment();
        string getInfo();
        string getAdvises();



};
