#include <iostream>
#include <fstream>
#include "BTree.h"
#include "BSTree.h"
#include "MinHeap.h"

using namespace std;

BSTree* readFromFile(string fileName);

int main() {
    string fileName;

    cout << "Please enter file name: ";
    //cin >> fileName;
    BSTree* bsTree = readFromFile("input1.txt");
    bsTree->printInOrder();
    BTree* hoffmanTree = buildHoffmanTree(bsTree);
    delete bsTree;
    return 0;
}

BSTree* readFromFile(string fileName)
{
    BSTree* bsTree = new BSTree();
    ifstream infile;
    char ascii;
    infile.open(fileName);
    if (!infile)
    {
        cout << "Error with infile" << endl;
        exit(1);
    }
    infile >> ascii;
    while (!infile.eof())
    {
        if (!infile.good())
        {
            cout << "Error reading" << endl;
            exit(1);
        }
        bsTree->increaseCount(ascii);
        infile >> ascii;
    }
    infile.close();
    return bsTree;
}

BTree* buildHoffmanTree(BSTree* bsTree, int n) 
{
    MinHeap Q(bsTree);
    TreeNode* node;
    Pair pair;
    for (int i = 0; i < n; i++)
    {
        node = new TreeNode();
        node->setLeft(new TreeNode(Q.deleteMin(), nullptr, nullptr));
        node->setRight(new TreeNode(Q.deleteMin(), nullptr, nullptr));
        node->setFreq(node->getLeft()->getFreq()+ node->getRight()->getFreq());
    }
}
