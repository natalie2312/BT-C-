
#include "Tree.hpp"
#include <iostream>
#include <stdexcept>
#include "BinaryTreeNode.h"

// using namespace std;
using namespace ariel;

Tree::Tree(){
  _root = NULL;
  _size = 0;
}

Tree::~Tree(){
  _root = NULL;
}

void Tree::print(){
    
}

void Tree::print(BinaryTreeNode* t){

}

int Tree::size(){
    return 0;
}

Tree& Tree::insert(int i){
    BinaryTreeNode* node = new BinaryTreeNode(i);
    Tree::insert(i, node);
    return *this;
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
    return 0;
}

int Tree::right(int i){
    return 0;
}

int Tree::parent(int i){
    return 0;
}

void Tree::remove(int i){
    if(!Tree::contains(i)){
        // לזרוק שגיאה
    }
    else{
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
                    BinaryTreeNode *temp = findMin(N->rightNode);
                    N->nodeKey = temp->nodeKey;
                    N = N->rightNode;
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

BinaryTreeNode* Tree::findMin (BinaryTreeNode* N)
{
      while (N->leftNode != NULL) 
            N = N->leftNode;
      return N;
}

