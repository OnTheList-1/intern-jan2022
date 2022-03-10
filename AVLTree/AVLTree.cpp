#include "AVLTree.h"
#include "TreeNode.h"
#include "Functions.h"

AVLTree::AVLTree()
{
	root = NULL;
}

void AVLTree::Insert(const int& x)
{
	root = insert(root, x);
}

void AVLTree::Remove(const int& x)
{
	root = remove(x, root);
}

bool AVLTree::Find(const int& x)
{
	return find(root, x);
}

void AVLTree::Clear()
{
	clear(root);
}

void AVLTree::PrintInorder()
{
	if (!root)
	{
		std::cout << "Tree doesn't exist.\n";
		return;
	}
	inorder(root);
	std::cout << "\n";
}

void AVLTree::PrintPostorder()
{
	if (!root)
	{
		std::cout << "Tree doesn't exist.\n";
		return;
	}
	postorder(root);
	std::cout << "\n";
}

void AVLTree::PrintPreorder()
{
	if (!root)
	{
		std::cout << "Tree doesn't exist.\n";
		return;
	}
	preorder(root);
	std::cout << "\n";
}

void AVLTree::VisualizeTree()
{
	if (!root)
	{
		std::cout << "Tree doesn't exist.\n";
		return;
	}
	visualizeTree(root);
}