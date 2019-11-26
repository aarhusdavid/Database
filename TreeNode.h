#include <iostream>

using namespace std;

template <class T> class TreeNode
{
    public:
        TreeNode();
        TreeNode(int id, T* object); //k = key, which in this example is also the value(data)
        ~TreeNode(); //when creating a template class destructor must me virtual

        int key;
        T* value;
        TreeNode *left;
        TreeNode *right;


};

template <class T> //declares template class
TreeNode<T>::TreeNode()
{
    key = nullptr;
    left = nullptr;
    right = nullptr;
}

template <class T> //declares template class
TreeNode<T>::TreeNode(int id, T* object)
{
    key = id;
    value = object;
    left = nullptr;
    right = nullptr;
}

template <class T> //declares template class
TreeNode<T>::~TreeNode()
{
    left = nullptr;
    right = nullptr;
}
