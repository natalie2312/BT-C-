
#include "Tree.hpp"
#include <iostream>
#include <stdexcept>
#include "BinaryTreeNode.hpp"

using std::cout;
using std::endl;
using namespace std;
using namespace ariel;

Tree::Tree(){
  _root = NULL;
  _size = 0;
}

Tree::~Tree(){
  _root = NULL;
}

void Tree::print(){
    BinaryTreeNode* x = _root;
    Tree::inorderTreeWalk(x);
}

void Tree::inorderTreeWalk(BinaryTreeNode* x){
    if(x != NULL)
	{
		inorderTreeWalk(x->leftNode);
		cout << "Node key: " << x->nodeKey << endl;
		inorderTreeWalk(x->rightNode);
	}
}

int Tree::size(){
    return _size;;
}

void Tree::insert(int i){
    if(Tree::contains(i)){
        throw std::invalid_argument("Already Contains Element!");
    }
    else{
        _size++;
        BinaryTreeNode* node = NULL;
        node->nodeKey= i;
        Tree::insert(i, node);
    }
}

void Tree::insert(int i, BinaryTreeNode* node){
    BinaryTreeNode* y = NULL;
	BinaryTreeNode* x = _root;
	
	while(x != NULL)
	{
		y = x;
		if(node->nodeKey < x->nodeKey)
			x = x->leftNode;
		else
			x = x->rightNode;
	}
	node->parentNode = y;
	
	if(y == NULL)
	{
		_root = node; 	// tree was empty
	} else if (node->nodeKey < y->nodeKey)
	{
		y->leftNode = node;
	} else
	{
		y->rightNode = node;
	}

}

bool Tree::contains(int i){
    BinaryTreeNode* x = _root;
	
	while(x != NULL)
	{
        if(x->nodeKey == i)
         return true;
		if (i < x->nodeKey)
			x = x->leftNode;
		else
			x = x->rightNode;
	}
	return false;
}

int Tree::root(){
    return _root->nodeKey;
}

int Tree::left(int i){
     BinaryTreeNode *x = Tree::find(i);
    return x->leftNode->nodeKey;
}

int Tree::right(int i){
    BinaryTreeNode *x = Tree::find(i);
    return x->rightNode->nodeKey;
}

int Tree::parent(int i){
    BinaryTreeNode *x = Tree::find(i);
    return x->parentNode->nodeKey;
}

void Tree::remove(int i){
    if(!Tree::contains(i)){
        std::cout << "invalid input exeption" << '\n';
        return;
    }
    else{
        _size--;
        BinaryTreeNode* N = _root;
        while(N != NULL){

            if(N->nodeKey == i){

                if (N->leftNode == NULL && N->rightNode== NULL){ //no chlidren case
                    N = NULL;                
                }
                else if(N->leftNode == NULL){ //right child case
                    N = N->rightNode;
                }
                else if(N->rightNode == NULL){ //left child case
                    N = N->leftNode;
                }
                else{  //both child case
                    BinaryTreeNode *temp = Tree::findMin(N->rightNode);
                    N->nodeKey = temp->nodeKey;
                    remove(temp->nodeKey);
                }
            }
		    else {
                if (i < N->nodeKey)
			        N = N->leftNode;
		        else
			        N = N->rightNode;
            }
        }
    }
}

BinaryTreeNode* Tree::findMin (BinaryTreeNode* N){
      while (N->leftNode != NULL) 
            N = N->leftNode;
      return N;
}

BinaryTreeNode* Tree::find(int i){
    BinaryTreeNode* x = _root;
	while(x != NULL){
        if(x->nodeKey == i)
         return x;
		else if (i < x->nodeKey)
			x = x->leftNode;
		else
			x = x->rightNode;
	}
	return NULL;
}

