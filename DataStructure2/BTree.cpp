#include "BTree.h"

bool isLeaf(TreeNode* node);

BTree::BTree(TreeNode* root) : root(root)
{
}

BTree::~BTree()
{
	if (root != nullptr)
		delete root;
}

void BTree::printEncodingTable() {
	if (isLeaf(this->root)) {
		cout << (char)this->root->getValue().key << "- 1" << endl;
		cout << "weight: " << this->root->getValue().frequency << endl;
	}
	else {
		int weight = 0;
		printEncodingTable(this->root, "", weight);
		cout << "weight: " << weight << endl;
	}
}

void BTree::printEncodingTable(TreeNode* curr, string code, int& weight)
{
	if (isLeaf(curr))
	{
		cout << (char)curr->getValue().key << "- " << code << endl;
		weight += code.length() * curr->getValue().frequency;
		return;
	}
	printEncodingTable(curr->left, code + '0', weight);
	printEncodingTable(curr->right, code + '1', weight);
}

bool isLeaf(TreeNode* node) {
	return (node->getLeft() == nullptr && node->getRight() == nullptr);
}
