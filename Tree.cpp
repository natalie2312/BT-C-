
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

Node* Tree::getRoot(){ //getter for parent
  return _root;
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
  _root= deleteNode(getRoot(), i);
  _size--;
}


/* Given a binary search tree and a key, this function deletes the key 
   and returns the new root */
Node* Tree::deleteNode(Node* root, int key) 
{ 
    // base case 
    if (root == NULL) return root; 
  
    // If the key to be deleted is smaller than the root's key, 
    // then it lies in left subtree 
    if (key < root->getData()) 
        root->setLeft(deleteNode(root->getLeft(), key)); 
  
    // If the key to be deleted is greater than the root's key, 
    // then it lies in right subtree 
    else if (key > root->getData()) 
        root->setRight(deleteNode(root->getRight(), key)); 
  
    // if key is same as root's key, then This is the node 
    // to be deleted 
    else
    { 
        // node with only one child or no child 
        if (root->getLeft() == NULL) 
        { 
            Node *temp = root->getRight(); 
            free(root); 
            return temp; 
        } 
        else if (root->getRight() == NULL) 
        { 
            Node *temp = root->getLeft(); 
            free(root); 
            return temp; 
        } 
  
        // node with two children: Get the inorder successor (smallest 
        // in the right subtree) 
        Node* temp = findMin(root->getRight()); 
  
        // Copy the inorder successor's content to this node 
        root->setData(temp->getData()); 
  
        // Delete the inorder successor 
        root->setRight(deleteNode(root->getRight(), temp->getData())); 
    } 
    return root; 
} 


//void Tree::remove(int i){


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
    
//}

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

