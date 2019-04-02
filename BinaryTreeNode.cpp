#include "BinaryTreeNode.h"

BinaryTreeNode::BinaryTreeNode()
{
	parentNode = NULL;
	rightNode = NULL;
	leftNode = NULL;
	nodeKey = -9999999999;
}

BinaryTreeNode::BinaryTreeNode(int key)
{
	parentNode = NULL;
	rightNode = NULL;
	leftNode = NULL;
	nodeKey = key;
}

BinaryTreeNode::~BinaryTreeNode()
{
	
}