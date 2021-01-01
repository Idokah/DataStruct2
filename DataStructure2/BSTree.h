#pragma once
struct Pair {
	int frequency;
	int ascii;
};

class BSTreeNode
{
private:
	Pair value;
	BSTreeNode* left, * right;
public:
	BSTreeNode();
	BSTreeNode(Pair item, BSTreeNode* left, BSTreeNode* right);
	~BSTreeNode();
	Pair* Find(int key);
	void Insert(Pair Item);
	void inceaseFrequency(Pair Item);

};