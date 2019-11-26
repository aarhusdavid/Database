#include "TreeNode.h"
#include "Student.h"
#include "Faculty.h"
#include <iostream>

using namespace std;

// https://stackoverflow.com/questions/10865957/printf-with-stdstring
// https://stackoverflow.com/questions/34170164/destructor-for-binary-search-tree
// https://www.geeksforgeeks.org/deleting-a-binary-tree-using-the-delete-keyword/

template <class T> class BST
{

    public:
        BST();
        ~BST();

        TreeNode<T>* search(int value);
        void insert(T* object);

        TreeNode<T> *root;

        //delete placeholder
        bool deleteNode(T* key);

        // helper function
        bool isEmpty();
        TreeNode<T>* getMin();
        TreeNode<T>* getMax();
        TreeNode<T>* getSuccessor(TreeNode<T> *d);
        void printStudentTree(); //prints whole tree
        void printFacultyTree();
        void printStudent(TreeNode<T> *node); //prints one member
        void printFaculty(TreeNode<T> *node);
        void recursiveStudentPrint(TreeNode<T> *node);
        void recursiveFacultyPrint(TreeNode<T> *node);

        int returnStudentAdv(TreeNode<T> *node); //returns advisor of student

        void DestroyRecursive(TreeNode<T> *root); //destructor method

};

template <class T> //declares template class
BST<T>::BST()
{
    root = NULL; //empty tree
}

template <class T> //declares template class
void BST<T>::DestroyRecursive(TreeNode<T> *root)
{
    if (root != NULL)
    {
        DestroyRecursive(root->left);
        DestroyRecursive(root->right);
        delete root;
    }

    cout << "Tree deleted" << endl;
}

template <class T> //declares template class
BST<T>::~BST()
{
    DestroyRecursive(root);
}

template <class T>
void BST<T>::recursiveFacultyPrint(TreeNode<T> *node)
{
    if (node == NULL)
    {
        return;
    }
    recursiveFacultyPrint(node->left);
    cout << "ID: " << node->key << endl;
    cout << "Name: " << node->value->name << endl;
    cout << "Level: " << node->value->level << endl;
    cout << "Department: " << node->value->deparment << endl;
    cout << "Advisees: " << node->value->getAdvises() << endl;
    recursiveFacultyPrint(node->right);
}

template <class T> //declares template class
void BST<T>::recursiveStudentPrint(TreeNode<T> *node)
{
    if (node == NULL)
    {
        return;
    }
    recursiveStudentPrint(node->left);
    cout << "ID: " << node->key << endl;
    cout << "Name: " << node->value->name << endl;
    cout << "Grade Level: " << node->value->grade_level << endl;
    cout << "Major: " << node->value->major << endl;
    cout << "gpa: " << node->value->gpa << endl;
    cout << "Advisor: " << node->value->advisor << endl;
    recursiveStudentPrint(node->right);
}

template <class T> //declares template class
void BST<T>::printFacultyTree()
{
    if(root == NULL)
    {
        cout << "No Faculty in Directory." << endl;
    }
    recursiveFacultyPrint(root);
}

template <class T> //declares template class
void BST<T>::printStudentTree()
{
    if(root == NULL)
    {
        cout << "No Students in Directory." << endl;
    }
    recursiveStudentPrint(root);
}



template <class T> //declares template class
void BST<T>::printFaculty(TreeNode<T> *node)
{
    cout << "ID: " << node->key << endl;
    cout << "Name: " << node->value->name << endl;
    cout << "Level: " << node->value->level << endl;
    cout << "Department: " << node->value->deparment << endl;
    cout << "Advisees: " << node->value->getAdvises() << endl;
}

template <class T> //declares template class
void BST<T>::printStudent(TreeNode<T> *node)
{
    cout << "ID: " << node->key << endl;
    cout << "Name: " << node->value->name << endl;
    cout << "Grade Level: " << node->value->grade_level << endl;
    cout << "Major: " << node->value->major << endl;
    cout << "gpa: " << node->value->gpa << endl;
    cout << "Advisor: " << node->value->advisor << endl;
}

