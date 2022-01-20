
#include "LinkedList.h"

LinkedList::LinkedList()
{
    head = nullptr;
}

LinkedList::~LinkedList()
{
    Node* n = head;
    Node* current = nullptr;
    while (n)
    {
        current = n;
        n = n->nextPtr;
        delete(current);
    }
}