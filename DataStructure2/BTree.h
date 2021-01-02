#pragma once
#include "TreeNode.h"

class BTree
{
private:
	TreeNode* root;
public:
	BTree(TreeNode* root);
	~BTree();
};