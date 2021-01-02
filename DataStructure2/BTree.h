#pragma once
#include <iostream>
#include <fstream>
#include "TreeNode.h"

class BTree
{
private:
	TreeNode* root;
	void printEncodingTable(TreeNode* curr, string code, int& weight);
public:
	BTree(TreeNode* root);
	~BTree();
	void printEncodingTable();
};