#ifndef EX2_MINHEAP_H
#define EX2_MINHEAP_H
#include "Pair.h"
#include "BSTree.h"

class MinHeap {
    private:
        TreeNode** data;
        int maxSize;
        int heapSize;
        int allocated;
        int left(int node);
        int right(int node);
        int parent(int node);
        void fixHeap(int node);
        void swap(int node1, int node2);
        int buidArrFromTreeRec(TreeNode* root, TreeNode** arr);

    public:
        MinHeap(int max);
        MinHeap(BSTree* tree, int n);
        TreeNode** buidArrFromTree(BSTree* tree, int max, int& size);
        MinHeap(TreeNode** arr, int n);
        ~MinHeap();
        TreeNode* min();
        TreeNode* deleteMin();
        void insert(TreeNode* item);
        bool isEmpty();
        void makeEmpty();
        int getHeapSize();
};

#endif
