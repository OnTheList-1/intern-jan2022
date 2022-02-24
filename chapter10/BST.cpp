#include "BST.h"


//constructors/destructors

BST::BST()
{
    root = nullptr;
}

BST::~BST()
{
    deleteTree(root);
}

void BST::deleteTree()
{
    deleteTree(root);
}

void BST::deleteTree(Node* leaf)
{
    if (leaf != nullptr)
    {
        deleteTree(leaf->left);
        deleteTree(leaf->right);
        delete leaf;
    }
}