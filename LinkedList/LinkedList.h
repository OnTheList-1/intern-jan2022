#pragma once

// class
template <typename T>
class Node
{
public:

    Node<T>* nextPtr;
    T value;
};

template <typename T>
class LinkedList
{
public:
    //constructors & destructors
    LinkedList();
    ~LinkedList();
    LinkedList(const LinkedList&);

    //create new Node
    Node<T>* makeNewNode(const T&);

    //insert
    void push_back(const int&);
    void push_front(const int&);
    void insertFront(Node<T>*, Node<T>*);
    void insertBack(Node<T>*, Node<T>*);
    void append(const LinkedList<T>&); //hmm

    //overloading operator
    LinkedList<T>* operator->() { return this; };

    //setters & getters
    Node<T>* getNode(const T&);
    T getSmallestNum();
    T getBiggestNum();
    Node<T>* getHead() const;
    Node<T>* getTail() const;

    void printList();

    //int functions
    int countNode();

    //bool functions
    bool isEmpty();

    //void
    void pop();
    void sort();
    void sortDescending();

private:
    Node<T>* head;
    Node<T>* tail;
};


//constructors

template <typename T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
    tail = nullptr;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    Node<T>* temp = head;
    while (head != nullptr)
    {
        temp = head->nextPtr;
        delete head;
        head = temp;
    }
    delete temp;

}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& copy)
{
    Node<T>* current = copy.getHead();

    if (current == nullptr)
    {
        head = nullptr;
        tail = nullptr;

    }
    else
    {
        head = new Node<T>;
        head->value = current->value;
        Node<T>* node = head;
        node = node->nextPtr;

        while (current->nextPtr != nullptr)
        {
            node = new Node<T>;
            node->value = current->value;
            node = node->nextPtr;
            current = current->nextPtr;
        }
        tail = new Node<T>;
        tail->value = current->value;
        tail->nextPtr = nullptr;

    }

}

template <typename T>
Node<T>* LinkedList<T>::getHead() const
{
    return head;
}

template <typename T>
Node<T>* LinkedList<T>::getTail() const
{
    return tail;
}

template <typename T>
void LinkedList<T>::push_back(const int& val)
{
    Node<T>* newNode = new Node<T>;
    newNode->value = val;
    newNode->nextPtr = nullptr;

    if (head == nullptr)
        head = tail = newNode;


    else
    {
        tail->nextPtr = newNode;
        tail = tail->nextPtr;
    }
    tail->nextPtr = nullptr;

}

template <typename T>
void LinkedList<T>::push_front(const int& val)
{
    Node<T>* front = head;
    Node<T>* newNode = new Node<T>;
    newNode->value = val;

    if (head == nullptr)
        head = tail = newNode;
    else
    {
        newNode->nextPtr = front;
        head = newNode;
    }

}

template <typename T>
void LinkedList<T>::printList()
{
    Node<T>* current = head;

    std::cout << "\n";

    while (current != nullptr)
    {
        std::cout << current->value << " ";
        current = current->nextPtr;
    }

    std::cout << "\n";
}

template <typename T>
Node<T>* LinkedList<T>::makeNewNode(const T& val)
{
    Node* new_node = new Node;
    new_node->value = val;
    return new_node;
}

template <typename T>
int LinkedList<T>::countNode()
{
    int count = 0;
    while (head != nullptr)
    {
        ++count;
        head = head->nextPtr;
    }
    return count;
}

template <typename T>
bool LinkedList<T>::isEmpty()
{
    if (head == nullptr)
        return true;
    return false;
}

template <typename T>
Node<T>* LinkedList<T>::getNode(const T& val)
{
    Node<T>* current = head;
    while (current != nullptr)
    {
        if (current->value == val)
            return current;

        current = current->nextPtr;
    }
    return nullptr;
}

template <typename T>
void LinkedList<T>::insertFront(Node<T>* p, Node<T>* q)
{
    Node<T>* current = head;
    while (current->nextPtr != q)
    {
        if (current->nextPtr == nullptr)
            return;
        current = current->nextPtr;

    }

    Node<T>* tmp = current->nextPtr;
    current->nextPtr = p;
    current->nextPtr->nextPtr = tmp;
}

template <typename T>
void LinkedList<T>::insertBack(Node<T>* p, Node<T>* q)
{
    Node<T>* current = head;
    while (current->nextPtr != q)
    {
        current = current->nextPtr;
        if (current->nextPtr == nullptr)
        {
            std::cout << "Can't find Node q in LinkedList.\n";
            return;
        }
    }
    Node<T>* tmp = current->nextPtr;
    current->nextPtr = p;
    p->nextPtr = tmp;

}

template <typename T>
void LinkedList<T>::pop()
{
    head = head->nextPtr;
}

template <typename T>
T LinkedList<T>::getSmallestNum()
{
    Node<T>* current = head;
    T smallest = current->value;
    while (current != nullptr)
    {
        smallest = std::min(smallest, current->value);
        current = current->nextPtr;
    }
    return smallest;
}

template <typename T>
T LinkedList<T>::getBiggestNum()
{
    Node<T>* current = head;
    T biggest = current->value;
    while (current != nullptr)
    {
        biggest = std::max(biggest, current->value);
        current = current->nextPtr;
    }
    return biggest;
}

template <typename T>
void LinkedList<T>::sort()
{
    //insertion sort
    Node<T>* current = head;
    while (current)
    {
        Node<T>* min = current;
        Node<T>* nxt = current->nextPtr;
        while (nxt)
        {
            if (min->value > nxt->value)
                swap(min->value, nxt->value);

            nxt = nxt->nextPtr;
        }
        current = current->nextPtr;
    }

}

template <typename T>
void LinkedList<T>::sortDescending()
{
    Node<T>* current = head;
    while (current)
    {
        Node<T>* max = current;
        Node<T>* next = current->nextPtr;
        while (next)
        {
            if (max->value < next->value)
                swap(max->value, next->value);

            next = next->nextPtr;
        }
        current = current->nextPtr;
    }
}

template <typename T>
void swap(T& a, T& b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
void LinkedList<T>::append(const LinkedList<T>& l2)
{
    Node<T>* currentL2 = l2.getHead();

    while (currentL2 != nullptr)
    {
        this->push_back(currentL2->value);
        currentL2 = currentL2->nextPtr;
    }

}
