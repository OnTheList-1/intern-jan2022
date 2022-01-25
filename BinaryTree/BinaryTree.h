#pragma once
#include <queue>
#include <iostream>

class Node
{
public:
    Node();
    Node(const int&);
    Node* left;
    Node* right;
    int data;
};

Node::Node()
{
    data = 0;
    left = right = nullptr;
}

Node::Node(const int& val)
{
    data = val;
    left = right = nullptr;
}


class BinaryTree
{
public:
    //contructors & destructors
    BinaryTree();
    BinaryTree(const int&);
    ~BinaryTree();

    //setters & getters
    Node* getRoot() const;

    //helper
    void destroy_recursive(Node*);

    //insert and print
    //inorder/postorder/preorder traversal
    //inorder => left, root, right
    //preorder => root, left, right
    //postorder => left, right, root
    void insert(Node*, const int&);
    void printInorder(Node*);
    void printPostorder(Node*);
    void printPreorder(Node*);
    void printEvenNumber(Node*);
    void printKDistantFromRoot(Node*, const int&);
    void printEveryKLevel(Node*);
    void deleteNode(Node*, const int&); //needs check

    //bool
    bool isEmpty();
    bool isPerfect(Node*); //needs check

    //misc
    int getMax(Node*);
    int getMin(Node*);
    Node* findMin(Node*);
    int countNodes(Node*);
    int sumNodes(Node*);
    int sumLeaf(Node*);
    int biggestNodeValueDifference(Node*);

private:
    Node* root;
};

BinaryTree::BinaryTree()
{
    root = new Node;
    root->data = 0;
    root->left = root->right = nullptr;
}

BinaryTree::BinaryTree(const int& val)
{
    root = new Node;
    root->data = val;
    root->left = root->right = nullptr;
}

BinaryTree::~BinaryTree()
{
    destroy_recursive(root);
}

void BinaryTree::destroy_recursive(Node* node)
{
    if (node)
    {
        destroy_recursive(node->left);
        destroy_recursive(node->right);
        delete node;
    }
}

Node* BinaryTree::getRoot() const
{
    return root;
}

void BinaryTree::insert(Node* node, const int& val)
{
    if (val < node->data)
    {
        if (node->left != nullptr)
            insert(node->left, val);
        else
        {
            node->left = new Node;
            node->left->data = val;
            node->left->left = node->left->right = nullptr;
        }
    }
    else if (val >= node->data)
    {
        if (node->right != nullptr)
            insert(node->right, val);

        else
        {
            node->right = new Node;
            node->right->data = val;
            node->right->left = node->right->right = nullptr;
        }
    }

}

void BinaryTree::printInorder(Node* node)
{
    if (node == nullptr)
        return;

    printInorder(node->left);
    std::cout << node->data << " ";
    printInorder(node->right);
}

void BinaryTree::printPostorder(Node* node)
{
    if (node == nullptr)
        return;

    printPostorder(node->left);
    printPostorder(node->right);
    std::cout << node->data << " ";
}

void BinaryTree::printPreorder(Node* node)
{
    if (node == nullptr)
        return;

    std::cout << node->data << " ";
    printPreorder(node->left);
    printPreorder(node->right);
}

void BinaryTree::printEvenNumber(Node* node)
{
    if (node == nullptr)
        return;

    if (node->data % 2 == 0)
        std::cout << node->data << " ";

    printEvenNumber(node->left);
    printEvenNumber(node->right);

}

void BinaryTree::printKDistantFromRoot(Node* node, const int& k)
{
    if (node == nullptr || k < 0)
        return;
    if (k == 0)
    {
        std::cout << node->data << " ";
        return;
    }
    printKDistantFromRoot(node->left, k - 1);
    printKDistantFromRoot(node->right, k - 1);
}

void BinaryTree::printEveryKLevel(Node* node)
{
    if (node == nullptr)
        return;

    int level = 0;

    typedef std::pair<Node*, int> node_level;
    std::queue<node_level> q;
    q.push(node_level(node, 1));

    while (!q.empty())
    {
        node_level nl = q.front();
        q.pop();
        if (nullptr != (node = nl.first))
        {
            if (level != nl.second)
            {
                std::cout << "Level " << nl.second << ": ";
                level = nl.second;
            }
            std::cout << node->data << " ";
            q.push(node_level(node->left, level + 1));
            q.push(node_level(node->right, level + 1));
        }
    }
    std::cout << "\n";
}

void BinaryTree::deleteNode(Node* node, const int& value)
{
    if (node == nullptr)
        return;

    if (value < node->data)
        deleteNode(node->left, value);

    else if (value >= node->data)
        deleteNode(node->right, value);

    else
    {
        if (node->left == nullptr && node->right == nullptr)
            return;

        else if (node->left == nullptr)
        {
            Node* tmp = node->right;
            delete node;
            node = tmp;
        }

        else if (node->right == nullptr)
        {
            Node* tmp = node->left;
            delete node;
            node = tmp;
        }
        else
        {
            Node* tmp = findMin(node->right);
            node->data = tmp->data;
            deleteNode(node->right, tmp->data);
        }
    }
}

bool BinaryTree::isEmpty()
{
    if (root == nullptr)
        return true;
    return false;
}

int BinaryTree::getMax(Node* node)
{
    if (node == nullptr)
        return -1;

    int left = getMax(node->left);
    int right = getMax(node->right);
    if (node->data > left && node->data > right)
        return node->data;
    else
        return std::max(left, right);
}

int BinaryTree::getMin(Node* node)
{
    if (node == nullptr)
        return 0;

    int left = getMin(node->left);
    int right = getMin(node->right);
    if (node->data < left && node->data < right)
        return node->data;
    else
        return std::min(left, right);
}

Node* BinaryTree::findMin(Node* node)
{
    Node* tmp = node;
    while (tmp && tmp->left != nullptr)
        tmp = tmp->left;

    return tmp;
}

int BinaryTree::countNodes(Node* node)
{
    int count = 1;
    if (node == nullptr)
        return 0;

    else
    {
        count += countNodes(node->left);
        count += countNodes(node->right);
        return count;
    }

}

int BinaryTree::sumNodes(Node* node)
{
    int sum = 0;
    if (node == nullptr)
        return 0;

    sum += node->data;
    sum += sumNodes(node->left);
    sum += sumNodes(node->right);
    return sum;
}

int BinaryTree::sumLeaf(Node* node)
{
    int sum = 0;
    if (node == nullptr)
        return 0;

    if (node->left == nullptr && node->right == nullptr)
        return node->data;

    sum += sumLeaf(node->left);
    sum += sumLeaf(node->right);
}

bool BinaryTree::isPerfect(Node* node)
{
    if (node == nullptr)
        return true;

    if (node->left == nullptr && root->right == nullptr)
        return true;
    else
        return false;

    return isPerfect(node->left) && isPerfect(node->right);
}

int BinaryTree::biggestNodeValueDifference(Node* node)
{
    return getMax(node) - getMin(node);
}