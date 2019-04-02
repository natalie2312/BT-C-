namespace ariel{
#include "BinaryTreeNode.hpp"


class Tree{
public:

	BinaryTreeNode* _root;

    Tree();
    ~Tree();

    Tree& insert(int i);
    void remove(int i);
    int size();
    bool contains(int i);
    int root();
    int parent(int i);
    int left(int i);
    int right(int i);
    void print();
    BinaryTreeNode* findMin(BinaryTreeNode* N);

private:
    void insert(int i, BinaryTreeNode* t);
    BinaryTreeNode* contains(int data, BinaryTreeNode* t);
    void remove(int data, BinaryTreeNode* t);
    int root(BinaryTreeNode* t);
	int parent(int i, BinaryTreeNode* t);
	int left(int i, BinaryTreeNode* t);
	int right(int i, BinaryTreeNode* t);
	void print(BinaryTreeNode* t);


	BinaryTreeNode* _root;
	int _size;

};

}
