
#include "Tree.hpp"
#include <iostream>
#include <stdexcept>

using std::cout;
using std::endl;
using namespace std;
using namespace ariel;

Node::Node(int data){ //constructor for Node.
  _data = data;
  left = NULL;
  right = NULL;
  parent = NULL;
}

int Node::getData(){ //getter for data.
  return _data;
}

Node* Node::getLeft(){ //getter for left child.
  return left;
}

Node* Node::getRight(){ //getter for right child.
  return right;
}

Node* Node::getParent(){ //getter for parent
  return parent;
}

void Node::setData(int data){
  _data = data;
}

void Node::setLeft(Node* l){
  left = l;
}

void Node::setRight(Node* r){
  right = r;
}

void Node::setParent(Node* p){
  parent = p;
}

Tree::Tree(){
  _root = NULL;
  _size = 0;
}

Tree::~Tree(){
  if(_root == NULL)
		return;		// Nothing to do
  Destroy(_root);
}

void Tree::Destroy(Node* x)
{
  Destroy(x->getLeft());
  Destroy(x->getRight());
  delete x;	
}

void Tree::print(){
    Node* x = _root;
    Tree::print(x);
}

void Tree::print(Node* x){
    if(x != NULL)
	{
		print(x->getLeft());
		cout << "Node key: " << x->getData() << endl;
		print(x->getRight());
	}
}

int Tree::size(){
     return _size;
}

Tree& Tree::insert(int i){
    if(contains(i)){
       throw runtime_error("already inside tree");
    }
    else{
        if(_size==0)
          _root= new Node(i);
        else{
            Node* n= new Node(i);
            insert(i, n);

          }
       _size++;
     // std::cout << _root->getData() << '\n';
   }
   return *this;
}

void Tree::insert(int i, Node* n){
    Node* y = NULL;
	Node* x = _root;
	
	while(x != NULL)
	{
		y = x;
		if(n->getData() < x->getData())
			x = x->getLeft();
		else
			x = x->getRight();
	}
	n->setParent(y);
	
    if (n->getData() < y->getData()){
		y->setLeft(n);
	} 
    else{
		y->setRight(n);
	}
}

bool Tree::contains(int i){
  try{ //tries to find i inside binary tree.
    Node* isIn = find(i);
  }
  catch(exception& e){ //exception indicates failure to find i.
    return false;
  }
  return true;
}


int Tree::root(){
    return _root->getData();
}

int Tree::left(int i){
    Node *x = find(i);
     if(x->getLeft()==NULL)
        throw invalid_argument("There is no left child for requested node.");
    return x->getLeft()->getData();
}

int Tree::right(int i){
    Node *x = find(i);
    if(x->getRight()==NULL)
        throw invalid_argument("There is no Right child for requested node.");
    return x->getRight()->getData();
}

int Tree::parent(int i){
    Node *x = find(i);
    if(size()==0 || !contains(i) || root() == i){
    throw invalid_argument("has no parent or does not contain specified node.");
   }
    return x->getParent()->getData();
}

