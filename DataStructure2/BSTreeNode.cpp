#include "BSTreeNode.h"

BSTreeNode::BSTreeNode() 
{
}

BSTreeNode::BSTreeNode(Pair item, BSTreeNode* left, BSTreeNode* right) : value(item), left(left), right(right)
{
}

BSTreeNode::~BSTreeNode()
{
}

