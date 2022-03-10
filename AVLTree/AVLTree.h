#pragma once

#include "TreeNode.h"
#include <iostream>

class AVLTree
{
public:
	AVLTree();

	void Insert(const int& x);
	void Remove(const int& x);
	bool Find(const int& x);
	void Clear();

	void PrintInorder();
	void PrintPostorder();
	void PrintPreorder();

	void VisualizeTree();

private:
	TreeNode* root;
};
