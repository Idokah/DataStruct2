#include "MinHeap.h"

MinHeap::MinHeap(int max) : heapSize(0), allocated(1), maxSize(max), data(new Pair[max]) {}

MinHeap::MinHeap(Pair A[], int n) : heapSize(n), maxSize(n), allocated(0), data(A) {
    for (int i = n / 2 - 1; i >= 0; i--)
        this->fixHeap(i);
}

MinHeap::~MinHeap() {
    if (allocated) delete[] this->data;
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

int MinHeap::fixHeap(int node) {
    int max;
    int left = this->left(node);
    int right = this->right(node);
    if ((left < heapSize) && (this->data[left].frequency > data[node].frequency))
        max = left;
    else max = node;
    if ((right < heapSize) && (this->data[right].frequency > data[max].frequency))
        max = right;
    if (max != node){
        this->swap(node, max);
        this->fixHeap(max);
    }
}

void MinHeap::swap(int node1, int node2) {
    Pair temp = this->data[node2];
    this->data[node2] =  this->data[node1];
    this->data[node1] = temp;
}

Pair MinHeap::deleteMin() {
    if (heapSize < 1)
        throw "error";
    Pair min = data[0];
    heapSize--;
    data[0] = data[heapSize];
    this->fixHeap(0);
    return min;
}

Pair MinHeap::min() {
    return Pair();
}

void MinHeap::insert(Pair item) {
    if (heapSize = maxSize)
        throw "error";
    int i = this->heapSize;
    this->heapSize++;
    while ((i > 0) && (this->data[parent(i)].frequency > item.frequency)) {
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

