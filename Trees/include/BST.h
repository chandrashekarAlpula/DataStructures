/*
 * BST.h
 *
 *  Created on: Nov 5, 2016
 *      Author: chandra.shekhar
 */

#ifndef DS_BST_INCLUDE_BST_H_
#define DS_BST_INCLUDE_BST_H_

#include<iostream>
#include<stdio.h>

using namespace std;
class BSTNode{

public:
	BSTNode *left;
	BSTNode *right;
	int data;

	BSTNode(){
		left = NULL;
		right = NULL;
		data = 0;
	}
	BSTNode(int value){
		data = value;
		left = NULL;
		right = NULL;
	}
	BSTNode *GetLeft(){
		return left;
	}
	void SetLeft(BSTNode *ptr){
		left = ptr;
	}
	BSTNode *GetRight(){
		return right;
	}
	void SetRight(BSTNode *rt){
		right = rt;
	}
	int GetData(){
		return data;
	}
	void SetData(int val){
		data = val;
	}
};

class BST{

public:
	BSTNode *mRoot;

public:
	BST(){
		mRoot = NULL;
	}
	BST(int value){
		if(mRoot == NULL)
			mRoot = new BSTNode(value);
	}
	BSTNode *GetRoot(){
		return mRoot;
	}
	void InsertNode(int val);
	BSTNode *DeleteNode(BSTNode *root, int value);
	BSTNode *GetInorderSucc(BSTNode *currentNode);
	void PrintElements(BSTNode *root);
	void PrintLevelOrder(BSTNode *root);
	void InOrderTraversal(BSTNode *root);
	void PreOrderTraversal(BSTNode *root);
	void PostOrderTraversal(BSTNode *root);
	unsigned int HeightOfTree(BSTNode *root);
};


#endif /* DS_BST_INCLUDE_BST_H_ */
