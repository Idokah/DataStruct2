#pragma once
struct Pair {
	int frequency;
	int key;
};

class BSTreeNode
{
private:
public:
	Pair value;
	BSTreeNode* left, * right;
	BSTreeNode();
	BSTreeNode(Pair item, BSTreeNode* left, BSTreeNode* right);
	~BSTreeNode();
	Pair* Find(int key);
	void Insert(Pair Item);
	void inceaseFrequency(Pair Item);

};