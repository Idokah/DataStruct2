#pragma once
#include <iostream>
#include "TreeNode.h"

using namespace std;
class BSTree 
{
private:
	TreeNode* root;
public:
	BSTree();
	~BSTree();
	TreeNode* find(int key);
	void insert(Pair item);
	void deleteNode(int key);
	
	
};