void Tree::remove(int i){

     if(!contains(i)){
    throw runtime_error("You tried to remove non-existent node from the tree.");
  }
  if(_size==1){
    _size--;
    delete _root;
    return;
  } 
    Node* toRemove = find(i);
    if(i != root()){
      Node* parentOf = find(parent(i));
      bool toRemoveIsRightChild = toRemove->getData() > parentOf->getData();
      if(toRemove->getLeft() == NULL && toRemove->getRight() == NULL){
        //no childs. just deletes the node.
        if(toRemoveIsRightChild){
          parentOf->setRight(NULL);
        }
        else{
          parentOf->setLeft(NULL);
        }
        delete toRemove;
        _size--;
      }
      else if(toRemove->getRight() != NULL && toRemove ->getLeft()==NULL){
        //toRemove has only right child. 
        if(toRemoveIsRightChild){
          parentOf->setRight(toRemove->getRight());
        }
        else{ //toRemove is actually a left child.
          parentOf->setLeft(toRemove->getRight());
        }
        delete toRemove;
        _size--;
        return;
      
      } else if(toRemove ->getRight() == NULL && toRemove->getLeft()!=NULL){
        //toRemove has only left child.
        if(toRemoveIsRightChild){
          parentOf->setRight(toRemove->getLeft());
        }
        else{ //toRemove is actually a left child.
          parentOf->setLeft(toRemove->getLeft());
        }
        delete toRemove;
        _size--;
        return;
      } else{
        /*toRemove has 2 childs.
        if toRemove is a right child,
        will take the whole "left tree" of toRemove (left child)and add it to 
        the left-most child of the "right tree"(right child) of toRemove.
        */
        if(toRemoveIsRightChild){
          Node* concat = toRemove->getRight(); //guaranteed to have right child.
          while(concat->getLeft() != NULL){ 
            concat = concat->getLeft();
          }
          concat->setLeft(toRemove->getLeft());
          parentOf->setRight(toRemove->getRight());
          delete toRemove;
          _size--;
          return;
        } else{
          //to remove is left child. same logic, different side trees.
          Node* concat = toRemove->getLeft(); //guaranteed to have left child.
          while(concat->getRight() != NULL){
            concat = concat -> getRight();
          }
          concat->setRight(toRemove->getRight()); 
          parentOf->setLeft(toRemove->getLeft());
          delete toRemove;
          _size--;
          return;
        }
      }
    }
    else{//i is the root. removing root. no childs for root has already been handled (size=1).
      if(toRemove->getLeft() != NULL && toRemove->getRight() == NULL){
        //only left child.
        _root = toRemove->getLeft();
        delete toRemove;
        _size--;
      }
      else if(toRemove->getLeft() == NULL && toRemove->getRight() != NULL){
        //only right child.
        _root = toRemove->getRight();
        delete toRemove;
        _size--;
      }
      else{ //has 2 childs.
        Node* concat = toRemove->getRight();
        while(concat->getLeft() != NULL){
          concat = concat->getLeft();
        }
        concat->setLeft(toRemove->getLeft());
        _root = toRemove->getRight();
        delete toRemove;
        _size--;
      }
    }
//   if(!contains(i)){
//     throw runtime_error("You tried to remove non-existent node from the tree.");
//   }
//   if(_size==1){
//     _size--;
//     delete _root;
//     return;
//   } 
//      Node *N = find(i);

//     //    Node* N = _root;
//      //   while(N != NULL){

//         //    if(N->getData() == i){

//                 if (N->getLeft() == NULL && N->getRight()== NULL){ //no chlidren case
//                     N = NULL;                
//                 }
//                 else if(N->getLeft() == NULL){ //right child case
//                     N = N->getRight();
//                 }
//                 else if(N->getRight() == NULL){ //left child case
//                     N = N->getLeft();
//                 }
//                 else{  //both child case
//                     Node *temp = findMin(N->getRight());
//                     N->setData(temp->getData());
//                     delete temp;
//                     //remove(temp->getData());
//                 }
//         //    }
// 		    // else {
//             //     if (i < N->getData())
// 			//         N = N->getLeft();
// 		    //     else
// 			//         N = N->getRight();
//             // }
//      //   }
//      _size--;
    
}

Node *Tree::findMin (Node* N){
      while (N->getLeft() != NULL) 
            N = N->getLeft();
      return N;
}

Node* Tree::find(int i){
     if(size() == 0 ){
    throw invalid_argument("Cannot find in an empty tree");
  }
    Node* x = _root;
	while(x != NULL){
        if(x->getData() == i)
         return x;
		else if (i < x->getData())
			x = x->getLeft();
		else
			x = x->getRight();
	}
  throw runtime_error("Cannot find requested node."); //traverse through tree, did not find i.
}

