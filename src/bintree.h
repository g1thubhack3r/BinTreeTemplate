// Binary Tree Template Header

/*
 This header is under a GNU LGPLv2.1+ license.
*/

#ifdef __GNUC__
#pragma once
#endif

#ifndef _BINTREE
#define _BINTREE

#include <functional> 

// Node of a binary tree.
struct BinaryTreeNode
{
public:
	
	// member variable
	void *data;
	BinaryTreeNode *l, *r;
	
	// constructer & destructer
	BinaryTreeNode() : data(nullptr), l(nullptr), r(nullptr) {}
	BinaryTreeNode(void *ptr, BinaryTreeNode *lptr, BinaryTreeNode *rptr) : data(ptr), l(lptr), r(rptr) {}
	~BinaryTreeNode() {}
};

/*
 Preorder traverse a binary tree.
 First argument is a pointer to the root of the tree.
 Second argument is a function, its argument is a pointer to the current node.
*/
void preorder_traverse(BinaryTreeNode *root, const std::function<void(BinaryTreeNode*)> &func)
{
	if (root == nullptr) return;
	
	func(root);
	
	preorder_traverse(root->l, func);
	preorder_traverse(root->r, func);
}

/*
 Preorder traverse a binary tree.
 First argument is a pointer to the root of the tree.
 Second argument is a function, its argument is a pointer to the current node.
*/
void inorder_traverse(BinaryTreeNode *root, const std::function<void(BinaryTreeNode*)> &func)
{
	if (root == nullptr) return;
	
	preorder_traverse(root->l, func);
	
	func(root);
	
	preorder_traverse(root->r, func);
}

/*
 Preorder traverse a binary tree.
 First argument is a pointer to the root of the tree.
 Second argument is a function, its argument is a pointer to the current node.
*/
void postorder_traverse(BinaryTreeNode *root, const std::function<void(BinaryTreeNode*)> &func)
{
	if (root == nullptr) return;
	
	postorder_traverse(root->l, func);
	postorder_traverse(root->r, func);
	
	func(root);
}

#endif
