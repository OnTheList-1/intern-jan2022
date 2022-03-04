#pragma once

template <typename T>
struct Node
{
    Node<T>* next;
    T data;
};

template <typename T>
class LinkedList
{
public:
    LinkedList();

private:
    Node<T>* head;
    Node<T>* tail;
};