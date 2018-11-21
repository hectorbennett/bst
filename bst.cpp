#include <iostream>
#include <cstdlib>

#include "bst.h"

BST::BST()
{
    root = NULL;
}

BST::node* BST::CreateLeaf(int key)
{
    node* n = new node;
    n->key = key;
    n->left = NULL;
    n->right = NULL;

    return n;
}

void BST::AddLeaf(int key)
{
    AddLeafPrivate(key, root);
}

void BST::AddLeafPrivate(int key, node* Ptr)
{
    if (root == NULL)
    {
        root = CreateLeaf(key);
    }
    else if (key < Ptr->key)
    {
        if (Ptr->left != NULL)
        {
            AddLeafPrivate(key, Ptr->left);
        }
        else
        {
            Ptr->left = CreateLeaf(key);
        }
    }
    else if (key > Ptr->key)
    {
        if (Ptr->right != NULL)
        {
            AddLeafPrivate(key, Ptr->right);
        }
        else
        {
            Ptr->right = CreateLeaf(key);
        }
    }
    else
    {
        std::cout << "The key " << key << " has already been added to the tree" << std::endl;
    }
}

void BST::PrintInOrder()
{
    PrintInOrderPrivate(root);
}

void BST::PrintInOrderPrivate(node* Ptr)
{
    if (root != NULL)
    {
        if (Ptr->left != NULL)
        {
            PrintInOrderPrivate(Ptr->left);
        }
        std::cout << Ptr->key << " ";
        if (Ptr->right != NULL)
        {
            PrintInOrderPrivate(Ptr->right);
        }
    }
    else
    {
        std::cout << "The tree is empty" << std::endl;
    }
}

BST::node* BST::ReturnNode(int key)
{
    return ReturnNodePrivate(key, root);
}

BST::node* BST::ReturnNodePrivate(int key, node* Ptr)
{
    if (Ptr != NULL)
    {
        if (Ptr->key == key)
        {
            return Ptr;
        }
        else
        {
            if (key < Ptr->key)
            {
                return ReturnNodePrivate(key, Ptr->left);
            }
            else if (key > Ptr->key)
            {
                return ReturnNodePrivate(key, Ptr->right);
            }
        }
    }
    return NULL;
}

int BST::ReturnRootKey ()
{
    if (root != NULL) {
        return root->key;
    }
    return -1000;
}

void BST::PrintChildren(int key)
{
    node* Ptr = ReturnNode(key);

    if (Ptr != NULL)
    {
        std::cout << "Parent node = " << Ptr->key << std::endl;

        Ptr->left == NULL ?
        std::cout << "Left Child = NULL" << std::endl :
        std::cout << "Left Child = " << Ptr->left->key << std::endl;

        Ptr->right == NULL ?
        std::cout << "Right Child = NULL" << std::endl :
        std::cout << "Right Child = " << Ptr->right->key << std::endl;
    }
    else
    {
        std::cout << "Key " << key << " is not in the tree" << std::endl;
    }
}

int BST::FindSmallest()
{
    return FindSmallestPrivate(root);
}

int BST::FindSmallestPrivate(node* Ptr)
{
    if (root == NULL) {
        std::cout << "The tree is empty" << std::endl;
        return -1000;
    }
    else
    {
        if (Ptr->left != NULL)
        {
            return FindSmallestPrivate(Ptr->left);
        }
        else {
            return Ptr->key;
        }
    }
}
