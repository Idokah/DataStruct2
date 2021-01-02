#include "BTree.h"

BTree::BTree(TreeNode* root) : root(root)
{
}

BTree::~BTree()
{
	if (root != nullptr)
		delete root;
	
}
