#include "BSTree.h"

BSTree::BSTree() :root(nullptr)
{
}

BSTree::~BSTree()
{
	if (root!=nullptr)
		delete root;
}

TreeNode* BSTree::find(int key)
{
	TreeNode* temp = root;
	while (temp != nullptr)
	{
		if (key == (temp->value).key)
			return temp;
		else if (key < (temp->value).key)
			temp = temp->left;
		else
			temp = temp->right;
	}
	return nullptr;
}

void BSTree::insert(Pair item)
{
	if (find(item.key) != nullptr)
	{
		cout << "Error";
		exit(1);
	}
	TreeNode* temp = this->root;
	TreeNode* parent = nullptr;
	TreeNode* newNode;
	while (temp != nullptr)
	{
		parent = temp;
		if (item.key < (temp->value).key)
			temp = temp->left;
		else 
			temp = temp->right;
	}
	newNode = new TreeNode(item, nullptr, nullptr);
	if (parent == nullptr)
		this->root = newNode;
	else if (item.key < (parent->value).key)
		parent->left = newNode;
	else
		parent->right = newNode;
}

void BSTree::deleteNode(int key)
{
	TreeNode* curr = root;
	TreeNode* prev = nullptr;
	//find to be deleted node, parent.
	while (curr != nullptr && (curr->value).key != key)
	{
		prev = curr;
		if (key < (curr->value).key)
			curr = curr->left;
		else
			curr = curr->right;
	}
	if (curr == nullptr)
	{
		cout << "Key not found" << endl;
		return;
	}
	//the node to be deleted have at most one child.
	if (curr->left == nullptr || curr->right == nullptr)
	{
		//newCurr will replace deleted node
		TreeNode* newCurr;
 
		if (curr->left == nullptr)
			newCurr = curr->right;
		else
			newCurr = curr->left;

		// check if the node to be deleted is the root
		if (prev == nullptr)
		{
			delete curr;
			this->root = newCurr;
			return;
		}

		if (curr == prev->left)
			prev->left = newCurr;
		else
			prev->right = newCurr;

		delete curr;
	}
	//the node to be deleted have two children.
	else
	{
		//find max in left child tree
		TreeNode* maxLeftParent = curr;
		TreeNode* maxLeft;
		maxLeft = curr->left;
		//find the max value from the left side and his parent.
		while (maxLeft->right != nullptr)
		{
			maxLeftParent = maxLeft;
			maxLeft = maxLeft->right;
		}

		//if the maxLeftParent is the to be delete node - we don't want to change
		//its right child
		if (maxLeftParent == curr)
		{
			maxLeftParent->left = maxLeft->left;
		}
		//maxLeftParent is not the to be delete node, maxRight has at most one child
		else
		{
			maxLeftParent->right = maxLeft->left;
		}
		curr->value = maxLeft->value;

		delete maxLeft;
	}
}
