#include "MinHeap.h"
#include "BSTree.h"

MinHeap::MinHeap(int max) : heapSize(0), allocated(1), maxSize(max), data(new TreeNode*[max]) {}

MinHeap::MinHeap(BSTree* tree, int max) : allocated(1){

    int size;
    TreeNode** arr = buidArrFromTree(tree, max, size);
    this->heapSize = size;
    this->maxSize = size;
    *this = MinHeap(arr, size);
}

TreeNode** MinHeap::buidArrFromTree(BSTree* tree, int max, int& size)
{
    TreeNode** arr = new TreeNode*[maxSize];
    size = buidArrFromTreeRec(tree->getRoot(), arr);
    return arr;
}

int MinHeap::buidArrFromTreeRec(TreeNode* root, TreeNode** arr)
{
    static int index = 0;
    if (root == nullptr) return 0;
    buidArrFromTreeRec(root->getLeft(), arr);
    buidArrFromTreeRec(root->getRight(), arr);
    arr[index] = root;
    arr[index]->setLeft(nullptr);
    arr[index]->setRight(nullptr);
    index++;
    return index;
}

MinHeap::MinHeap(TreeNode** arr, int n) : heapSize(n), maxSize(n), allocated(0), data(arr) {
    for (int i = n / 2 - 1; i >= 0; i--)
        this->fixHeap(i);
}

MinHeap::~MinHeap() {
    if (allocated) delete[] this->data;
   // else delete this->data;
    this->data = nullptr;
}

int MinHeap::left(int node) {
    return (2*node+1);
}

int MinHeap::right(int node) {
    return (2*node+2);
}

int MinHeap::parent(int node) {
    return (node-1)/2;
}

int MinHeap::getHeapSize() {
    return this->heapSize;
}

void MinHeap::fixHeap(int node) {
    int min;
    int left = this->left(node);
    int right = this->right(node);
    if ((left < heapSize) && (this->data[left]->getFreq() < data[node]->getFreq()))
        min = left;
    else min = node;
    if ((right < heapSize) && (this->data[right]->getFreq() < data[min]->getFreq()))
        min = right;
    if (min != node){
        this->swap(node, min);
        this->fixHeap(min);
    }
}

void MinHeap::swap(int node1, int node2) {
    TreeNode* temp = this->data[node2];
    this->data[node2] =  this->data[node1];
    this->data[node1] = temp;
}

TreeNode* MinHeap::deleteMin() {
    if (heapSize < 1) {
        cout << "there is no node to delete";
        exit(1);
    }
    TreeNode* min = data[0];
    heapSize--;
    data[0] = data[heapSize];
    this->fixHeap(0);
    return min;
}

TreeNode* MinHeap::min() {
    return this->data[0];
}

void MinHeap::insert(TreeNode* item) {
    if (heapSize + 1 == maxSize) {
        cout << "error";
        exit(1);
    }
    int i = this->heapSize;
    this->heapSize++;
    while ((i > 0) && (this->data[parent(i)]->getFreq() > item->getFreq())) {
        this->data[i] = this->data[parent(i)];
        i = parent(i);
    }
    data[i] = item;
}

bool MinHeap::isEmpty()
{
    return (this->heapSize == 0);
}

void MinHeap::makeEmpty() {
    this->heapSize = 0;
}

