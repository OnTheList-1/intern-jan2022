#pragma once

struct Node
{
    Node* nextPtr;
    Node* prevPtr;
    int data;
};

class LinkedList
{
public:
    LinkedList();
    ~LinkedList();

private:
    Node* head;
};