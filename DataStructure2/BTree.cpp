#include "BTree.h"
//לגבי עץ בינארי יש לממש את מה שנחוץ לכם, ולגבי ערימה את כל הפעולות הבסיסיות שתוארו במקראה ובשיעור (מקסימום, הורדת מקסימום, הכנסה, והאלגוריתם של פלויד).

BTree::BTree() :root(nullptr)
{
}

BTree::~BTree()
{
	if (root != nullptr)
		delete root;
}
