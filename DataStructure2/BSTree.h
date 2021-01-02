#pragma once
#include <iostream>
#include "TreeNode.h"

using namespace std;
class BSTree 
{
private:
	TreeNode* root;
	void printInOrder(TreeNode* root);	
public:
	BSTree();
	~BSTree();
	TreeNode* find(int key);
	void insert(Pair item);
	void deleteNode(int key);
	void increaseCount(int key);
	void printInOrder();
	TreeNode* getRoot();
};