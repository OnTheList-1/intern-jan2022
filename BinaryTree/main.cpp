#include <iostream>

#include "BinaryTree.h"


int main()
{
    BinaryTree BST(20);
    for (int i = 0; i < 20; ++i)
    {
        BST.insert(BST.getRoot(), rand() % 30);
    }

    BST.printInorder(BST.getRoot());
    std::cout << "\n";
    BST.printPostorder(BST.getRoot());
    std::cout << "\n";
    BST.printPreorder(BST.getRoot());
    std::cout << "\n";
    BST.deleteNode(BST.getRoot(), 1);
    std::cout << "\n" << BST.getMax(BST.getRoot()) << "\n";
    BST.printKDistantFromRoot(BST.getRoot(), 1);
    std::cout << "\n";
    BST.printEveryKLevel(BST.getRoot());
    std::cout << "\n";
    BST.deleteNode(BST.getRoot(), 5);
    BST.printInorder(BST.getRoot());

    std::cout << "\n" << BST.countNodes(BST.getRoot()) << "\n";
    std::cout << "\n" << "Sum Nodes: " << BST.sumNodes(BST.getRoot()) << "\n";
    std::cout << "\n" << "Sum Leaf: " << BST.sumLeaf(BST.getRoot()) << "\n";
    std::cout << "\n" << "Biggest Node val diff: " << BST.biggestNodeValueDifference(BST.getRoot()) << "\n";
    return 0;
}