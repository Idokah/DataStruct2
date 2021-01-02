#include <iostream>
#include <fstream>
#include "BTree.h"
#include "BSTree.h"
#include "MinHeap.h"

using namespace std;
const int MAX = 255;

BSTree* readFromFile(string fileName);
BTree* buildHoffmanTree(BSTree* bsTree, int n);

int main() {
    string fileName;

    cout << "Please enter file name: ";
    //cin >> fileName;
    BSTree* bsTree = readFromFile("input1.txt");
    bsTree->printInOrder();
    BTree* hoffmanTree = buildHoffmanTree(bsTree, MAX);
    //delete bsTree;
    delete hoffmanTree;
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
    MinHeap Q(bsTree, n);
    int size = Q.getHeapSize();
    TreeNode* node;
    for (int i = 0; i < size - 1; i++)
    {
        node = new TreeNode();
        node->setLeft(Q.deleteMin());
        node->setRight(Q.deleteMin());
        node->setFreq(node->getLeft()->getFreq()+ node->getRight()->getFreq());
        Q.insert(node);
    }
    return new BTree(Q.deleteMin());
}
