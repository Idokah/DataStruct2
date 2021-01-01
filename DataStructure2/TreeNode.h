#pragma once
struct Pair {
	int frequency;
	int key;
};

class TreeNode
{
private:
	Pair value;
	TreeNode* left, * right;
public:

	TreeNode();
	TreeNode(Pair item, TreeNode* left, TreeNode* right);
	~TreeNode();
	
	friend class BSTree;
	friend class BTree;
};