template <class T> //declares template class
int BST<T>::returnStudentAdv(TreeNode<T> *node)
{
    return node->value->advisor;
}



template <class T> //declares template class
TreeNode<T>* BST<T>::getMax()
{
    TreeNode<T> *curr = root;
    if(root == NULL) //empty TreeNode
        return NULL;

    while(curr->right != NULL)
    {
        curr = curr->right;
    }

    return curr;
}

template <class T> //declares template class
void BST<T>::insert(T* object)
{
    int value = object->getID();
    TreeNode<T> *node = new TreeNode<T>(value, object);

    if(root == NULL)
    {
        //empty tree
        root = node;
    }
    else
    {
        //tree is not Empty, nee to find the insertion location
        TreeNode<T> *current = root;
        TreeNode<T> *parent = NULL;

        while(true)
        {
            parent  = current;
            if(value < current->key)
            {
                current = current->left;
                //going left
                if(current == NULL)
                {
                    //we found our insertion point
                    parent->left = node;
                    break;
                }
            }
            else
            {
                //go right
                current = current->right;
                if(current == NULL)
                {
                    //we found our insertion point
                    parent->right = node;
                    break;
                }
            }
        }
    }
}

template <class T> //declares template class
TreeNode<T>*  BST<T>::search(int value)
{
    TreeNode<T> *current = root;
    if(root == NULL)
    {
        return NULL;
        //empty tree
    }
    else
    {
        //tree is not empty, let's start looking for value
        while(current->key != value)
        {
            if(value < current->key)
                current = current->left;
            else
                current = current->right;

            if(current == NULL) // we did not find the value
                return NULL;
        }
    }
    return current;
}


template <class T> //declares template class
bool BST<T>::deleteNode(T* object)
{
    int value = object->getID();
    if(root == NULL)
        return false;

    TreeNode<T> *current = root;
    TreeNode<T> *parent = root;
    bool isLeft = true;

    while(current->key != value)
    {
        parent = current;
        if(value < current->key)
        {
            isLeft = true;
            current = current->left;
        }
        else
        {
            isLeft = false;
            current = current->right;

        }

        if(current == NULL) // we did not find the value
            return false;
    }

    //if we get here, then we found the node that needs to be deleted
    //now lets check our different cases
    //no children, check is node to be deleted a leaf node
    if(current->left == NULL && current->right == NULL)
    {
        if(current == root)
            root = NULL;
        else if (isLeft)
            parent->left = NULL;
        else
            parent ->right = NULL;
    }

    //node to be deleted has one child, we need to determine if child is left or right and proceed
    else if(current->right == NULL)//child has not right children
    {
        if(current == root)
        {
            root = current->left;
        }
        else if(isLeft)
        {
            parent->left = current->left;
        }
        else
        {
            parent->right = current->left;
        }
    }

    else if(current->left == NULL)//child has not left children
    {
        if(current == root)
        {
            root = current->right;
        }
        else if(isLeft)
        {
            parent->left = current->right;
        }
        else
        {
            parent->right = current->right;
        }
    }

    else //node to be deleted has two children
    {
        TreeNode<T> *successor = getSuccessor(current);
        if(current == root)
        {
            root = successor;
        }
        else if(isLeft)
        {
            parent->left = successor;
        }
        else
        {
            parent->right = successor;
        }

        successor->left = current->left;
    }

    return true;

}

template <class T> //declares template class
TreeNode<T>* BST<T>::getSuccessor(TreeNode<T> *d) //d is the node to be deleted
{
    TreeNode<T> *sp = d; //sp is successor's parent and is initialized to d
    TreeNode<T> *successor = d;
    TreeNode<T> *current = d->right; //start one right

    while(current != NULL) //one right all the way left
    {
        sp = successor;
        successor = current;
        current = current->left;
    }

    if(successor != d->right) //successor is a descendant of the right child
    {
        sp->left = successor->right;
        successor->right = d->right;
    }
    return successor;
}
