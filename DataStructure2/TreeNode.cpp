#include "TreeNode.h"

TreeNode::TreeNode() : left(nullptr), right(nullptr), value({-1,-1})
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

void TreeNode::setRight(TreeNode* node)
{
	this->right = node;
}

void TreeNode::setLeft(TreeNode* node)
{
	this->left = node;
}

void TreeNode::setFreq(int freq)
{
	this->value.frequency = freq;
}

TreeNode* TreeNode::getRight()
{
	return this->right;
}

TreeNode* TreeNode::getLeft()
{
	return this->left;
}

int TreeNode::getFreq()
{
	return this->value.frequency;
}

Pair TreeNode::getValue()
{
	return this->value;
}

