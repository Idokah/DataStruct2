#pragma once
#include "Pair.h"
class TreeNode
{
private:
	Pair value;
	TreeNode* left, * right;
public:

	TreeNode();
	TreeNode(Pair item, TreeNode* left, TreeNode* right);
	~TreeNode();
	void setRight(TreeNode* node);
	void setLeft(TreeNode* node);
	void setFreq(int freq);
	TreeNode* getRight();
	TreeNode* getLeft();
	int getFreq();
	Pair getValue();
	friend class BSTree;
	friend class BTree;
};