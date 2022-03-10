#include <iostream>

#include "AVLTree.h"

int main()
{
	AVLTree tree;
	tree.Insert(10);
	tree.Insert(20);
	tree.Insert(30);
	tree.Insert(40);
	tree.Insert(50);
	tree.Insert(25);
	tree.Insert(48);

	tree.VisualizeTree();

	return 0;
}