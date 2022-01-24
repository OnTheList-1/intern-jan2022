#include <iostream>
#include <string>

#include "LinkedList.h"

int main()
{
    LinkedList<int> List1;

    List1.push_back(1);
    List1.push_back(10);
    List1.push_back(5);
    List1.push_back(19);
    List1.push_back(4);
    List1.push_front(32);

    List1.printList();

    LinkedList<int> List2;
    List2.push_back(11);
    List2.push_back(13);
    List2.push_back(5);
    List2.push_back(1);
    List2.push_back(3);

    List1.append(List2);
    List1.printList();
    //List2.~LinkedList();
    return 0;
}