namespace ariel{
#include "BinaryTreeNode.hpp"


class Tree{
public:

	BinaryTreeNode* _root;

    Tree();
    ~Tree();

    void insert(int i);
    void remove(int i);
    int size();
    bool contains(int i);
    int root();
    int parent(int i);
    int left(int i);
    int right(int i);
    void print();
    BinaryTreeNode* findMin(BinaryTreeNode* N);
    BinaryTreeNode* find(int i);

private:
    void insert(int i, BinaryTreeNode* node);
    void inorderTreeWalk(BinaryTreeNode* x);
    void removeSubtree(BinaryTreeNode* x);

	int _size;

};

}
