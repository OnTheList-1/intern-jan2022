#pragma once

class Node
{
public:
    Node* left;
    Node* right;
    int data;
};

class BST
{
public:
    BST();
    ~BST();
    void deleteTree();
    void deleteTree(Node*);


    Node* root;
};