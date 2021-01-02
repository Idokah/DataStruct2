#ifndef EX2_MINHEAP_H
#define EX2_MINHEAP_H
#include "Pair.h"

class MinHeap {
    private:
        Pair* data;
        int maxSize;
        int heapSize;
        int allocated;
        int left(int node);
        int right(int node);
        int parent(int node);
        void fixHeap(int node);
        void swap(int node1, int node2);

    public:
        MinHeap(int max);
        MinHeap(BSTree* tree, int n);
        Pair* buidArrFromTree(BSTree* tree);
        Pair* buidArrFromTreeRec(TreeNode* root, Pair*& arr);
        MinHeap(Pair A[], int n);
        ~MinHeap();
        Pair min();
        Pair deleteMin();
        void insert(Pair item);
        bool isEmpty();
        void makeEmpty();

};

#endif
