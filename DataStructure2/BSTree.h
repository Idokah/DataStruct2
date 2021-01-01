#pragma once
#include <iostream>
#include "BSTreeNode.h"
using namespace std;
class BSTree 
{
private:
	BSTreeNode* root;
public:
	BSTree();
	~BSTree();
	BSTreeNode* find(int key);
	void insert(Pair item);
	void deleteNode(int key);
	

};