#include "TreeNode.h"

TreeNode::TreeNode() : left(nullptr), right(nullptr)
{
}

TreeNode::TreeNode(Pair item, TreeNode* left, TreeNode* right) : value(item), left(left), right(right)
{
}

TreeNode::~TreeNode()
{
	if (this->left != nullptr)
		delete this->left;
	if (this->right != nullptr)
		delete this->right;
}

